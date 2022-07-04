#include "kemployeeregistration.h"
#include "ui_kemployeeregistration.h"

KEmployeeRegistration::KEmployeeRegistration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KEmployeeRegistration)
{
    ui->setupUi(this);
    ui->m_man_btn->setChecked(true);
    userservice = new KUserService;
}

KEmployeeRegistration::~KEmployeeRegistration()
{
    if(userservice != NULL)
        delete userservice;
    delete ui;
}

bool KEmployeeRegistration::judgeEmpty()
{
    if(ui->m_username_edit->text().isEmpty())
        return true;
    if(ui->m_password_edit->text().isEmpty())
        return true;
    if(ui->m_password_again_edit->text().isEmpty())
        return true;
    if(ui->m_name_edit->text().isEmpty())
        return true;
    if(ui->m_birthday_edit->text().isEmpty())
        return true;
    if(ui->m_phone_edit->text().isEmpty())
        return true;
    if(ui->m_address_edit->text().isEmpty())
        return true;
    if(ui->m_email_edit->text().isEmpty())
        return true;
    return false;
}

void KEmployeeRegistration::on_m_register_clicked()
{
    QString username = ui->m_username_edit->text();
    QString password = ui->m_password_edit->text();
    QString password_again = ui->m_password_again_edit->text();
    QString name = ui->m_name_edit->text();
    QString sex = ui->m_man_btn->isChecked() ? "1" : "2";
    QString birthday = ui->m_birthday_edit->text();
    QString phone_number = ui->m_phone_edit->text();
    QString address = ui->m_address_edit->text();
    QString email = ui->m_email_edit->text();
    if(password.compare(password_again) != 0)
    {
        QMessageBox::critical(this, "错误信息", "两次密码不一致", QMessageBox::Ok,QMessageBox::NoButton);
        return;
    }
    if(judgeEmpty())
    {
        QMessageBox::critical(this, "错误信息", "信息填写不完整", QMessageBox::Ok,QMessageBox::NoButton);
        return;
    }
    // TODO 参数校验
    QList<QString> list;
    list << username << password << name << phone_number << sex << birthday << address << email;
    UserRegisterTypeErr res = userservice->uregisterOrUpdate(list, INSERT);
    if(res == R_SUCCESS)
        QMessageBox::information(this, "消息", "账号成功！", QMessageBox::Ok,QMessageBox::NoButton);
}

