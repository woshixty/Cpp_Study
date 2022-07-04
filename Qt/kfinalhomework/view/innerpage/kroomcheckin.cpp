#include "kroomcheckin.h"
#include "ui_kroomcheckin.h"

KRoomCheckIn::KRoomCheckIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRoomCheckIn)
{
    ui->setupUi(this);
    m_room_service = new KRoomService;
    ui->m_check_in_time->setDateTime(QDateTime::currentDateTime());
}

KRoomCheckIn::~KRoomCheckIn()
{
    if(m_room_service != NULL)
        delete m_room_service;
    delete ui;
}

void KRoomCheckIn::initPage()
{
    rooms = m_room_service->selectRooms("空房");
    QStringList list;
    for(int i = 0; i < rooms.size(); i++)
        list << rooms[i]["id"] + "-" + rooms[i]["room_type"];
    qDebug() << "void KRoomCheckIn::initPage():" << list.size();
    ui->m_room_box->clear();
    ui->m_room_box->addItems(list);
}

bool KRoomCheckIn::judgeEmpty()
{
    return false;
}

void KRoomCheckIn::on_m_checkin_btn_clicked()
{
    QMap<QString, QString> guest;
    guest["id"] = ui->m_id_edit->text();
    guest["name"] = ui->m_name_edit->text();
    guest["user_phone"] = ui->m_phone_edit->text();
    guest["user_room_number"] = ui->m_room_box->currentText().split("-")[0];
    guest["user_status"] = "已入住";
    if(ui->m_normal_button->isChecked())
        guest["user_permission"] = "普通";
    else
        guest["user_permission"] = "VIP";
    guest["user_check_in"] = ui->m_check_in_time->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    bool ok = m_room_service->checkInRoom(guest);
    if(ok)
    {
        QMessageBox::information(this, "提示信息", "登记成功", QMessageBox::Ok,QMessageBox::NoButton);
        // 发送信号到room info
        emit checkin();
        // 初始化房间列表
        initPage();
        // 清空信息
        ui->m_name_edit->clear();
        ui->m_id_edit->clear();
        ui->m_phone_edit->clear();
        ui->m_phone_edit->clear();
        ui->m_normal_button->setChecked(true);
        // 设置新时间
        ui->m_check_in_time->setDateTime(QDateTime::currentDateTime());
    }
    else
        QMessageBox::information(this, "提示信息", "登记失败", QMessageBox::Ok,QMessageBox::NoButton);
}

void KRoomCheckIn::on_checkin_room_m()
{
    initPage();
}

void KRoomCheckIn::on_checkout_room_m()
{
    initPage();
}

