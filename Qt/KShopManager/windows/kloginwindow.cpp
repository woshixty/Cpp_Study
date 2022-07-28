#include "kloginwindow.h"
#include "ui_kloginwindow.h"
#include "utils/kconstants.h"

KLoginWindow::KLoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KLoginWindow)
{
    ui->setupUi(this);
    m_user_service = new KUserService(this);
}

KLoginWindow::~KLoginWindow()
{
    delete ui;
}

void KLoginWindow::on_m_login_btn_clicked()
{
    QString username = ui->m_username->text();
    QString password = ui->m_password->text();
    if(username.isNull() || username.isEmpty())
    {
        QMessageBox::warning(this, "用户名为空！", "用户名与密码不能为空！");
        return;
    }
    if(password.isNull() || password.isEmpty())
    {
        QMessageBox::warning(this, "密码为空！", "用户名与密码不能为空！");
        return;
    }
    UserLoginTypeErr type = m_user_service->login(username, password);
    switch (type) {
    case L_SUCCESS:
        QMessageBox::information(this, "登陆成功！", "登陆成功！");
        this->accept();
        break;
    case USER_NULL:
        QMessageBox::warning(this, "用户不存在！", "用户不存在！");
        break;
    case PASSWORD_ERR:
        QMessageBox::warning(this, "密码错误！", "密码错误！");
        break;
    }
}

void KLoginWindow::on_m_register_btn_clicked()
{
    QString username = ui->m_username->text();
    QString password = ui->m_password->text();
    if(username.isNull() || username.isEmpty())
    {
        QMessageBox::warning(this, "用户名为空！", "用户名不能为空！");
        return;
    }
    if(password.isNull() || password.isEmpty())
    {
        QMessageBox::warning(this, "密码为空！", "密码不能为空！");
        return;
    }
    UserRegisterTypeErr type = m_user_service->uregister(username, password);
    switch (type) {
    case R_SUCCESS:
        QMessageBox::information(this, "注册成功！", "注册成功！自动为你登陆跳转！");
        this->accept();
        break;
    case USER_EXIST:
        QMessageBox::warning(this, "用户存在！", "该用户名已被注册！");
        break;
    case R_ERR:
        QMessageBox::warning(this, "错误！", "注册失败！");
        break;
    }
}

