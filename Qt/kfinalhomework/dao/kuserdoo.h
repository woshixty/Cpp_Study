#ifndef KUSERDOO_H
#define KUSERDOO_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <utils/kconstant.h>

class KUserDoo : public QObject
{
    Q_OBJECT
public:
    explicit KUserDoo(QObject *parent = nullptr);
    bool insertOUpdateUser(QMap<QString, QString> &user, ActionType type);
    bool checkLogin(const QString& username, const QString& password);

signals:

private:
    QSqlQuery *m_query;
    QSqlQueryModel *m_query_model;
};

#endif // KUSERDOO_H
