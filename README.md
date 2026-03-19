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
├── src/                                  # Core source code
│   ├── hanoi_main.cpp                    # Main application entry and loop control
│   ├── hanoi_menu.cpp                    # Interactive menu system implementation
│   ├── hanoi_multiple_solutions.cpp     # Scheduling and animation execution logic
│   ├── cmd_console_tools.cpp            # Low-level console UI utilities
│   ├── cmd_hdc_tools.cpp                # Windows GDI drawing implementations
│   ├── hanoi.h                          # Core function and class declarations
│   ├── cmd_console_tools.h              # Console utility headers
│   ├── cmd_hdc_tools.h                  # GDI utility headers
│   └── hanoi_const_value.h              # Default UI configuration (Standard)
│
├── themes/                               # Alternative UI profiles
│   ├── hanoi_const_value-P.h            # 'Fat' UI profile
│   └── hanoi_const_value-s.h            # 'Slim' UI profile
│
└── README.md                             # Project documentation
```

---

# 汉诺塔可视化与交互系统

本项目实现了一个基于 C++ 的控制台应用程序，用于汉诺塔算法的可视化与研究。系统利用 Windows 控制台 API 和图形设备接口（GDI），提供了一个观察递归状态转移和探索基于控制台的渲染技术的平台。

## 实现细节

该系统整合了多个功能模块，以促进算法研究和用户交互：

* **运行模式**：实现了九种不同的模式，从基于文本的顺序步骤追踪到自动图形动画。此外还包括具有集成规则验证的手动交互模式（例如，防止将较大的圆盘放在较小的圆盘上）。
* **双渲染架构**：应用程序支持两条渲染路径：显示实时状态数组的文本界面，以及利用 Windows GDI 进行视觉动画处理的图形引擎。
* **可配置 UI 配置文件**：视觉参数与核心递归逻辑解耦。系统支持模块化的 UI 配置文件（标准 Standard、胖 Fat 和瘦 Slim），可以通过更换配置头文件来切换样式。
* **控制台控制与输入管理**：采用底层控制台缓冲区管理和 `_getch` 输入处理，以保持显示稳定性并最大限度地减少高频屏幕更新期间的伪影（如光标闪烁）。

## 📁 项目结构

仓库的组织方式保持了核心逻辑、实用功能和视觉配置之间的清晰分离：

```text
Interactive-Tower-of-Hanoi/
├── src/                                  # 核心源代码
│   ├── hanoi_main.cpp                    # 主程序入口和循环控制
│   ├── hanoi_menu.cpp                    # 交互式菜单系统实现
│   ├── hanoi_multiple_solutions.cpp     # 调度与动画执行逻辑
│   ├── cmd_console_tools.cpp            # 底层控制台 UI 工具
│   ├── cmd_hdc_tools.cpp                # Windows GDI 绘图实现
│   ├── hanoi.h                          # 核心函数与类声明
│   ├── cmd_console_tools.h              # 控制台工具头文件
│   ├── cmd_hdc_tools.h                  # GDI 工具头文件
│   └── hanoi_const_value.h              # 默认 UI 配置 (Standard)
│
├── themes/                               # 备选 UI 配置文件
│   ├── hanoi_const_value-P.h            # 'Fat' (胖) UI 样式
│   └── hanoi_const_value-s.h            # 'Slim' (瘦) UI 样式
│
└── README.md                             # 项目文档
```
