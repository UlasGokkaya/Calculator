// =============================================================================
// ButtonGrid.cpp — Implementation of the calculator button grid
// =============================================================================

#include "ui/ButtonGrid.h"

#include <QSizePolicy>

// =============================================================================
// Constructor
// =============================================================================

ButtonGrid::ButtonGrid(QWidget* parent)
    : QWidget(parent)
    , m_gridLayout(new QGridLayout(this))
{
    setupButtons();
}

// =============================================================================
// setupButtons — Create and arrange all calculator buttons
// =============================================================================
// TODO (Step 3): Build the button grid!
//
// A standard calculator layout looks like this:
//
//   [ C ][ ⌫ ][ ÷ ]
//   [ 7 ][ 8 ][ 9 ][ × ]
//   [ 4 ][ 5 ][ 6 ][ − ]
//   [ 1 ][ 2 ][ 3 ][ + ]
//   [   0   ][ . ][ = ]
//
// Use m_gridLayout->addWidget(button, row, col) to place each button.
// The third parameter can include column span:
//   m_gridLayout->addWidget(zeroButton, 4, 0, 1, 2);
//   ☝️ This means: row 4, col 0, span 1 row and 2 columns (wide zero button)
//
// EXAMPLE to get you started:
//
//   void ButtonGrid::setupButtons() {
//       // -- Row 1: C and ÷ --
//       QPushButton* clearBtn = new QPushButton("C", this);
//       connect(clearBtn, &QPushButton::clicked, this, &ButtonGrid::clearClicked);
//       m_gridLayout->addWidget(clearBtn, 0, 0);
//
//       // -- Row 2: digits 7, 8, 9 and × --
//       m_gridLayout->addWidget(createDigitButton('7'), 1, 0);
//       m_gridLayout->addWidget(createDigitButton('8'), 1, 1);
//       m_gridLayout->addWidget(createDigitButton('9'), 1, 2);
//       m_gridLayout->addWidget(createOperatorButton("×", Operation::Multiply), 1, 3);
//
//       // ... continue for all rows ...
//   }
// =============================================================================

