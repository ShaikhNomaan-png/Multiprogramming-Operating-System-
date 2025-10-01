# 🖥️ Multiprogramming Operating System Simulator

Welcome to the **Multiprogramming OS Simulator**!  
This project is a hands-on technological journey into fundamental concepts of operating systems, featuring interactive CPU, memory, and process management simulations.  
Dive into the world of multiprogramming and discover how real operating systems manage resources, schedule processes, and handle interrupts—all in a safe, educational environment.

---

## 🏗️ System Architecture

![OS Simulator Architecture](https://raw.githubusercontent.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/main/assets/architecture-diagram.png)

The simulator is built on a modular architecture, mimicking the core components of a real OS:
- **CPU Module**: Emulates instruction execution and context switching.
- **Memory Module**: Simulates RAM, paging, and address translation.
- **Process Manager**: Maintains PCB data, manages process states and scheduling.
- **Interrupt Handler**: Coordinates supervisor calls, errors, and asynchronous events.

---

## 🚀 Tech Highlights

### **Phase 1:**  
- **CPU & Machine Simulation** ⚙️  
  - Simulates instruction cycles, registers, and basic I/O.  
  - Provides hooks for supervisor calls and privilege checks.
- **Supervisor Calls via Interrupts** 🚨  
  - Implements SVCs for process management, memory allocation, and I/O.

### **Phase 2:**  
- **Paging Implementation** 🗂️  
  - Virtual memory management using page tables.
  - Supports page faults and dynamic allocation.
- **Robust Error Handling** ❌  
  - Detects illegal memory access, invalid instructions, and resource exhaustion.
- **Interrupt Generation & Servicing** 🔄  
  - Hardware and software interrupts, nested interrupt support, priority handling.
- **Process Control Block (PCB) Structure** 📊  
  - Tracks process ID, state, registers, memory maps, and scheduling information.

### **Planned Extensions:**  
- **Multi-level Scheduling**  
- **Device Driver Simulation**  
- **File System Layer (future release)**  
- **User/Kernel Mode Switching**

---

## 🌐 Why Use This Simulator?

- **Learn OS Fundamentals:**  
  Grasp core concepts like multiprogramming, interrupt handling, memory management, and process control in a hands-on way.
- **Tech-Driven Design:**  
  Modern code structure, clear separation of responsibilities, and focus on real-world scenarios.
- **Interactive & Educational:**  
  Ideal for students, educators, and curious developers ready to dive into OS inner workings—without needing real hardware.
- **Trace & Debug:**  
  Step-by-step simulation with trace logs for every process, interrupt, and memory operation.
- **Extensible & Customizable:**  
  Easily add new instructions, memory models, or scheduling algorithms for experiments and assignments.

---

## 💡 Features

- Simulates multi-process CPU scheduling and execution (FCFS, Round Robin, Priority)
- Handles supervisor calls and interrupts dynamically (customizable interrupt vector table)
- Implements paging for efficient memory management (with page fault simulation and swapping)
- Manages process information via PCB data structures (full lifecycle: creation, ready, running, blocked, terminated)
- Integrates error detection and handling for robust simulation (invalid opcode, out-of-memory, deadlock detection)
- Visualizes process and memory state (optional: CLI or GUI output, configurable logging)
- Supports batch and interactive modes for running workloads

---

## 🖼️ Example: Process Lifecycle

![Process Lifecycle Diagram](https://raw.githubusercontent.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/main/assets/process-lifecycle.png)

*Above: Typical process states and transitions visualized in the simulator*

---

## 🔧 Getting Started

1. **Clone the repo:**  
   ```sh
   git clone https://github.com/ShaikhNomaan-png/Multiprogramming-Operating-System-.git
   ```
2. **Navigate to the src directory:**  
   ```sh
   cd Multiprogramming-Operating-System-/src
   ```
3. **Build and Run the simulation:**  
   - Using `make`:
     ```sh
     make
     ./simulator
     ```
   - Or using `gcc`:
     ```sh
     gcc -o simulator *.c
     ./simulator
     ```
   - For C++:
     ```sh
     g++ -o simulator *.cpp
     ./simulator
     ```
4. **Configure simulation parameters:**  
   Edit `config.ini` or pass command-line arguments for number of processes, memory size, scheduling algorithm, etc.

---

## 🗃️ Directory Structure

```
Multiprogramming-Operating-System-/
│
├── src/              # Core simulator code
│   ├── cpu.c         # CPU emulation
│   ├── memory.c      # Memory and paging logic
│   ├── pcb.c         # Process Control Block management
│   ├── interrupt.c   # Interrupt handling routines
│   └── ...
├── assets/           # Diagrams, images for documentation
├── tests/            # Test cases and process workloads
├── docs/             # Extra documentation
├── config.ini        # Default configuration
└── README.md         # This file
```

---

## 📚 Learn More

- **[Wiki](./wiki)** — In-depth documentation & tutorials (architecture breakdown, code walkthroughs, OS concepts)
- **[Issues](https://github.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/issues)** — Report bugs or suggest features
- **Sample Assignments:**  
  Try implementing new scheduling algorithms, add device handlers, simulate deadlocks and recovery!

---

## ⚡ Tech Stack

- C / C++ / Assembly (adapt as appropriate)
- Modular structure for extensibility
- Designed for clarity, accuracy, and learning
- Optional: Python for scripting workloads or visualization

---

## 🤝 Contribution Guidelines

- Fork the repo and create your feature branch
- Add tests for new features
- Submit a pull request with a clear description
- Check [CONTRIBUTING.md](./CONTRIBUTING.md) for coding standards, review process, and tips

---

## 🤖 About GitHub Copilot

This project leverages GitHub Copilot to generate code snippets, documentation, and comments.  
Copilot helps ensure:
- Clean, readable code
- Best practices for maintainability
- Extra inline explanations for tough OS concepts

---

## 🏆 Credits & Inspiration

Inspired by classic OS textbooks and university projects such as:
- "Operating System Concepts" by Silberschatz, Galvin, Gagne
- "Modern Operating Systems" by Andrew S. Tanenbaum
- MIT xv6 and MINIX microkernel

---

**Contributions welcome!**  
Level up your OS knowledge and join the simulation revolution! 💻⚡
