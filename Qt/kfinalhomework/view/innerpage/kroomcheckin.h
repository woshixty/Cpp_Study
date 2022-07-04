#ifndef KROOMCHECKIN_H
#define KROOMCHECKIN_H

#include <QWidget>
#include <QMessageBox>
#include "service/kroomservice.h"

namespace Ui {
class KRoomCheckIn;
}

class KRoomCheckIn : public QWidget
{
    Q_OBJECT

public:
    explicit KRoomCheckIn(QWidget *parent = nullptr);
    ~KRoomCheckIn();
    void initPage();
    bool judgeEmpty();

private slots:
    void on_m_checkin_btn_clicked();
    void on_checkin_room_m();
    void on_checkout_room_m();

signals:
    void checkin();

private:
    Ui::KRoomCheckIn *ui;
    KRoomService *m_room_service;
    QList<QMap<QString, QString>> rooms;
};

#endif // KROOMCHECKIN_H
