#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "kmainwindow.h"
#include "service/kuserservice.h"
#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_loginBtn_clicked();

private:
    Ui::LoginWindow *ui;
    KUserService *m_userService;
};

#endif // LOGINWINDOW_H
