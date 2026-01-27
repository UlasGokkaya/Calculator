#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Boilerplate window setup
    setWindowTitle("Calculator");
    resize(400, 600); // Default size
}

MainWindow::~MainWindow() {
    // Cleanup code goes here
}