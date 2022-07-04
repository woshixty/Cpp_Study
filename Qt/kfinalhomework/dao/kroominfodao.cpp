#include "kroominfodao.h"

KRoomInfoDao::KRoomInfoDao(QObject *parent)
    : QObject{parent}
{
    m_query = new QSqlQuery;
    m_query_model = new QSqlQueryModel;
}

KRoomInfoDao::~KRoomInfoDao()
{
    if(m_query != NULL)
        delete m_query;
    if(m_query_model != NULL)
        delete m_query_model;
}

bool KRoomInfoDao::checkinRoomInfo(int roomid, QString guesrname)
{
    m_query->clear();
    QString sql;
    sql = "UPDATE room_info SET room_status = '已入住', guest_name = '" + guesrname + "' WHERE id = " + QString::number(roomid);
    m_query->prepare(sql);
    m_query->exec();
    return m_query->isActive();
}

bool KRoomInfoDao::checkOutRoomInfo(int roomid)
{
    m_query->clear();
    QString sql = "UPDATE room_info SET room_status = '空房', guest_name = '无' WHERE id = " + QString::number(roomid);
    m_query->prepare(sql);
    m_query->exec();
    return m_query->isActive();
}

QMap<QString, QString> KRoomInfoDao::getRoomInfo(QString roomtype)
{
    m_query_model->clear();
    QString sql = "SELECT * FROM room WHERE room_type = '" + roomtype + "'";
    m_query_model->setQuery(sql);
    QMap<QString, QString> res;
    QSqlRecord record = m_query_model->record(0);
    res["id"] = record.value(0).toString();
    res["room_type"] = record.value(1).toString();
    res["room_today_price"] = record.value(2).toString();
    res["room_normal_price"] = record.value(3).toString();
    res["room_vip_price"] = record.value(4).toString();
    return res;
}

QMap<QString, QString> KRoomInfoDao::getSingleRoomInfo(int roomid)
{
    m_query_model->clear();
    QString sql = "SELECT * FROM room_info WHERE id = " + QString::number(roomid);
    m_query_model->setQuery(sql);
    QMap<QString, QString> res;
    QSqlRecord record = m_query_model->record(0);
    res["id"] = record.value(0).toString();
    res["room_status"] = record.value(1).toString();
    res["guest_name"] = record.value(2).toString();
    res["room_type"] = record.value(3).toString();
    return res;
}
