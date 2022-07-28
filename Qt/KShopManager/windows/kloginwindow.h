#ifndef KLOGINWINDOW_H
#define KLOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "service/kuserservice.h"
#include "utils/kconstants.h"

namespace Ui {
class KLoginWindow;
}

class KLoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit KLoginWindow(QWidget *parent = nullptr);
    ~KLoginWindow();

private slots:
    void on_m_login_btn_clicked();

    void on_m_register_btn_clicked();


private:
    Ui::KLoginWindow *ui;
    KUserService *m_user_service;
};


#endif // KLOGINWINDOW_H
