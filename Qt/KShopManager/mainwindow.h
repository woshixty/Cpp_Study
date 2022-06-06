#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QSqlError>
#include <QDataWidgetMapper>
#include <qabstractitemmodel.h>
#include <QSqlRecord>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void openDatabase();
    void  initTable();

private slots:
    void on_m_sider_clicked(const QModelIndex &index);
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);
    void on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_m_insert_product_btn_clicked();

    void on_m_save_product_btn_clicked();

    void on_m_product_category_currentIndexChanged(int index);

    void on_m_delete_product_btn_clicked();

private:
    Ui::MainWindow *ui;
    // 数据库连接
    QSqlDatabase m_db;
    // 数据模型
    QSqlTableModel *m_table_model;
    // 选择映射
    QItemSelectionModel *m_the_selection;
    // 数据映射
    QDataWidgetMapper *m_data_mapper;
};

#endif // MAINWINDOW_H
