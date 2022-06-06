#ifndef KUSERSERVICE_H
#define KUSERSERVICE_H

#include <QObject>
#include <QString>
#include <QMap>
#include "utils/kconstants.h"
#include "dao/kuserdao.h"

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

public slots:

private:
    // userDao
    KUserDAO *m_user_dao;
};

#endif // KUSERSERVICE_H
