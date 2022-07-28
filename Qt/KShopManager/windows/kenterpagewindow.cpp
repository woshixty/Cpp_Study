#include "kenterpagewindow.h"
#include "ui_kenterpagewindow.h"

KEnterPageWindow::KEnterPageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KEnterPageWindow)
{
    ui->setupUi(this);
}

KEnterPageWindow::~KEnterPageWindow()
{
    delete ui;
}
