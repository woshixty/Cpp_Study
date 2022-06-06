#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QtSql>
#include <QDataWidgetMapper>
#include "qwcomboboxdelegate.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //数据库连接
    QSqlDatabase DB;

    //数据模型
    QSqlTableModel *tabModel;

    //选择模型
    QItemSelectionModel *theSelection;

    //数据映射
    QDataWidgetMapper *dataMapper;

    //自定义数据代理，性别
    QWComboBoxDelegate delegateSex;

    //自定义数据代理，部门
    QWComboBoxDelegate delegateDepart;

    //打开数据表
    void openTable();

    //获取字段名称,填充“排序字段”的comboBox
    void getFieldNames();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

    // QTableView的SelectionModel的行发生了变化，进行处理
    void on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_actOpenDB_triggered();

    void on_actRecAppend_triggered();

    void on_actRecInsert_triggered();

    void on_actRevert_triggered();

    void on_actSubmit_triggered();

    void on_actRecDelete_triggered();

    void on_actPhoto_triggered();

    void on_actPhotoClear_triggered();

    void on_radioBtnAscend_clicked();

    void on_radioBtnDescend_clicked();

    void on_radioBtnMan_clicked();

    void on_radioBtnWoman_clicked();

    void on_radioBtnBoth_clicked();

    void on_comboFields_currentIndexChanged(int index);

    void on_actScan_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
