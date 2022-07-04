#include "kuserdoo.h"

KUserDoo::KUserDoo(QObject *parent)
    : QObject{parent}
{
    m_query = new QSqlQuery();
    m_query_model = new QSqlQueryModel();
}

bool KUserDoo::insertOUpdateUser(QMap<QString, QString> &user, ActionType type)
{
    m_query->clear();
    QString sql;
    QString id = user["id"];
    QString username = user["username"];
    QString password = user["password"];
    QString name = user["name"];
    QString phone_number = user["phone_number"];
    int sex = user["sex"].toInt();
    QString birthday = user["birthday"];
    QString address = user["address"];
    QString email = user["email"];
    // 先查询是更新还是插入
    switch (type) {
    case INSERT:
        sql = "INSERT INTO user (username, password, name, phone_number, sex, birthday, address, email) VALUES (:UN, :PD, :N, :PN, :S, :BIR, :ADD, :EM)";
        break;
    case UPDATE:
        sql = "UPDATE user SET username = :UN, password = :PD, name = :N, phone_number = :PN, sex = :S, birthday = :BIR, address = :ADD, email= :EM WHERE id = " + id;
        break;
    default:
        // 啥也不做
        break;
    }
    m_query->prepare(sql);
    m_query->bindValue(":UN", username);
    m_query->bindValue(":PD", password);
    m_query->bindValue(":N", name);
    m_query->bindValue(":PN", phone_number);
    m_query->bindValue(":S", sex);
    m_query->bindValue(":BIR", birthday);
    m_query->bindValue(":ADD", address);
    m_query->bindValue(":EM", email);
    m_query->exec();
    qDebug() << m_query->lastError();
    return m_query->isActive();
}

bool KUserDoo::checkLogin(const QString &username, const QString &password)
{
    return true;
}
