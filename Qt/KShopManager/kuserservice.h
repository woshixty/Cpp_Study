#ifndef KUSERSERVICE_H
#define KUSERSERVICE_H

#include "kconstant.h"
#include "kuserdao.h"
#include <QObject>
#include <QString>
#include <QMap>

class KUserService : public QObject
{
    Q_OBJECT

public:
    explicit KUserService(QObject *parent = nullptr);
    ~KUserService();
    UserLoginTypeErr login(QString const &username, QString const &password);
    bool insertUser(QMap<QString, QString> const &user);
    bool deleteUser(QString const &username);
    bool updateUser(QMap<QString, QString> const &user);
signals:

private:
    // userDao
    KUserDAO *m_user_dao;
};

#endif // KUSERSERVICE_H
