#include "mainwindow.h"
#include "windows/kloginwindow.h"
#include "test/kuserdaotest.h"
#include "test/kproductdaotest.h"
#include "test/ksingletontest.h"
#include <QApplication>
#include <QTest>

//QTEST_MAIN(UserDaoTest);

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);
    QApplication a(argc, argv);
    KLoginWindow *login = new KLoginWindow();
    if(login->exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
        return 0;

    // -----------------
//    MainWindow w;
//    w.show();
//    return a.exec();
    // -----------------
//     QTest::qExec(new KProductDaoTest, argc, argv);
}
