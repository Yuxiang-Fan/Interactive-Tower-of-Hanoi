# Interactive Tower of Hanoi Visualizer

A robust, pure C++ console application that brings the classic Tower of Hanoi algorithm to life. Built entirely from scratch using the Windows Console API and GDI (Graphics Device Interface), this project demonstrates advanced control over console rendering, state machine management, and recursive algorithm visualization.

## ✨ Key Features

* **9 Interactive Modes**: Spans from basic text-based step tracking to fully automated graphical animations, and even a playable manual game mode with strict rule validation (e.g., preventing large disks on small disks).
* **Dual Rendering Engine**: Seamlessly switches between a text-based UI (displaying horizontal and vertical real-time state arrays) and a smooth, flicker-free graphical animation engine.
* **Custom UI Themes**: The core logic is decoupled from visual configurations. The application supports modular UI themes (Standard, Fat, Slim) through interchangeable header files.
* **Robust Input Handling**: Features custom delay loops and strictly controlled input buffers (`_getch`) to prevent cursor jumping, screen flickering, and buffer overflow common in console animations.

## 📁 Project Structure

This repository is designed to be a lightweight, IDE-agnostic source code distribution.

```text
Interactive-Tower-of-Hanoi/
├── src/                                 # Core source code
│   ├── hanoi_main.cpp                   # Main entry loop
│   ├── hanoi_menu.cpp                   # Interactive menu system
│   ├── hanoi_multiple_solutions.cpp     # Core scheduling and animation logic
│   ├── cmd_console_tools.cpp            # Low-level console UI utilities
│   ├── cmd_hdc_tools.cpp                # Windows GDI drawing utilities
│   ├── hanoi.h                          # Core declarations
│   ├── cmd_console_tools.h              # Console utilities header
│   ├── cmd_hdc_tools.h                  # GDI utilities header
│   └── hanoi_const_value.h              # Default UI configuration (Standard)
│
├── themes/                              # Alternative UI profiles
│   ├── hanoi_const_value-P.h            # 'Fat' UI profile
│   └── hanoi_const_value-s.h            # 'Slim' UI profile
│
└── README.md                            # Project documentation