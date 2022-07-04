#ifndef KROOMINFORMATION_H
#define KROOMINFORMATION_H

#include <QWidget>
#include <QSqlTableModel>
#include "view/kroomstatus.h"
#include "view/innerpage/kroomcheckin.h"
#include "view/innerpage/kroomcheckout.h"

namespace Ui {
class KInformationRegistration;
}

class KRoomInformation : public QWidget
{
    Q_OBJECT

public:
    explicit KRoomInformation(QWidget *parent = nullptr);
    ~KRoomInformation();
    void setGuestTableModel(QSqlTableModel *model);
    KRoomCheckIn *getRoomCheckIn();
    KRoomCheckOut *getRoomCheckOut();

private:
    Ui::KInformationRegistration *ui;
};

#endif // KROOMINFORMATION_H
