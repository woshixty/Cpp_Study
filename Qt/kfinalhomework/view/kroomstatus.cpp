#include "kroomstatus.h"
#include "ui_kroomstatus.h"

KRoomStatus::KRoomStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRoomStatus)
{
    ui->setupUi(this);
}

KRoomStatus::~KRoomStatus()
{
    delete ui;
}

void KRoomStatus::setTableModel(QSqlTableModel *model)
{
    m_room_info_table_model = model;
}

void KRoomStatus::initPage()
{
    m_room_info_table_model->select();
    int count = m_room_info_table_model->rowCount();
    for(int i = 0; i < count; ++i)
    {
        QSqlRecord record = m_room_info_table_model->record(i);
        QPushButton *btn = getTheButton(record.value(0).toInt());
        if(btn != NULL)
        {
            QString id = record.value(0).toString();
            QString status = record.value(1).toString();
            QString guest_name = record.value(2).toString();
            QString room_type = record.value(3).toString();
            if(status.compare("空房"))
            {
                btn->setText(id + "\n" + status + ": " + guest_name + "\n" + room_type);
                btn->setStyleSheet("background-color: rgb(230,230,230);"
                                                   "border-radius: 5px;"
                                                   "color: rgb(150, 150, 150);");
            }
            else
            {
                btn->setText(id + "\n" + status + "\n" + room_type);
                btn->setStyleSheet("background-color: white;"
                                                   "border-radius: 5px;"
                                                   "color: rgb(100, 100, 100);"
                                                   "border: 1px solid rgb(100, 100, 100);");
            }
        }
    }
}

QPushButton *KRoomStatus::getTheButton(int roomid)
{
    switch(roomid)
    {
    case 101:
        return ui->m_101;
    case 102:
        return ui->m_102;
    case 103:
        return ui->m_103;
    case 104:
        return ui->m_104;
    case 201:
        return ui->m_201;
    case 202:
        return ui->m_202;
    case 203:
        return ui->m_203;
    case 204:
        return ui->m_204;
    case 301:
        return ui->m_301;
    case 302:
        return ui->m_302;
    case 303:
        return ui->m_303;
    case 304:
        return ui->m_304;
    case 401:
        return ui->m_401;
    case 402:
        return ui->m_402;
    case 403:
        return ui->m_403;
    case 404:
        return ui->m_404;
    case 501:
        return ui->m_501;
    case 502:
        return ui->m_502;
    case 503:
        return ui->m_503;
    case 504:
        return ui->m_504;
    }
    return NULL;
}



void KRoomStatus::on_m_101_clicked()
{
    initPage();
}

void KRoomStatus::on_checkin_room()
{
    initPage();
    qDebug() << "void KRoomStatus::on_checkin_room()";
}

void KRoomStatus::on_checkout_room()
{
    initPage();
    qDebug() << "void KRoomStatus::on_checkout_room()";
}

