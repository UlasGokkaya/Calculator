// =============================================================================
// CalculatorEngine.cpp — Implementation of the calculator's math logic
// =============================================================================
//
// This is the .cpp file for CalculatorEngine. In C++, the .h file DECLARES
// what a class can do (its interface), and the .cpp file DEFINES how it does it
// (its implementation).
//
// Think of it like a restaurant menu (.h) vs. the kitchen (.cpp):
//   - The menu says "we serve pasta" (declaration)
//   - The kitchen knows the recipe (definition)
//   - Customers (other files) only see the menu
// =============================================================================

#include "engine/CalculatorEngine.h"
// ☝️ We include our own header first. This is a convention that ensures
// the header is self-contained (it compiles on its own without needing
// other headers to be included before it).

// =============================================================================
// Constructor — Sets the initial state
// =============================================================================
// The ": m_displayText("0"), ..." syntax is called an INITIALIZER LIST.
//
// WHY use it instead of assignments in the body?
//   1. It's faster — members are initialized directly, not default-constructed
//      then overwritten
//   2. It's required for const members and references
//   3. It's the "correct" C++ way — you'll see it in all professional code
// =============================================================================

CalculatorEngine::CalculatorEngine()
    : m_displayText("0"), m_firstOperand(0.0), m_pendingOperation(Operation::None),
      m_waitingForSecondOperand(false) {
    // The initializer list above already did all the work.
    // The body is empty — this is totally normal for constructors.
}

// =============================================================================
// appendDigit — Add a digit to the current number
// =============================================================================
// TODO (Step 5): Implement this method
//
// HINTS:
//   - If m_displayText is "0", replace it (don't show "07")
//   - If m_waitingForSecondOperand is true, start fresh (replace display)
//   - Otherwise, just append the digit to the end of m_displayText
//
// =============================================================================

void CalculatorEngine::appendDigit(char digit) {
    if (m_waitingForSecondOperand) {
        m_displayText = std::string{digit};
        m_waitingForSecondOperand = false;
    } else if (m_displayText == "0") {
        m_displayText = std::string{digit};
    } else {
        m_displayText += digit;
    }
}

// =============================================================================
// setOperation — Store the operator and prepare for the second number
// =============================================================================
// TODO (Step 7): Implement this method
//
// HINTS:
//   - Convert m_displayText to a double and store in m_firstOperand
//   - Store the operation in m_pendingOperation
//   - Set m_waitingForSecondOperand = true
//   - Use std::stod() to convert string → double
// =============================================================================

void CalculatorEngine::setOperation(Operation op) {
    // TODO: Your implementation here
    (void)op;
}

// =============================================================================
// calculate — Execute the pending operation
// =============================================================================
// TODO (Step 7): Implement this method
//
// HINTS:
//   - Get the second operand from m_displayText (std::stod)
//   - Use a switch statement on m_pendingOperation
//   - Handle division by zero! (show "Error" or just prevent it)
//   - Store the result back into m_displayText
//   - Use std::to_string() to convert double → string
//
// EXAMPLE switch:
//   switch (m_pendingOperation) {
//       case Operation::Add:      result = m_firstOperand + secondOperand; break;
//       case Operation::Subtract: result = m_firstOperand - secondOperand; break;
//       // ... etc
//   }
// =============================================================================

void CalculatorEngine::calculate() {
    // TODO: Your implementation here
}

// =============================================================================
// clear — Reset to initial state
// =============================================================================

void CalculatorEngine::clear() {
    m_displayText = "0";
    m_firstOperand = 0.0;
    m_pendingOperation = Operation::None;
    m_waitingForSecondOperand = false;
}

// ☝️ This one is already done for you! It's simple enough to serve as an
// example of how to implement the others.

// =============================================================================
// getDisplayText — Return what the display should show
// =============================================================================

std::string CalculatorEngine::getDisplayText() const {
    return m_displayText;
}
