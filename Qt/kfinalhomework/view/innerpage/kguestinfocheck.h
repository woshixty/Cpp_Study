#ifndef KGUESTINFOCHECK_H
#define KGUESTINFOCHECK_H

#include <QWidget>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include "service/kroomservice.h"

namespace Ui {
class KGuestInfoCheck;
}

class KGuestInfoCheck : public QWidget
{
    Q_OBJECT

public:
    explicit KGuestInfoCheck(QWidget *parent = nullptr);
    ~KGuestInfoCheck();
    void initPage();
    void setSqlTableModel(QSqlTableModel *model);

private slots:
    void on_m_search_roomid_clicked();

    void on_m_search_name_clicked();

    void on_m_search_btn_clicked();

private:
    Ui::KGuestInfoCheck *ui;
    KRoomService *m_room_service;
    QList<QMap<QString, QString>> rooms;
    QSqlTableModel *m_guest_table_model;
    QItemSelectionModel *m_selection;
};

#endif // KGUESTINFOCHECK_H
