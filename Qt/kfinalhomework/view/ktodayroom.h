#ifndef KTODAYROOM_H
#define KTODAYROOM_H

#include <QWidget>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QItemSelectionModel>

namespace Ui {
class KTodayRoom;
}

class KTodayRoom : public QWidget
{
    Q_OBJECT

public:
    explicit KTodayRoom(QWidget *parent = nullptr);
    ~KTodayRoom();
    void setTableModel(QSqlTableModel *model);
    void initPage();

private slots:
    void on_checkin_room_m();

private:
    Ui::KTodayRoom *ui;
    QSqlTableModel *m_room_table_model;
    QItemSelectionModel *m_selection;
};

#endif // KTODAYROOM_H
