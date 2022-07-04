#include "kuserservice.h"

KUserService::KUserService(QObject *parent)
    : QObject{parent}
{
    m_userdao = new KUserDoo;
}

KUserService::~KUserService()
{
    if(m_userdao != NULL)
        delete m_userdao;
}

UserRegisterTypeErr KUserService::uregisterOrUpdate(QList<QString> &user, ActionType type)
{
    int i = 0;
    QString id;
    if(type == UPDATE)
        id = user[i++];
    QString username = user[i++];
    QString password = user[i++];
    QString name = user[i++];
    QString phone_number = user[i++];
    QString sex = user[i++];
    QString birthday = user[i++];
    QString address = user[i++];
    QString email = user[i++];
//    QMap<QString, QString> record = m_userdao->selectUser(username);
//    if(record.contains(username))
//        return USER_EXIST;
    QMap<QString, QString> user_dao;
    user_dao.insert("id", id);
    user_dao.insert("username", username);
    user_dao.insert("password", password);
    user_dao.insert("name", name);
    user_dao.insert("phone_number", phone_number);
    user_dao.insert("sex", sex);
    user_dao.insert("birthday", birthday);
    user_dao.insert("address", address);
    user_dao.insert("email", email);
    if(m_userdao->insertOUpdateUser(user_dao, type))
        return R_SUCCESS;
    return R_ERR;
}

bool KUserService::login(const QString &username, const QString &password)
{
    return m_userdao->checkLogin(username, password);
}
