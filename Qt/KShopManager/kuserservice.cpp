#include "kuserservice.h"

KUserService::KUserService(QObject *parent)
    : QObject{parent}
{
    m_user_dao = new KUserDAO(this);
}

KUserService::~KUserService()
{
    if(m_user_dao != nullptr)
        delete m_user_dao;
}

UserLoginTypeErr KUserService::login(const QString &username, const QString &password)
{
    QMap<QString, QString> record = m_user_dao->selectUser(username);
    if(!record.contains(username))
        return USER_NULL;
    if(record[username].compare(password) != 0)
        return PASSWORD_ERR;
    return SUCCESS;
}

bool KUserService::insertUser(const QMap<QString, QString> &user)
{
    return m_user_dao->insertOUpdateUser(user, INSERT);
}

bool KUserService::deleteUser(const QString &username)
{
    return m_user_dao->deleteUser(username);
}

bool KUserService::updateUser(const QMap<QString, QString> &user)
{
    return m_user_dao->insertOUpdateUser(user, UPDATE);
}
