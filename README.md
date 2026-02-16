# Calculator

A professional-grade desktop calculator built with **C++17** and **Qt 6**.

![License](https://img.shields.io/badge/license-MIT-blue)
![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Qt](https://img.shields.io/badge/Qt-6-green)

## Features

- Standard arithmetic operations (+, −, ×, ÷)
- Decimal number support
- Keyboard input
- Calculation history
- Dark / light theme
- Clean, modern UI

> **Note:** This project is being built incrementally. See [`ROADMAP.md`](ROADMAP.md) for current progress.

## Prerequisites

| Dependency | Version | Install (Ubuntu/Debian) |
|---|---|---|
| CMake | ≥ 3.16 | `sudo apt install cmake` |
| Qt 6 | ≥ 6.2 | `sudo apt install qt6-base-dev` |
| C++ Compiler | GCC 11+ or Clang 14+ | `sudo apt install g++` |

## Build & Run

```bash
# 1. Configure the build (from the project root)
cmake -B build -DCMAKE_BUILD_TYPE=Debug

# 2. Compile
cmake --build build

# 3. Run
./build/Calculator
```

## Project Structure

```
Calculator/
├── CMakeLists.txt          # Build configuration
├── ROADMAP.md              # Learning roadmap & progress
├── README.md               # This file
├── .clang-format           # Code style rules
│
├── src/                    # Source code
│   ├── main.cpp            # Entry point
│   ├── app/                # Application window & orchestration
│   │   ├── MainWindow.h
│   │   └── MainWindow.cpp
│   ├── engine/             # Pure calculation logic (no Qt)
│   │   ├── CalculatorEngine.h
│   │   └── CalculatorEngine.cpp
│   ├── ui/                 # Reusable UI components
│   │   ├── Display.h / .cpp
│   │   └── ButtonGrid.h / .cpp
│   └── utils/              # Shared types & constants
│       └── Types.h
│
├── tests/                  # Unit tests (QTest)
└── resources/              # Icons, stylesheets, fonts
```

### Why This Structure?

| Directory | Responsibility |
|---|---|
| `src/app/` | Wires everything together — owns the engine and UI widgets |
| `src/engine/` | Pure math, zero Qt dependency — testable and reusable |
| `src/ui/` | Self-contained widget components |
| `src/utils/` | Shared enums and type definitions |

## License

MIT
