#include "kroomcheckout.h"
#include "ui_kroomcheckout.h"

KRoomCheckOut::KRoomCheckOut(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRoomCheckOut)
{
    ui->setupUi(this);
    m_room_service = new KRoomService;
    ui->m_check_out_time->setDateTime(QDateTime::currentDateTime());
}

KRoomCheckOut::~KRoomCheckOut()
{
    if(m_room_service != NULL)
        delete m_room_service;
    delete ui;
}

void KRoomCheckOut::initPage()
{
    rooms = m_room_service->selectRooms("已入住");
    QStringList list;
    for(int i = 0; i < rooms.size(); i++)
        list << rooms[i]["id"] + "-" + rooms[i]["room_type"];
    qDebug() << "void KRoomCheckIn::initPage():" << list.size();
    ui->m_room_box->clear();
    ui->m_room_box->addItems(list);
}

bool KRoomCheckOut::judgeEmpty()
{
    return false;
}

void KRoomCheckOut::on_checkin_room_m()
{
    initPage();
}

void KRoomCheckOut::on_m_room_btn_clicked()
{
    int index = ui->m_room_box->currentIndex();
    QMap<QString, QString> room = rooms[index];
    // 修改数据库信息
    QMap<QString, QString> guest = m_room_service->checkoutOneGuest(room["id"].toInt());
    // 弹窗
    QMessageBox::information(this, "提示信息", "退房成功", QMessageBox::Ok,QMessageBox::NoButton);
    // 修改页面信息
    initPage();
    emit checkout_m();
    // 显示信息
    QString text = "身份证号：" + guest["id"] + "\n"
            + "姓名：" + guest["name"] + "\n"
            + "手机号码：" + guest["user_phone"] + "\n"
            + "房间号：" + guest["user_room_number"] + "\n"
            + "入住情况：" + guest["user_status"] + "\n"
            + "用户权限：" + guest["user_permission"] + "\n"
            + "总房费：" + guest["user_consume_money"] + "\n"
            + "登记时间：" + guest["user_check_in"] + "\n"
            + "退房时间：" + guest["user_check_out"] + "\n";
    ui->m_text_info->setText(text);
}

