//  https://github.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/edit/master/src/os2.cpp
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// File Handlers
ifstream fin("input_phase2.txt");
ofstream fout("output_phase2.txt");

// Memory & Registers
char M[1200][4];
char buffer[40];
char IR[4];
char R[4];
int IC, C;
int SI, PI, TI;
int PTR;
bool breakFlag;

// PCB
struct PCB{
    int jobId, TTL, TTC, TLL, LLC;
    void setPCB(int jid,int ttl,int tll){jobId=jid;TTL=ttl;TLL=tll;TTC=0;LLC=0;}
} pcb;

// Error Messages
string error[7] = {
    "No Error","Out of Data","Line Limit Exceeded","Time Limit Exceeded",
    "Operation Code Error","Operand Error","Invalid Page Fault"
};

// ------------------- Functions -------------------
void init(){
    memset(M,'\0',1200); memset(IR,'\0',4); memset(R,'\0',5);
    C=SI=PI=TI=0; breakFlag=false;
}

void Terminate(int EM,int EM2=-1){
    fout<<endl<<endl;
    if(EM==0) fout<<"Terminated Normally. "<<error[EM]<<endl;
    else fout<<"Terminated abnormally due to "<<error[EM]<<
        (EM2!=-1 ? (". "+error[EM2]): "")<<endl;
}

void read(int RA){
    fin.getline(buffer,41);
    char temp[5]; memset(temp,'\0',5); memcpy(temp,buffer,4);
    if(!strcmp(temp,"$END")){Terminate(1); breakFlag=true;}
    else strcpy(M[RA],buffer);
}

void write(int RA){
    char str[40]; int k=0;
    for(int i=RA;i<RA+10;i++) for(int j=0;j<4;j++) str[k++]=M[i][j];
    fout<<str<<endl; pcb.LLC++;
}

int allocate(){ srand(time(0)); return rand()%30; }

int addressMap(int VA){
    if(0<=VA && VA<100){
        int pte=PTR+VA/10;
        if(M[pte][0]=='*'){ PI=3; return 0; }
        return atoi(M[pte])*10+VA%10;
    }
    PI=2; return 0;
}

int mos(int RA=0){
    if(SI!=0){ switch(SI){ case 1: read(RA); break; case 2: write(RA); break; case 3: Terminate(0); breakFlag=true; break;} SI=0; }
    return 0;
}

void execute_user_program(){
    char temp[3],loca[2]; int RA;
    while(!breakFlag){
        RA=addressMap(IC); memcpy(IR,M[RA],4); IC++;
        memset(temp,'\0',3); memcpy(temp,IR,2);
        loca[0]=IR[2]; loca[1]=IR[3]; int locIR=atoi(loca);
        RA=addressMap(locIR);

        if(!strcmp(temp,"LR")) memcpy(R,M[RA],4);
        else if(!strcmp(temp,"SR")) memcpy(M[RA],R,4);
        else if(!strcmp(temp,"CR")) C=(strcmp(R,M[RA])==0)?1:0;
        else if(!strcmp(temp,"BT")) if(C==1) IC=RA;
        else if(!strcmp(temp,"GD")){ SI=1; mos(RA); }
        else if(!strcmp(temp,"PD")){ SI=2; mos(RA); }
        else if(!strcmp(temp,"H")){ SI=3; mos(); break; }
    }
}

void start_execution(){ IC=0; execute_user_program(); }

void load(){
    int m,currPTR; char temp[5]; memset(buffer,'\0',40);
    while(!fin.eof()){
        fin.getline(buffer,41);
        memset(temp,'\0',5); memcpy(temp,buffer,4);
        if(!strcmp(temp,"$AMJ")){
            init();
            int jobId=atoi(string(buffer+4,4).c_str());
            int TTL=atoi(string(buffer+8,4).c_str());
            int TLL=atoi(string(buffer+12,4).c_str());
            pcb.setPCB(jobId,TTL,TLL);
            PTR=allocate()*10; memset(M[PTR],'*',40); currPTR=PTR;
        } else if(!strcmp(temp,"$DTA")) start_execution();
        else if(!strcmp(temp,"$END")) continue;
        else{
            do{ m=allocate(); }while(M[m*10][0]!='\0');
            sprintf(M[currPTR],"%d",m); currPTR++;
            strcpy(M[m*10],buffer);
        }
    }
}

// ------------------- Main -------------------
int main(){
    load(); 
    fin.close(); 
    fout.close(); 
    return 0; }
