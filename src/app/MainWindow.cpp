// =============================================================================
// MainWindow.cpp — Wiring the calculator together
// =============================================================================

#include "app/MainWindow.h"

#include <QVBoxLayout>
#include <QWidget>

// =============================================================================
// Constructor — Build the UI and connect all the pieces
// =============================================================================

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    // -- Window Properties --
    setWindowTitle("Calculator");
    resize(320, 480);
    // ☝️ This is the DEFAULT size. Users can still resize the window.
    // For a fixed size, you'd use setFixedSize() instead.

    // =========================================================================
    // WHY DO WE NEED A "CENTRAL WIDGET"?
    //
    // QMainWindow is special — it has a menu bar, toolbar, status bar, and a
    // CENTRAL WIDGET area. You can't add layouts directly to QMainWindow.
    // Instead, you create a plain QWidget, set it as the central widget,
    // and put your layout on THAT.
    //
    // This is a common "gotcha" for beginners:
    //   ❌ setLayout(mainLayout);           // Doesn't work on QMainWindow!
    //   ✅ centralWidget->setLayout(layout); // This is the correct way
    // =========================================================================
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // -- Create the UI components --
    m_display = new CalcDisplay(centralWidget);
    m_buttonGrid = new ButtonGrid(centralWidget);
    // ☝️ Both are parented to centralWidget. When the window closes,
    // centralWidget is destroyed, which auto-destroys both children.
    // No memory leaks, no manual delete needed.

    // -- Arrange them vertically: display on top, buttons below --
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(m_display);          // Takes ~20% of height
    mainLayout->addWidget(m_buttonGrid, 1);    // Takes the rest (stretch factor = 1)
    // ☝️ The "1" is a STRETCH FACTOR. It tells the layout "give this widget
    // as much extra space as possible." Without it, the button grid would
    // only be as tall as its minimum size.

    // -- Wire up the signals --
    connectSignals();
}

MainWindow::~MainWindow() {
    // Qt's parent-child system cleans up all widgets automatically.
    // We only need to clean up non-Qt resources here (we have none).
}

// =============================================================================
// connectSignals — The "wiring diagram" of the calculator
// =============================================================================
// This is where architecture pays off. Each connection is one line:
//   "when THIS happens, do THAT"
//
// Reading this method tells you the ENTIRE behavior of the calculator
// without reading any other code.
// =============================================================================

void MainWindow::connectSignals() {
    // When a digit button is clicked → tell our slot
    connect(m_buttonGrid, &ButtonGrid::digitClicked,
            this, &MainWindow::onDigitClicked);

    // When an operator button is clicked → tell our slot
    connect(m_buttonGrid, &ButtonGrid::operationClicked,
            this, &MainWindow::onOperationClicked);

    // When = is clicked → tell our slot
    connect(m_buttonGrid, &ButtonGrid::equalsClicked,
            this, &MainWindow::onEqualsClicked);

    // When C is clicked → tell our slot
    connect(m_buttonGrid, &ButtonGrid::clearClicked,
            this, &MainWindow::onClearClicked);
}

// =============================================================================
// Slot Implementations — Each one follows the same pattern:
//   1. Tell the engine what happened
//   2. Update the display with the engine's new state
// =============================================================================

void MainWindow::onDigitClicked(char digit) {
    m_engine.appendDigit(digit);
    updateDisplay();
}

void MainWindow::onOperationClicked(Operation op) {
    m_engine.setOperation(op);
    updateDisplay();
}

void MainWindow::onEqualsClicked() {
    m_engine.calculate();
    updateDisplay();
}

void MainWindow::onClearClicked() {
    m_engine.clear();
    updateDisplay();
}

// =============================================================================
// updateDisplay — Bridge between engine (std::string) and UI (QString)
// =============================================================================

void MainWindow::updateDisplay() {
    // Convert std::string → QString
    // WHY the conversion? The engine uses std::string (standard C++, no Qt
    // dependency). The display uses QString (Qt's string class, which supports
    // Unicode, is implicitly shared, and integrates with all Qt widgets).
    // This one-line conversion is the "price" of keeping the engine Qt-free.
    QString text = QString::fromStdString(m_engine.getDisplayText());
    m_display->setText(text);
}
