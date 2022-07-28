#ifndef KUSERDAO_H
#define KUSERDAO_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "utils/kconstants.h"

class KUserDAO : public QObject
{
    Q_OBJECT

public:
    KUserDAO(QObject *parent = nullptr);
    ~KUserDAO();
    bool insertOUpdateUser(QMap<QString, QString> const &user, ActionType type);
    bool deleteUser(QString const &username);
    QMap<QString, QString> selectUser(QString const &username);
private:
    // 数据库连接
    QSqlDatabase m_db;
    QSqlQuery *m_query;
    QSqlQueryModel *m_query_model;
};


#endif // KUSERDAO_H
