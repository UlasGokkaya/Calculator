// =============================================================================
// Display.h — The calculator's screen (a custom widget wrapping QLineEdit)
// =============================================================================
//
// NAMING NOTE: This class is called "CalcDisplay" instead of "Display" because
// X11 (the Linux graphics system) already defines a type called "Display".
// If we named our class "Display", the compiler would get confused between
// our class and X11's Display. This is a REAL-WORLD lesson: always check
// that your class names don't collide with system libraries!
//
// Common strategies to avoid this:
//   1. Use a more specific name (CalcDisplay) ← what we do
//   2. Use a namespace (Calc::Display)
//   3. Use a prefix (CDisplay — old MFC-style, avoid this)
//
//
// WHY A SEPARATE CLASS FOR THE DISPLAY?
//
// "It's just a text field — why not create QLineEdit directly in MainWindow?"
//
// Good question! In a small project, you could. But wrapping it teaches you:
//   1. ENCAPSULATION — The display knows how to configure itself (font, alignment,
//      read-only). MainWindow doesn't need to know those details.
//   2. REUSABILITY — If you later want a second display (e.g., showing the
//      pending operation), you just create another Display instance.
//   3. SINGLE RESPONSIBILITY — Each class does one thing well.
//
// This pattern (wrapping a Qt widget in your own class) is extremely common
// in production Qt code.
// =============================================================================

#pragma once

#include <QLineEdit>
#include <QWidget>

// =============================================================================
// WHY INHERIT FROM QWidget (not QLineEdit)?
//
// We COULD inherit from QLineEdit directly:
//   class Display : public QLineEdit { ... };
//
// But wrapping with composition (having a QLineEdit as a member) gives us
// more flexibility — we can add labels, animations, etc. later without
// changing the public interface.
//
// For now, we inherit from QWidget (the base class of ALL visual elements in
// Qt) and own a QLineEdit internally.
// =============================================================================

class CalcDisplay : public QWidget {
    Q_OBJECT
    // ☝️ Q_OBJECT is required in EVERY class that uses signals or slots.
    // Even if you don't have any yet, add it proactively — adding it later
    // after the class is in use can cause confusing build errors.

public:
    /// Constructor. The "parent" parameter is Qt's ownership system:
    /// if you pass a parent, the parent auto-deletes this widget.
    explicit CalcDisplay(QWidget* parent = nullptr);
    // ☝️ "explicit" prevents accidental implicit conversions:
    //   Display d = someWidget;  ← this would compile without "explicit" (bad!)
    //   Display d(someWidget);   ← this is the intended usage

    /// Update the text shown on the display.
    void setText(const QString& text);
    // ☝️ "const QString&" means:
    //   - const: we promise not to modify the string
    //   - &: we pass by reference (no copy, efficient)
    //   Together: "borrow the string, read-only"

    /// Get the current display text.
    QString text() const;

private:
    QLineEdit* m_lineEdit;  // The actual text field widget
    // ☝️ Raw pointer is fine here because Qt's parent-child system manages
    // the memory. When Display is destroyed, it destroys m_lineEdit too.

    /// Configure the look and feel of the display.
    void setupUI();
};
