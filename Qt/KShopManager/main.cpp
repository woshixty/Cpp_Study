#include "mainwindow.h"
#include "kuserdao.h"
#include "kuserservice.h"
#include "dialog/kdialogin.h"
#include "test/kuserdaotest.h"
#include <QApplication>
#include <QTest>
#include <QMap>
#include <QString>

//QTEST_MAIN(UserDaoTest);

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);
    QApplication a(argc, argv);
//    KDialogin *login = new KDialogin();
//    if(login->exec() == QDialog::Accepted)
//    {
//        MainWindow w;
//        w.show();
//        return a.exec();
//    }
//    else
//        return 0;
    MainWindow w;
    w.show();
    return a.exec();
//    KUserService service;
//    QMap<QString, QString> user;
//    user.insert("id", "8");
//    user.insert("username", "hello1");
//    user.insert("password", "world");
//    qDebug() << service.insertUser(user);
//    user["username"] = "abcd";
//    user["password"] = "abcd";
//    qDebug() << service.updateUser(user);
    // QTest::qExec(new UserDaoTest, argc, argv);
}
