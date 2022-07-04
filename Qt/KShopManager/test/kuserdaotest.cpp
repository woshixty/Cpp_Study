#include "test/kuserdaotest.h"

void KUserDaoTest::case1_update_or_insert()
{
//    KUserDAO *userDao = KSingleton::instanceOfUserDao();
    KUserDAO *userDao = new KUserDAO();
    QMap<QString, QString> user;
    user.insert("username", "hhh");
    user.insert("password", "ooo");
    bool res = userDao->insertOUpdateUser(user, INSERT);
    QVERIFY(res);
}
