# =============================================================================
# tests/CMakeLists.txt — Unit Test Configuration
# =============================================================================
#
# TODO (After Step 7): Set up QTest for testing CalculatorEngine
#
# Example of what this will look like:
#
#   find_package(Qt6 REQUIRED COMPONENTS Test)
#
#   add_executable(CalculatorEngineTest
#       test_calculator_engine.cpp
#       ../src/engine/CalculatorEngine.cpp
#       ../src/engine/CalculatorEngine.h
#       ../src/utils/Types.h
#   )
#
#   target_include_directories(CalculatorEngineTest PRIVATE ../src)
#   target_link_libraries(CalculatorEngineTest PRIVATE Qt6::Test)
#
#   add_test(NAME CalculatorEngineTest COMMAND CalculatorEngineTest)
#
# Notice how we only link the ENGINE files — no MainWindow, no Display,
# no ButtonGrid. That's the power of separation of concerns!
# =============================================================================
