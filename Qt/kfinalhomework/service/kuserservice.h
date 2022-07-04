#ifndef KUSERSERVICE_H
#define KUSERSERVICE_H

#include <QObject>
#include <utils/kconstant.h>
#include <dao/kuserdoo.h>

class KUserService : public QObject
{
    Q_OBJECT
public:
    explicit KUserService(QObject *parent = nullptr);
    ~KUserService();
    UserRegisterTypeErr uregisterOrUpdate(QList<QString> &user, ActionType type);
    bool login(const QString& username, const QString& password);

signals:

private:
    KUserDoo *m_userdao;
};

#endif // KUSERSERVICE_H
