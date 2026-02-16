// =============================================================================
// CalculatorEngine.h — The "brain" of the calculator (pure C++, NO Qt)
// =============================================================================
//
// WHY THIS CLASS EXISTS (and why it has ZERO Qt code):
//
// Imagine you want to:
//   1. Test the math without opening a window
//   2. Reuse this logic in a command-line calculator
//   3. Port the engine to a mobile app
//
// If the math logic is tangled into MainWindow, NONE of that is possible.
// By keeping this class "pure C++" (only standard library, no Qt), we get:
//
//   ✅ Testable — Write unit tests that run in milliseconds, no GUI needed
//   ✅ Reusable — Same engine, different frontends
//   ✅ Readable — This file is ONLY about math, nothing else
//
// This is called "Separation of Concerns" — the #1 principle of clean code.
// =============================================================================

#pragma once

#include "utils/Types.h"  // Our shared Operation enum
#include <string>          // std::string for the display text

class CalculatorEngine {
public:
    // =========================================================================
    // Constructor
    // =========================================================================
    // Sets the engine to its initial state ("0" on the display, no operation).
    CalculatorEngine();

    // =========================================================================
    // Public Interface — These are the "buttons" the UI calls
    // =========================================================================

    // TODO (Step 5): Implement these methods in CalculatorEngine.cpp

    /// Append a digit character ('0'-'9') to the current number being typed.
    /// Example: display is "12", appendDigit('3') → display becomes "123"
    void appendDigit(char digit);

    /// Set the pending operation (+, −, ×, ÷) and prepare for the second operand.
    /// Example: user typed "5" then presses "+", so we store 5 and wait for next number.
    void setOperation(Operation op);

    /// Execute the pending operation: firstOperand [op] secondOperand.
    /// Example: 5 + 3 = → returns "8"
    void calculate();

    /// Reset everything back to the initial state.
    void clear();

    // TODO (Step 9):  void appendDecimalPoint();
    // TODO (Step 10): void backspace();
    // TODO (Step 11): void toggleSign();

    // =========================================================================
    // Getters — The UI reads these to update the display
    // =========================================================================

    /// Returns the text that should be shown on the display right now.
    /// This is the ONLY way the UI gets data from the engine.
    std::string getDisplayText() const;

    // ☝️ "const" at the end means "this method promises not to modify the object"
    // It's a contract: the compiler enforces it. Use it on all getters.

private:
    // =========================================================================
    // Internal State — The "memory" of the calculator
    // =========================================================================

    std::string m_displayText;       // What's currently shown on the display
    double m_firstOperand;           // The number BEFORE the operator (e.g., "5" in "5 + 3")
    Operation m_pendingOperation;    // Which operation is waiting (e.g., Add)
    bool m_waitingForSecondOperand;  // Are we waiting for the user to type the next number?

    // ☝️ WHY the "m_" prefix?
    // It stands for "member variable". It's a convention that instantly tells you
    // "this is a class field, not a local variable." You'll see it everywhere
    // in professional C++ and Qt code. Some teams use "m_", others use "_" suffix.
    // Pick one and be consistent.
};
