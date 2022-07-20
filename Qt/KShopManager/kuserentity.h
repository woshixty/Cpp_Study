#ifndef KUSERENTITY_H
#define KUSERENTITY_H
#include <QString>

class UserEntity
{
public:
    QString getUsername() { return m_username; };
    QString getPassword() { return m_password; };
    void setUsername(QString username) { this->m_username = username; };
    void setpassword(QString password) { this->m_password = password; };

private:
    QString m_username;
    QString m_password;
};

#endif // KUSERENTITY_H
