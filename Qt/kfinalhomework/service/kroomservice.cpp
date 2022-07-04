#include "kroomservice.h"

KRoomService::KRoomService(QObject *parent)
    : QObject{parent}
{
    m_guest_dao = new KGuestDao;
    m_roominfo_dao = new KRoomInfoDao;
}

KRoomService::~KRoomService()
{
    if(m_guest_dao != NULL)
        delete m_guest_dao;
    if(m_roominfo_dao != NULL)
        delete m_roominfo_dao;
}

bool KRoomService::checkInRoom(QMap<QString, QString> &guest)
{
    bool f1 = m_guest_dao->insertOneGuest(guest);
    bool f2 = m_roominfo_dao->checkinRoomInfo(guest["user_room_number"].toInt(), guest["name"]);
    return f1 && f2;
}

QList<QMap<QString, QString>> KRoomService::selectRooms(QString str)
{
    return m_guest_dao->selectRoomsByRoomStatus(str);
}

QMap<QString, QString> KRoomService::checkoutOneGuest(int roomid)
{
    QMap<QString, QString> guest = m_guest_dao->selectInRoomByroomid(roomid);
    if(guest.size() == 0)
        return guest;
    //获取当前日期时间，为三个专用编辑器设置日期时间数据，并转换为字符串
    QDateTime outDate = QDateTime::currentDateTime();
    QDateTime inDate = QDateTime::fromString(guest["user_check_in"], "yyyy-MM-dd hh:mm:ss");

    qDebug() << "outDate" << outDate;
    qDebug() << "inDate" << inDate;

    int days = inDate.daysTo(outDate);

    QMap<QString, QString> room_info = m_roominfo_dao->getSingleRoomInfo(roomid);
    qDebug() << "room_info" << room_info;
    QMap<QString, QString> room = m_roominfo_dao->getRoomInfo(room_info["room_type"]);
    qDebug() << "room" << room;

    // 计算房费用
    double money = 0;
    if(days == 0)
        days++;
    if(guest["user_permission"].compare("普通") == 0)
        money = days * room["room_normal_price"].toDouble();
    else
        money = days * room["room_vip_price"].toDouble();

    // 返回信息更新
    guest["user_consume_money"] = QString::number(money);
    guest["user_check_out"] = outDate.toString("yyyy-MM-dd hh:mm:ss");

    // 更新guest
    m_guest_dao->updateGuestMoneyAndOutDate(money, outDate.toString("yyyy-MM-dd hh:mm:ss"), roomid);
    // 更新room_info
    m_roominfo_dao->checkOutRoomInfo(roomid);

    return guest;
}
