// =============================================================================
// main.cpp — The entry point of the application
// =============================================================================
//
// This file should ALWAYS be tiny. Its only job is:
//   1. Create the QApplication  (sets up the event loop + OS connection)
//   2. Create the MainWindow    (builds the entire UI)
//   3. Show the window           (makes it visible)
//   4. Enter the event loop      (app.exec() — waits for events forever)
//
// If you're tempted to add logic here, put it in MainWindow or Engine instead.
// =============================================================================

#include "app/MainWindow.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    // Step 1: Initialize the application framework
    // QApplication handles: command-line args, display connection,
    // default fonts, event dispatching, and application-wide settings.
    QApplication app(argc, argv);

    // Step 2: Create the main window (this builds the entire UI tree)
    MainWindow window;

    // Step 3: Make the window visible (widgets start hidden by default)
    window.show();

    // Step 4: Enter the event loop
    // exec() runs an infinite loop:
    //   - Wait for an event (click, key, timer, resize...)
    //   - Dispatch it to the right widget
    //   - Repeat until the window is closed
    //
    // When the user closes the window, exec() returns 0, and main() exits.
    return app.exec();
}