#ifndef KGUESTDAO_H
#define KGUESTDAO_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDateTime>

class KGuestDao : public QObject
{
    Q_OBJECT
public:
    explicit KGuestDao(QObject *parent = nullptr);
    ~KGuestDao();
    bool insertOneGuest(QMap<QString, QString> &guest);
    QList<QMap<QString, QString>> selectRoomsByRoomStatus(QString status);
    QMap<QString, QString> selectInRoomByroomid(int roomid);
    bool updateGuestMoneyAndOutDate(double money, QString date, int roomid);

signals:

private:
    QSqlQuery *m_query;
    QSqlQueryModel *m_query_model;
};

#endif // KGUESTDAO_H
