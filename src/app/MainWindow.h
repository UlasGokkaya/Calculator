// =============================================================================
// MainWindow.h — The main application window (the "glue" that connects everything)
// =============================================================================
//
// ROLE OF THIS CLASS:
// MainWindow is the ORCHESTRATOR. It doesn't do math (that's CalculatorEngine)
// and it doesn't create buttons (that's ButtonGrid). It:
//
//   1. CREATES the engine, display, and button grid
//   2. ARRANGES them in a layout
//   3. CONNECTS signals from ButtonGrid to methods that call the engine
//   4. UPDATES the display with the engine's result
//
// Think of MainWindow as a DIRECTOR of a movie — it doesn't act, it tells
// the actors (widgets) what to do and when.
// =============================================================================

#pragma once

#include "engine/CalculatorEngine.h"
#include "ui/ButtonGrid.h"
#include "ui/Display.h"

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

// =============================================================================
// PRIVATE SLOTS — Methods that respond to signals
// =============================================================================
// In modern Qt (Qt 5+), any regular method can be used as a slot with
// the new connect() syntax. The "slots:" keyword is technically optional,
// but it's still good practice for documentation and IDE support.
// =============================================================================
private slots:
    void onDigitClicked(char digit);
    void onOperationClicked(Operation op);
    void onEqualsClicked();
    void onClearClicked();

    // TODO (Step 10): void onBackspaceClicked();
    // TODO (Step 11): void onSignToggleClicked();

private:
    // -- Owned objects --
    CalculatorEngine m_engine;   // The math brain (NOT a pointer — lives on the stack)
    // ☝️ Unlike widgets, the engine is not a QObject and has no parent.
    // It lives as a regular member variable — created when MainWindow is
    // created, destroyed when MainWindow is destroyed. Simple ownership.

    CalcDisplay* m_display;      // The screen widget (pointer, because Qt owns it)
    ButtonGrid* m_buttonGrid;   // The button grid (pointer, same reason)

    /// Wire all signals from ButtonGrid to our slot methods.
    void connectSignals();

    /// Read the engine's display text and update the UI display.
    void updateDisplay();
};
