#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *enterPage = new KEnterPageWindow(this);
    QWidget *productSell = new KProductSellWindows(this);
    QWidget *productManager = new KProductManagerWindow(this);
    ui->m_stacked_function->addWidget(enterPage);
    ui->m_stacked_function->addWidget(productSell);
    ui->m_stacked_function->addWidget(productManager);
    ui->m_stacked_function->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDataBase()
{

}

void MainWindow::on_m_sider_clicked(const QModelIndex &index)
{
    QString tagName = index.data().toString();
    if(tagName.compare("出售管理") == 0)
        ui->m_stacked_function->setCurrentIndex(1);
    else if(tagName.compare("商品管理") == 0)
        ui->m_stacked_function->setCurrentIndex(2);
    else
        ui->m_stacked_function->setCurrentIndex(0);
}

