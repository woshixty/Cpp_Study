#include <QSqlField>
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>
#include "dao/kuserdao.h"

KUserDAO::KUserDAO(QObject *parent)
    : QObject{parent}
{
    QString aFile = "/Users/xietingyu/Desktop/Cpp_Study/Qt/KShopManager/kshoppingcentre.db3";
    if (!aFile.isEmpty()) {
        // 打开数据库
        // 添加 SQL LITE数据库驱动
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库名称
        m_db.setDatabaseName(aFile);
        // 打开数据库
        if (!m_db.open())
        {
            qDebug() << "数据库打开失败";
            QMessageBox::warning(NULL, "错误", "打开数据库失败", QMessageBox::Ok, QMessageBox::NoButton);
            return;
        }
    }
    m_query = new QSqlQuery();
    m_query_model = new QSqlQueryModel();
}

KUserDAO::~KUserDAO()
{
    if(m_query != NULL)
        delete m_query;
    if(m_query_model != NULL)
        delete m_query_model;
    if(m_db.isOpen())
        m_db.close();
}

bool KUserDAO::insertOUpdateUser(const QMap<QString, QString> &user, ActionType type)
{
    m_query->clear();
    QString sql;
    QString id = user["id"];
    QString username = user["username"];
    QString password = user["password"];
    // 先查询是更新还是插入
    switch (type) {
    case INSERT:
        sql = "INSERT INTO user (username, password) VALUES (:USERNAME, :PASSWORD)";
        break;
    case UPDATE:
        sql = "UPDATE user SET username=:USERNAME, password=:PASSWORD WHERE id = " + id;
        break;
    default:
        // 啥也不做
        break;
    }
    m_query->prepare(sql);
    m_query->bindValue(":USERNAME", username);
    m_query->bindValue(":PASSWORD", password);
//    m_query->bindValue(":ID", id.toInt());
    m_query->exec();
    return m_query->isActive();
}

bool KUserDAO::deleteUser(const QString &username)
{
    m_query->clear();
    QString sql = "DELETE FROM user WHERE username = :USERNAME";
    m_query->prepare(sql);
    m_query->bindValue(":USERNAME", username);
    m_query->exec();
    return m_query->isActive();
}

QMap<QString, QString> KUserDAO::selectUser(QString const &username)
{
    m_query_model->clear();
    QString sql = "SELECT id, username, password FROM user WHERE username = '" + username + "'";
    m_query_model->setQuery(sql);
    // qDebug() << "m_query_model->rowCount() : " << m_query_model->rowCount();
    QMap<QString, QString> result;
    for(int i = 0; i < m_query_model->rowCount(); i++)
    {
        QSqlRecord qrecord = m_query_model->record(i);
        // 注意顺序！
        result.insert(qrecord.field(1).value().toString(), qrecord.field(2).value().toString());
    }
    return result;
}
