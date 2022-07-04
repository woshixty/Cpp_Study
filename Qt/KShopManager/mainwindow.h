#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "windows/kproductmanagerwindow.h"
#include "windows/kenterpagewindow.h"
#include "windows/kproductsellwindows.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initDataBase();

private slots:

    void on_m_sider_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
