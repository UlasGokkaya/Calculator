# 🧭 Calculator — Learning Roadmap

This file tracks what you're building and in what order.
Each step is **~30 minutes**. Every step produces something you can **run and see**.

---

## ✅ Step 1 — Empty Window
- **What:** Window opens with a title and fixed size.
- **Learn:** `QApplication`, `QMainWindow`, CMake build system.
- **Files:** `main.cpp`, `MainWindow.h`, `MainWindow.cpp`

## ✅ Step 2 — Add the Display
- **What:** A `QLineEdit` at the top of the window, read-only, right-aligned.
- **Learn:** Widget creation, `QVBoxLayout`, parent-child ownership.
- **Files:** `CalcDisplay.h`, `CalcDisplay.cpp`, update `MainWindow`

## ✅ Step 3 — Add Digit Buttons (0–9)
- **What:** A 4×3 grid of number buttons appears below the display.
- **Learn:** `QGridLayout`, `QPushButton`, creating widgets in a loop.
- **Files:** `ButtonGrid.h`, `ButtonGrid.cpp`, update `MainWindow`

## ✅ Step 4 — Wire Digits to Display
- **What:** Clicking "7" makes "7" appear on the display.
- **Learn:** `connect()`, signals & slots, `Q_OBJECT` macro.
- **Files:** Update `ButtonGrid` (add signal), update `MainWindow` (add slot)

## ✅ Step 5 — Create the Calculator Engine
- **What:** A pure C++ class that knows how to accumulate digits into a number.
- **Learn:** Separating logic from UI, class design, `char` → `std::string` conversion.
- **Files:** `CalculatorEngine.h`, `CalculatorEngine.cpp`

## ⬜ Step 6 — Add Operator Buttons (+, −, ×, ÷) *(you are here)*
- **What:** Four operator buttons appear on the right side of the grid.
- **Learn:** `enum class Operation`, extending a grid layout.
- **Files:** Update `ButtonGrid`, update `Types.h`

## ⬜ Step 7 — Implement Equals (=)
- **What:** `3 + 4 =` shows `7`. Basic two-operand math works.
- **Learn:** State machine design, `calculate()` method, chaining operations.
- **Files:** Update `CalculatorEngine`, wire to `MainWindow`

## ⬜ Step 8 — Add Clear (C)
- **What:** Pressing C resets everything to "0".
- **Learn:** State reset, thinking about edge cases.
- **Files:** Update `CalculatorEngine`, `ButtonGrid`

## ⬜ Step 9 — Add Decimal Point
- **What:** You can type "3.14". Double dots are rejected.
- **Learn:** Input validation, `QString::contains()`.
- **Files:** Update `CalculatorEngine`

## ⬜ Step 10 — Add Backspace (⌫)
- **What:** Delete the last typed digit.
- **Learn:** `QString::chop()`, handling edge case (don't delete the last "0").
- **Files:** Update `CalculatorEngine`, `ButtonGrid`

## ⬜ Step 11 — Sign Toggle (±)
- **What:** Toggle between positive and negative numbers.
- **Learn:** String manipulation, negative number handling.
- **Files:** Update `CalculatorEngine`, `ButtonGrid`

## ⬜ Step 12 — Keyboard Input
- **What:** You can type digits and operators with the keyboard.
- **Learn:** `keyPressEvent()`, Qt event system, override virtual methods.
- **Files:** Update `MainWindow`

## ⬜ Step 13 — Dark Theme & Polish
- **What:** Rounded buttons, dark background, modern look.
- **Learn:** QSS (Qt Style Sheets — like CSS for Qt), `QPropertyAnimation`.
- **Files:** New `styles/` or inline QSS

## ⬜ Step 14 — History Panel
- **What:** Past calculations shown in a scrollable side panel.
- **Learn:** `QListWidget`, model patterns, data persistence concepts.
- **Files:** New `HistoryPanel.h/cpp`, update `MainWindow`

---

## 🏆 After Finishing
You'll have a **production-quality calculator** and solid understanding of:
- C++ classes, inheritance, enums, pointers
- Qt's widget system, layouts, signals/slots
- Professional project structure and build systems
- Styling, keyboard handling, and state management