void ButtonGrid::setupButtons() {
    // -------------------------------------------------------------------------
    // Row 0: Clear and divide
    // -------------------------------------------------------------------------
    QPushButton* clearBtn = new QPushButton("C", this);
    connect(clearBtn, &QPushButton::clicked, this, &ButtonGrid::clearClicked);
    // ☝️ connect() is the heart of Qt. Let's break it down:
    //
    //   connect(
    //       clearBtn,                        // WHO emits the signal (sender)
    //       &QPushButton::clicked,           // WHAT signal is emitted
    //       this,                            // WHO receives it (receiver)
    //       &ButtonGrid::clearClicked        // WHAT slot/signal to call
    //   );
    //
    // Here we're doing something sneaky: we're connecting a SIGNAL to another
    // SIGNAL. When clearBtn emits clicked(), our ButtonGrid re-emits
    // clearClicked(). This "bubbles up" the event to whoever is listening
    // to ButtonGrid.

    m_gridLayout->addWidget(clearBtn, 0, 0);

    // TODO (Step 10): Add backspace button at row 0, col 1

    m_gridLayout->addWidget(
        createOperatorButton("÷", Operation::Divide), 0, 2);

    // -------------------------------------------------------------------------
    // Rows 1-3: Digit buttons + operators
    // -------------------------------------------------------------------------
    // TODO (Step 3): Add the rest of the digit and operator buttons
    //
    // Here's the pattern — one row done for you:

    // Row 1: 7, 8, 9, ×
    m_gridLayout->addWidget(createDigitButton('7'), 1, 0);
    m_gridLayout->addWidget(createDigitButton('8'), 1, 1);
    m_gridLayout->addWidget(createDigitButton('9'), 1, 2);
    m_gridLayout->addWidget(
        createOperatorButton("×", Operation::Multiply), 1, 3);

    // Row 2: 4, 5, 6, −
    m_gridLayout->addWidget(createDigitButton('4'), 2, 0);
    m_gridLayout->addWidget(createDigitButton('5'), 2, 1);
    m_gridLayout->addWidget(createDigitButton('6'), 2, 2);
    m_gridLayout->addWidget(
        createOperatorButton("−", Operation::Subtract), 2, 3);

    // Row 3: 1, 2, 3, +
    m_gridLayout->addWidget(createDigitButton('1'), 3, 0);
    m_gridLayout->addWidget(createDigitButton('2'), 3, 1);
    m_gridLayout->addWidget(createDigitButton('3'), 3, 2);
    m_gridLayout->addWidget(
        createOperatorButton("+", Operation::Add), 3, 3);

    // -------------------------------------------------------------------------
    // Row 4: 0 (wide), decimal point, equals
    // -------------------------------------------------------------------------
    QPushButton* zeroBtn = createDigitButton('0');
    m_gridLayout->addWidget(zeroBtn, 4, 0, 1, 2);  // Span 2 columns
    // ☝️ addWidget(widget, row, col, rowSpan, colSpan)
    // The 0 button is traditionally wider, spanning 2 columns.

    // TODO (Step 9): Add decimal point button at row 4, col 2
    // For now, we put a placeholder:
    QPushButton* dotBtn = new QPushButton(".", this);
    dotBtn->setEnabled(false);  // Disabled until Step 9
    m_gridLayout->addWidget(dotBtn, 4, 2);

    QPushButton* equalsBtn = new QPushButton("=", this);
    connect(equalsBtn, &QPushButton::clicked, this, &ButtonGrid::equalsClicked);
    m_gridLayout->addWidget(equalsBtn, 4, 3);

    // -------------------------------------------------------------------------
    // Make all buttons expand to fill available space
    // -------------------------------------------------------------------------
    // WHY setSizePolicy?
    // By default, buttons have a "preferred" size and won't grow. In a
    // calculator, we want buttons to fill the entire window evenly. This
    // policy says "expand in both directions as much as possible."
    // -------------------------------------------------------------------------
    for (int i = 0; i < m_gridLayout->count(); ++i) {
        QWidget* widget = m_gridLayout->itemAt(i)->widget();
        if (widget) {
            widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        }
    }
}

// =============================================================================
// createDigitButton — Factory method for digit buttons
// =============================================================================
// WHY a factory method?
// Because every digit button needs the same setup (create, connect, return).
// Without this, you'd copy-paste the same 4 lines ten times.
// "Don't Repeat Yourself" (DRY) is a fundamental principle.
// =============================================================================

QPushButton* ButtonGrid::createDigitButton(char digit) {
    // QString(1, digit) creates a one-character string from the char
    QPushButton* button = new QPushButton(QString(QChar(digit)), this);

    // =======================================================================
    // LAMBDA EXPLANATION — This is the trickiest part for beginners:
    //
    //   [this, digit]() { emit digitClicked(digit); }
    //
    // Breaking it down:
    //   [this, digit]  — "capture" these variables so the lambda can use them
    //   ()             — the lambda takes no parameters (clicked() has none)
    //   { ... }        — the code to run when the button is clicked
    //
    // WHY a lambda? Because clicked() sends no data, but our signal
    // digitClicked(char) needs to know WHICH digit. The lambda "wraps"
    // the digit value and forwards it.
    //
    // It's equivalent to writing a whole separate slot method for each digit,
    // but much cleaner.
    // =======================================================================
    connect(button, &QPushButton::clicked, this, [this, digit]() {
        emit digitClicked(digit);
    });

    return button;
}

// =============================================================================
// createOperatorButton — Factory method for operator buttons
// =============================================================================

QPushButton* ButtonGrid::createOperatorButton(const QString& label, Operation op) {
    QPushButton* button = new QPushButton(label, this);

    connect(button, &QPushButton::clicked, this, [this, op]() {
        emit operationClicked(op);
    });

    return button;
}
