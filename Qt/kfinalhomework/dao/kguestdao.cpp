#include "kguestdao.h"

KGuestDao::KGuestDao(QObject *parent)
    : QObject{parent}
{
    m_query = new QSqlQuery;
    m_query_model = new QSqlQueryModel;
}

KGuestDao::~KGuestDao()
{
    if(m_query != NULL)
        delete m_query;
}

bool KGuestDao::insertOneGuest(QMap<QString, QString> &guest)
{
    m_query->clear();
    QString sql;
    QString id = guest["id"];
    QString name = guest["name"];
    QString user_phone = guest["user_phone"];
    int user_room_number = guest["user_room_number"].toInt();
    QString user_status = guest["user_status"];
    QString user_permission = guest["user_permission"];
    QString user_check_in = guest["user_check_in"];
    sql = "INSERT INTO guest (id, name, user_phone, user_room_number, user_status, user_permission, user_check_in) VALUES (:ID, :N, :UPH, :URN, :US, :UP, :UCI)";
    m_query->prepare(sql);
    // (:ID, :N, :UP, :URN, US, :UP, :UCI)
    m_query->bindValue(":ID", id);
    m_query->bindValue(":N", name);
    m_query->bindValue(":UPH", user_phone);
    m_query->bindValue(":URN", user_room_number);
    m_query->bindValue(":US", user_status);
    m_query->bindValue(":UP", user_permission);
    m_query->bindValue(":UCI", user_check_in);
    m_query->exec();
    qDebug() << "bool KGuestDao::insertOneGuest：" << m_query->lastError();
    return m_query->isActive();
}

QList<QMap<QString, QString>> KGuestDao::selectRoomsByRoomStatus(QString status)
{
    m_query_model->clear();
    if(status.isNull())
        m_query_model->setQuery("SELECT * FROM room_info");
    else
        m_query_model->setQuery("SELECT * FROM room_info WHERE room_status = '" + status + "'");
    int rows = m_query_model->rowCount();
    QList<QMap<QString, QString>> res;
    for(int i = 0; i < rows; i++)
    {
        QSqlRecord record = m_query_model->record(i);
        QMap<QString, QString> rec;
        rec["id"] = record.value(0).toString();
        rec["room_status"] = record.value(1).toString();
        rec["guest_name"] = record.value(2).toString();
        rec["room_type"] = record.value(3).toString();
        res.append(rec);
    }
    return res;
}

QMap<QString, QString> KGuestDao::selectInRoomByroomid(int roomid)
{
    m_query_model->clear();
    QMap<QString, QString> res;
    QString sql = "SELECT * FROM guest WHERE user_status = '已入住' AND user_room_number = " + QString::number(roomid);
    m_query_model->setQuery(sql);
    if(m_query_model->rowCount() == 0)
        return res;
    QSqlRecord record = m_query_model->record(0);
    res["id"] = record.value(0).toString();
    res["name"] = record.value(1).toString();
    res["user_phone"] = record.value(2).toString();
    res["user_room_number"] = record.value(3).toString();
    res["user_status"] = record.value(4).toString();
    res["user_permission"] = record.value(5).toString();
    res["user_consume_money"] = record.value(6).toString();
    res["user_check_in"] = record.value(7).toString();
    res["user_check_out"] = record.value(8).toString();
    qDebug() << "1 bool KGuestDao::insertOneGuest：" << m_query->lastError();
    return res;
}

bool KGuestDao::updateGuestMoneyAndOutDate(double money, QString date, int roomid)
{
    m_query->clear();
    QString sql = "UPDATE guest SET user_status = '已退房', user_consume_money = " + QString::number(money) + ", user_check_out = '" + date + "' WHERE user_status = '已入住' AND user_room_number = " + QString::number(roomid);
    m_query->prepare(sql);
    m_query->exec();
    qDebug() << "bool KGuestDao::updateGuestMoneyAndOutDate" << m_query->lastError();
    return m_query->isActive();
}
