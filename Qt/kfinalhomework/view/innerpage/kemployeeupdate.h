#ifndef KEMPLOYEEUPDATE_H
#define KEMPLOYEEUPDATE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class KEmployeeUpdate;
}

class KEmployeeUpdate : public QWidget
{
    Q_OBJECT

public:
    explicit KEmployeeUpdate(QWidget *parent = nullptr);
    ~KEmployeeUpdate();
    void setUserTableModel(QSqlTableModel *model);
    void initPage();

private slots:
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);
    void on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);
    void on_m_update_clicked();

private:
    Ui::KEmployeeUpdate *ui;
    QSqlTableModel *m_user_table_model;
    // 数据映射
    QDataWidgetMapper *m_data_mapper;
    // 选择映射
    QItemSelectionModel *m_the_selection;
};

#endif // KEMPLOYEEUPDATE_H
