#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *productManager = new KProductManagerWindow(this);
    ui->m_stacked_function->addWidget(productManager);
    ui->m_stacked_function->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

