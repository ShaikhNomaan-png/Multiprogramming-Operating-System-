# 🖥️ Multiprogramming Operating System Simulator

![Banner](https://raw.githubusercontent.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/main/assets/os_banner.png)

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Build Status](https://img.shields.io/github/workflow/status/ShaikhNomaan-png/Multiprogramming-Operating-System-/CI)](https://github.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/actions)
[![Languages](https://img.shields.io/github/languages/top/ShaikhNomaan-png/Multiprogramming-Operating-System-)](https://github.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/src)
[![Stars](https://img.shields.io/github/stars/ShaikhNomaan-png/Multiprogramming-Operating-System-?style=social)](https://github.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/stargazers)

---

## 🚀 Tech Highlights

<img src="https://raw.githubusercontent.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/main/assets/cpu_simulation.png" alt="CPU Simulation" width="400">  
**Phase 1:** CPU & Machine Simulation ⚙️ | Supervisor Calls via Interrupts 🚨

<img src="https://raw.githubusercontent.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/main/assets/paging_diagram.png" alt="Paging Diagram" width="400">  
**Phase 2:** Paging 🗂️ | Error Handling ❌ | Interrupt Generation & Servicing 🔄 | PCB Data Structure 📊

---

## 📊 Architecture Diagram

```mermaid
flowchart TD
    CPU[CPU]
    MEM[Memory]
    PCB[Process Control Block]
    INTR[Interrupt Handler]
    CPU -->|Executes| PCB
    PCB -->|Requests| INTR
    INTR -->|Handles| MEM
    MEM -->|Paging| CPU
```

---

## 💻 Simulation Screenshots

![Run Screenshot](https://raw.githubusercontent.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/main/assets/simulation_run.png)
![Interrupt Example](https://raw.githubusercontent.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/main/assets/interrupt_example.gif)

---

## 🌐 Why Use This Simulator?

- **Learn OS Fundamentals:**  
  Grasp multiprogramming, interrupts, memory management, and process control interactively.

- **Tech-Driven Design:**  
  Modern code, real-world scenarios, modular architecture.

- **Educational & Interactive:**  
  Perfect for students, educators, and developers.

---

## ⚡ Tech Stack

- **Languages:** C / C++ / Assembly
- **Structure:** Modular, extensible, educational

---

## 📚 Learn More

- **[Wiki](./wiki)** — Documentation & tutorials  
- **[Issues](https://github.com/ShaikhNomaan-png/Multiprogramming-Operating-System-/issues)** — Report bugs / suggest features

---

**Contributions welcome! Level up your OS knowledge and join the simulation revolution! 💻⚡**
