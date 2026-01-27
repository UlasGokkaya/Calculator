#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT // <--- The most important line in Qt

public:
    // Constructor (boilerplate signature)
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // This is where you will declare your UI elements later
    // (e.g., QLineEdit *display; QPushButton *digits[10];)
};