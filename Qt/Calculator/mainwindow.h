#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <screenedit.h>
#include <calculator.h>
#include <keyboardwidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    Calculator *calculator;
};

#endif // MAINWINDOW_H
