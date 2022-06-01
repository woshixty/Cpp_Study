#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayDatabaseDriver();
    // 1 加载数据库驱动
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    // 2 设置数据库名称
    m_db.setDatabaseName("student.db");
    // 3 打开数据库
    bool ok = m_db.open();
    if(ok) {
        qDebug() << m_db.lastError();
        return;
    }
    // 4 关闭数据库
    m_db.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayDatabaseDriver()
{
    foreach(QString dbDriverName,QSqlDatabase::drivers())
    {
        qDebug() << dbDriverName << "  ";
    }
}

bool MainWindow::createTable(const QString &tablename)
{
    bool ok;
    QSqlQuery query;
    QString sql = QString("CREATE TABLE IF NOT EXISTS %1(id INTEGER PRIMARY KEY, name TEXT NOT NULL, age INTEGER, score INTEGER)").arg(tablename);
    query.prepare(sql);
    ok = query.exec();
    if(!ok) {
        qDebug() << "[mainwindow::]: " << __FUNCTION__ << query.lastError().text();
        return false;
    }
    return true;
}

bool MainWindow::insertScore(const QStringList &record)
{
    bool ok;
    QString sql;
    QSqlQuery query;

    ok = m_db.open();
    if(!ok)
    {
        qDebug() << "[mainwindow::]: " << __FUNCTION__ << query.lastError().text();
        return false;
    }
    ok = createTable("students");
    if(!ok)
    {
        qDebug() << "[mainwindow::]: " << __FUNCTION__ << query.lastError().text();
        return false;
    }
    sql = "INSERT INTO students (name, age, score) VALUES (?,?,?);";
    query.prepare(sql);
    query.bindValue(0,record.at (0));
    query.bindValue(1,record.at(1).toInt());
    query.bindValue(2,record.at(2).toInt());
    ok = query.exec();
    if(!ok)
    {
        qDebug() << "[mainwindow::]: " << __FUNCTION__ << query.lastError().text();
        return false;
    }
    else
    {
        QMessageBox::information(NULL, "提示", "信息保存成功！");
    }
    m_db.close();
    return true;
}

void MainWindow::on_pushButton_clicked()
{
    QString name, age, score;
    QStringList infoList;

    name = ui->name->text();
    age = ui->age->text();
    score = ui->score->text();

    infoList << name << age << score;
    qDebug() << "[mainwindow::]: " << __FUNCTION__ << infoList;
    bool ok = insertScore(infoList);
    if(!ok)
    {
        qDebug() << "[mainwindow::]: " << __FUNCTION__ << "Error";
    }
}


