#include "kmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow login;
    login.show();
//    KMainWindow w;
//    w.show();

//    KTodayRoom p1;
//    p1.setTableModel(w.m_room_table_model);
//    p1.initPage();
//    p1.show();

//    KRoomStatus p2;
//    p2.setTableModel(w.m_room_info_table_model);
//    p2.initPage();
//    p2.show();

//    KEmployeeInformation p3;
//    p3.setUserTableModel(w.m_user_table_model);
//    p3.initPage();
//    p3.show();

//    KRoomInformation p4;
//    p4.show();

    return a.exec();
}
