#ifndef KPRODUCTMANAGERWINDOW_H
#define KPRODUCTMANAGERWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QSqlError>
#include <QDataWidgetMapper>
#include <qabstractitemmodel.h>
#include <QSqlRecord>
#include <QFileDialog>
#include "delegate/kcategorydelegate.h"

namespace Ui {
class KProductManagerWindow;
}

class KProductManagerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit KProductManagerWindow(QWidget *parent = nullptr);
    ~KProductManagerWindow();
    void openDatabase();
    void initTable();

private slots:
    void on_m_sider_clicked(const QModelIndex &index);
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);
    void on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_m_insert_product_btn_clicked();

    void on_m_save_product_btn_clicked();

    void on_m_product_category_currentIndexChanged(int index);

    void on_m_delete_product_btn_clicked();

    void on_m_setpic_btn_clicked();

private:
    Ui::KProductManagerWindow *ui;
    // 数据库连接
    QSqlDatabase m_db;
    // 数据模型
    QSqlTableModel *m_table_model;
    // 选择映射
    QItemSelectionModel *m_the_selection;
    // 数据映射
    QDataWidgetMapper *m_data_mapper;
    // 自定义代理
    KCategoryDelegate m_category_delegate;
};

#endif // KPRODUCTMANAGERWINDOW_H
