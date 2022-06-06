#include "kdialogin.h"
#include "ui_kdialogin.h"

KDialogin::KDialogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KDialogin)
{
    ui->setupUi(this);
    m_user_service = new KUserService(this);
}

KDialogin::~KDialogin()
{
    delete ui;
}

void KDialogin::on_m_login_btn_clicked()
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
    case SUCCESS:
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

