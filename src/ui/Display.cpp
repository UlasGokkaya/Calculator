// =============================================================================
// Display.cpp — Implementation of the calculator display
// =============================================================================

#include "ui/Display.h"

#include <QFont>
#include <QVBoxLayout>

// =============================================================================
// Constructor
// =============================================================================
// The pattern here is:
//   1. Call the parent constructor (QWidget)
//   2. Create child widgets
//   3. Call a setup method to configure them
//
// This keeps the constructor body clean and readable.
// =============================================================================

CalcDisplay::CalcDisplay(QWidget* parent)
    : QWidget(parent)               // ← call the parent class constructor
    , m_lineEdit(new QLineEdit(this))  // ← create the text field, parented to us
{
    setupUI();
}

// =============================================================================
// setupUI — Configure the display's appearance
// =============================================================================
// TODO (Step 2): This is where you customize the display.
//
// Right now it works but looks plain. In Step 2, you'll:
//   - Set a larger font
//   - Right-align the text (numbers go right-to-left)
//   - Set a minimum height so it's not tiny
//   - Maybe add a frame or background color
// =============================================================================

void CalcDisplay::setupUI() {
    // -- Make it read-only (users type via buttons, not keyboard... for now) --
    m_lineEdit->setReadOnly(true);

    // -- Right-align the text (like a real calculator) --
    m_lineEdit->setAlignment(Qt::AlignRight);

    // -- Set a larger font so numbers are easy to read --
    QFont displayFont = m_lineEdit->font();
    displayFont.setPointSize(24);
    m_lineEdit->setFont(displayFont);

    // -- Set the initial text --
    m_lineEdit->setText("0");

    // -- Layout: put the line edit inside this widget --
    // WHY do we need a layout?
    // Without a layout, the QLineEdit would be positioned at (0,0) with its
    // default size, ignoring the Display widget's actual size. A layout makes
    // the QLineEdit automatically resize to fill the Display widget.
    QVBoxLayout* layout = new QVBoxLayout(this);
    // ☝️ "new QVBoxLayout(this)" — "this" is the parent. The layout attaches
    // itself to our widget. Qt deletes it when we're destroyed.

    layout->setContentsMargins(0, 0, 0, 0);  // No padding around the text field
    layout->addWidget(m_lineEdit);
    // ☝️ addWidget() puts our text field into the layout. If we had multiple
    // widgets, addWidget() would stack them vertically (that's what the "V"
    // in QVBoxLayout means — Vertical).
}

// =============================================================================
// setText / text — Simple forwarding methods
// =============================================================================
// These just forward to m_lineEdit. "Why not access m_lineEdit directly?"
// Because other classes shouldn't know (or care) that Display uses a QLineEdit
// internally. This is ENCAPSULATION — hide implementation details.
// =============================================================================

void CalcDisplay::setText(const QString& text) {
    m_lineEdit->setText(text);
}

QString CalcDisplay::text() const {
    return m_lineEdit->text();
}
