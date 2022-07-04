#ifndef KROOMSTATUS_H
#define KROOMSTATUS_H

#include <QWidget>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QSqlRecord>
#include <QPushButton>

namespace Ui {
class KRoomStatus;
}

class KRoomStatus : public QWidget
{
    Q_OBJECT

public:
    explicit KRoomStatus(QWidget *parent = nullptr);
    ~KRoomStatus();
    void setTableModel(QSqlTableModel *model);
    void initPage();
    QPushButton *getTheButton(int roomid);

private slots:
    void on_m_101_clicked();
    void on_checkin_room();
    void on_checkout_room();

private:
    Ui::KRoomStatus *ui;
    QSqlTableModel *m_room_info_table_model;
    QItemSelectionModel *m_selection;
};

#endif // KROOMSTATUS_H
