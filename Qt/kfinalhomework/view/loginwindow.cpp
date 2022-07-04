#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    m_userService = new KUserService;
}

LoginWindow::~LoginWindow()
{
    delete ui;
    delete m_userService;
}

void LoginWindow::on_loginBtn_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (username.isEmpty())
    {
        QMessageBox::information(this, "提示信息", "用户名不可为空", QMessageBox::Ok, QMessageBox::NoButton);
    }
    if (password.isEmpty())
    {
        QMessageBox::information(this, "提示信息", "密码不可为空", QMessageBox::Ok, QMessageBox::NoButton);
    }

    if (m_userService->login(username, password))
    {
        KMainWindow *mainwin = new KMainWindow;
        mainwin->show();
        this->close();
    }
    else
    {
        QMessageBox::information(this, "提示信息", "用户名或密码错误", QMessageBox::Ok, QMessageBox::NoButton);
    }
}

