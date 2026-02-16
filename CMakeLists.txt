# =============================================================================
# CMakeLists.txt — The Build Recipe for the Calculator
# =============================================================================
#
# CMake is a BUILD SYSTEM GENERATOR — it doesn't compile your code directly.
# Instead, it generates Makefiles (or Ninja files), which THEN compile your code.
#
# Flow:  CMakeLists.txt → cmake → Makefile → make → Calculator binary
#
# Every line below is numbered and explained.
# =============================================================================

# ---------------------------------------------------------------------------
# 1. Minimum CMake version
# ---------------------------------------------------------------------------
# We need 3.16+ because that's when Qt6 CMake support became reliable.
# If someone has an older CMake, this line gives them a clear error message
# instead of cryptic failures.
# ---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.16)

# ---------------------------------------------------------------------------
# 2. Project metadata
# ---------------------------------------------------------------------------
# VERSION follows Semantic Versioning: MAJOR.MINOR.PATCH
#   0.x.x = "pre-release, still learning"
#   1.0.0 = "first stable release"
# LANGUAGES CXX tells CMake "this is a C++ project" (not C, not Fortran, etc.)
# ---------------------------------------------------------------------------
project(Calculator VERSION 0.1.0 LANGUAGES CXX)

# ---------------------------------------------------------------------------
# 3. C++ Standard
# ---------------------------------------------------------------------------
# C++17 gives us: std::optional, std::string_view, structured bindings,
# if-init statements, and more. It's the sweet spot for modern C++ in 2024+.
# STANDARD_REQUIRED means "fail if the compiler doesn't support C++17"
# (instead of silently falling back to an older standard).
# ---------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------------------------
# 4. Qt Auto-Generators
# ---------------------------------------------------------------------------
# AUTOMOC: Automatically runs the Meta-Object Compiler on files with Q_OBJECT.
#   Without this, signals/slots silently won't work and you'll go insane.
#
# AUTOUIC: Automatically processes .ui files (Qt Designer forms).
#   We're not using .ui files (we build UI in code), but it's harmless to have.
#
# AUTORCC: Automatically processes .qrc resource files (icons, stylesheets).
#   We'll use this when we add icons/themes.
# ---------------------------------------------------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# ---------------------------------------------------------------------------
# 5. Find Qt6
# ---------------------------------------------------------------------------
# find_package() searches your system for the Qt6 installation.
# REQUIRED means "if Qt6 is not installed, stop with an error."
# COMPONENTS Widgets means "we only need the Widgets module" (not Network,
# not SQL, not 3D — just the GUI widgets).
# ---------------------------------------------------------------------------
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# ---------------------------------------------------------------------------
# 6. List all source files
# ---------------------------------------------------------------------------
# Every .h and .cpp file in your project must be listed here.
# WHY list .h files? Because AUTOMOC needs to scan them for Q_OBJECT.
# If you forget to list a header with Q_OBJECT, signals/slots will break.
#
# TIP: When you create a new file, add it here immediately.
# ---------------------------------------------------------------------------
set(PROJECT_SOURCES
    # -- Entry point --
    src/main.cpp

    # -- Application layer (window orchestration) --
    src/app/MainWindow.h
    src/app/MainWindow.cpp

    # -- Engine (pure math logic, no Qt) --
    src/engine/CalculatorEngine.h
    src/engine/CalculatorEngine.cpp

    # -- UI components (reusable widgets) --
    src/ui/Display.h
    src/ui/Display.cpp
    src/ui/ButtonGrid.h
    src/ui/ButtonGrid.cpp

    # -- Shared types (header-only) --
    src/utils/Types.h
)

# ---------------------------------------------------------------------------
# 7. Create the executable
# ---------------------------------------------------------------------------
# This tells CMake: "take all those source files and produce a binary
# called 'Calculator'."
# ---------------------------------------------------------------------------
add_executable(Calculator ${PROJECT_SOURCES})

# ---------------------------------------------------------------------------
# 8. Include directories
# ---------------------------------------------------------------------------
# This lets you write: #include "engine/CalculatorEngine.h"
# instead of:          #include "../engine/CalculatorEngine.h"
#
# PRIVATE means only THIS target (Calculator) gets this include path.
# If we were building a library for others to use, we'd use PUBLIC.
# ---------------------------------------------------------------------------
target_include_directories(Calculator PRIVATE ${CMAKE_SOURCE_DIR}/src)

# ---------------------------------------------------------------------------
# 9. Link Qt libraries
# ---------------------------------------------------------------------------
# target_link_libraries() connects your code to Qt's compiled code.
# Without this, the linker would say "undefined reference to QApplication..."
# PRIVATE means Qt is an IMPLEMENTATION DETAIL — only Calculator uses it,
# not anyone who (hypothetically) links to Calculator.
# ---------------------------------------------------------------------------
target_link_libraries(Calculator PRIVATE Qt6::Widgets)