#ifndef KROOMCHECKOUT_H
#define KROOMCHECKOUT_H

#include <QWidget>
#include <QMessageBox>
#include "service/kroomservice.h"

namespace Ui {
class KRoomCheckOut;
}

class KRoomCheckOut : public QWidget
{
    Q_OBJECT

public:
    explicit KRoomCheckOut(QWidget *parent = nullptr);
    ~KRoomCheckOut();
    void initPage();
    bool judgeEmpty();

private slots:
    void on_checkin_room_m();
    void on_m_room_btn_clicked();

signals:
    void checkout_m();

private:
    Ui::KRoomCheckOut *ui;
    KRoomService *m_room_service;
    QList<QMap<QString, QString>> rooms;
};

#endif // KROOMCHECKOUT_H
