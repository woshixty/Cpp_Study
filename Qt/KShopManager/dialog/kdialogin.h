#ifndef KDIALOGIN_H
#define KDIALOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "kuserservice.h"
#include "kconstant.h"

namespace Ui {
class KDialogin;
}

class KDialogin : public QDialog
{
    Q_OBJECT

public:
    explicit KDialogin(QWidget *parent = nullptr);
    ~KDialogin();

private slots:
    void on_m_login_btn_clicked();

private:
    Ui::KDialogin *ui;
    KUserService *m_user_service;
};

#endif // KDIALOGIN_H
