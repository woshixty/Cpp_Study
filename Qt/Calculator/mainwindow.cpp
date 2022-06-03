#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    calculator(nullptr)
{
    ui->setupUi(this);
    calculator = new Calculator(*(ui->screenEdit));
    ui->keyboardWidget->setCalculator(calculator);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete calculator;
}

// 通过操作符和操作数计算结果
double Calculate(double num1, wchar_t ope, double num2)
{
    switch (ope) {
    case L'+':
        return num1 + num2;
    case L'-':
        return num1 - num2;
    case L'×':
        return num1 * num2;
    case L'÷':
        return num1 / num2;
    default:
        return num1;
    }
}
