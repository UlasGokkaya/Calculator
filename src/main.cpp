#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    // 1. Initialize the Application
    // This sets up the Event Loop and OS connection
    QApplication app(argc, argv);

    // 2. Create and Show the Window
    MainWindow window;
    window.show();

    // 3. Enter the Event Loop
    // The program pauses here and waits for clicks/keys
    return app.exec();
}