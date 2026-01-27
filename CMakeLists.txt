cmake_minimum_required(VERSION 3.16)

# 1. Project Meta-data
project(Calculator VERSION 1.0 LANGUAGES CXX)

# 2. C++ Standard (We use 17 for modern features like std::optional)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Qt-Specific Magic (The "Why" is explained below)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 4. Find the Qt Library
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# 5. Define Your Source Files
# (Tip: As you add files, list them here)
set(PROJECT_SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
)

# 6. Create the Executable
add_executable(Calculator ${PROJECT_SOURCES})

# 7. Link Libraries (Connect your code to Qt)
target_link_libraries(Calculator PRIVATE Qt6::Widgets)