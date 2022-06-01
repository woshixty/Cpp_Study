#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void displayDatabaseDriver();
    bool createTable(const QString &tablename);
    bool insertScore(const QStringList &record);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
};

#endif // MAINWINDOW_H
