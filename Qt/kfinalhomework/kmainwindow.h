#ifndef KMAINWINDOW_H
#define KMAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include "view/ktodayroom.h"
#include "view/kroomstatus.h"
#include "view/kroominformation.h"
#include "view/kemployeeinformation.h"
#include "view/innerpage/kemployeeregistration.h"
#include "view/loginwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class KMainWindow; }
QT_END_NAMESPACE

class KMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    KMainWindow(QWidget *parent = nullptr);
    ~KMainWindow();
    void initDataBase();
    void initQueryModel();

// private:
    // /Users/xietingyu/Desktop/kfinalhomework.db3
    Ui::KMainWindow *ui;
    QSqlDatabase m_db;
    QSqlQueryModel *m_query_model;
    QSqlTableModel *m_room_table_model;
    QSqlTableModel *m_room_info_table_model;
    QSqlTableModel *m_user_table_model;
    QSqlTableModel *m_guest_table_model;
private slots:
    void on_m_sider_clicked(const QModelIndex &index);
};
#endif // KMAINWINDOW_H
