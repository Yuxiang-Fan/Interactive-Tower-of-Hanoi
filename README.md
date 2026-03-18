# Tower of Hanoi Visualization and Interaction System

This project implements a C++ console application designed for the visualization and study of the Tower of Hanoi algorithm. Utilizing the Windows Console API and Graphics Device Interface (GDI), the system provides a platform to observe recursive state transitions and explore console-based rendering techniques.

## Implementation Details

The system incorporates several functional modules to facilitate algorithmic study and user interaction:

* **Operational Modes**: Nine distinct modes are implemented, ranging from sequential text-based step tracking to automated graphical animations. It also includes a manual interaction mode with integrated rule validation (e.g., preventing the placement of larger disks onto smaller ones).
* **Dual Rendering Architecture**: The application supports two rendering paths: a text-based interface displaying real-time state arrays and a graphical engine that leverages Windows GDI for visual animations.
* **Configurable UI Profiles**: Visual parameters are decoupled from the core recursive logic. The system supports modular UI profiles (Standard, Fat, and Slim) which can be toggled by interchanging configuration header files.
* **Console Control and Input Management**: Low-level console buffer management and `_getch` input handling are employed to maintain display stability and minimize artifacts such as cursor flickering during high-frequency screen updates.

## 📁 Project Structure

The repository is organized to maintain a clear separation between core logic, utility functions, and visual configurations:

```text
Interactive-Tower-of-Hanoi/
├── src/                                 # Core source code
│   ├── hanoi_main.cpp                   # Main application entry and loop control
│   ├── hanoi_menu.cpp                   # Interactive menu system implementation
│   ├── hanoi_multiple_solutions.cpp     # Scheduling and animation execution logic
│   ├── cmd_console_tools.cpp            # Low-level console UI utilities
│   ├── cmd_hdc_tools.cpp                # Windows GDI drawing implementations
│   ├── hanoi.h                          # Core function and class declarations
│   ├── cmd_console_tools.h              # Console utility headers
│   ├── cmd_hdc_tools.h                  # GDI utility headers
│   └── hanoi_const_value.h              # Default UI configuration (Standard)
│
├── themes/                              # Alternative UI profiles
│   ├── hanoi_const_value-P.h            # 'Fat' UI profile
│   └── hanoi_const_value-s.h            # 'Slim' UI profile
│
└── README.md                            # Project documentation
