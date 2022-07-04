#ifndef KROOMINFODAO_H
#define KROOMINFODAO_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

class KRoomInfoDao : public QObject
{
    Q_OBJECT
public:
    explicit KRoomInfoDao(QObject *parent = nullptr);
    ~KRoomInfoDao();
    bool checkinRoomInfo(int roomid, QString guesrname);
    bool checkOutRoomInfo(int roomid);
    QMap<QString, QString> getRoomInfo(QString roomtype);
    QMap<QString, QString> getSingleRoomInfo(int roomid);

signals:

private:
    QSqlQuery *m_query;
    QSqlQueryModel *m_query_model;
};

#endif // KROOMINFODAO_H
