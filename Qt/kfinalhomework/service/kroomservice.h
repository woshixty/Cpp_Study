#ifndef KROOMSERVICE_H
#define KROOMSERVICE_H

#include <QObject>
#include <dao/kguestdao.h>
#include "dao/kroominfodao.h"

class KRoomService : public QObject
{
    Q_OBJECT
public:
    explicit KRoomService(QObject *parent = nullptr);
    ~KRoomService();
    bool checkInRoom(QMap<QString, QString> &guest);
    QList<QMap<QString, QString>> selectRooms(QString str);
    QMap<QString, QString> checkoutOneGuest(int roomid);
    QMap<QString, QString> getRoomInfo(QString roomtype);

signals:

private:
    KGuestDao *m_guest_dao;
    KRoomInfoDao *m_roominfo_dao;
};

#endif // KROOMSERVICE_H
