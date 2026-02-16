// =============================================================================
// ButtonGrid.h — The grid of calculator buttons
// =============================================================================
//
// WHY A SEPARATE CLASS FOR BUTTONS?
//
// MainWindow shouldn't know how buttons are arranged or styled. ButtonGrid
// handles all of that internally and just emits SIGNALS when something
// is clicked. MainWindow listens to those signals.
//
// This is the SIGNAL/SLOT pattern in action:
//   ButtonGrid emits "digitClicked('7')" → MainWindow receives it → tells engine
//
// The ButtonGrid doesn't know about the engine. The engine doesn't know about
// buttons. MainWindow is the "glue" that connects them. This is clean architecture.
// =============================================================================

#pragma once

#include "utils/Types.h"

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class ButtonGrid : public QWidget {
    Q_OBJECT

public:
    explicit ButtonGrid(QWidget* parent = nullptr);

// =============================================================================
// SIGNALS — Events that this class broadcasts
// =============================================================================
// In Qt, signals are DECLARED but never IMPLEMENTED by you. The MOC (Meta-Object
// Compiler) generates the implementation automatically. You just emit them:
//
//   emit digitClicked('7');  ← "broadcast to anyone listening"
//
// The "signals:" section is a Qt keyword (not standard C++). It's transformed
// by the MOC into real code.
// =============================================================================
signals:
    void digitClicked(char digit);          // A digit button was pressed
    void operationClicked(Operation op);    // An operator button was pressed
    void equalsClicked();                   // The = button was pressed
    void clearClicked();                    // The C button was pressed

    // TODO (Step 10): void backspaceClicked();
    // TODO (Step 11): void signToggleClicked();

private:
    QGridLayout* m_gridLayout;

    /// Create all the buttons and add them to the grid.
    void setupButtons();

    // TODO (Step 3): You'll implement these helper methods:

    /// Create a single digit button and connect its signal.
    /// Returns the button pointer so you can place it in the grid.
    QPushButton* createDigitButton(char digit);

    /// Create an operator button (+, -, etc.) and connect its signal.
    QPushButton* createOperatorButton(const QString& label, Operation op);
};
