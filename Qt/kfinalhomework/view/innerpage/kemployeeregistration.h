#ifndef KEMPLOYEEREGISTRATION_H
#define KEMPLOYEEREGISTRATION_H

#include <QWidget>
#include <QMessageBox>
#include "service/kuserservice.h"
#include "utils/kconstant.h"

namespace Ui {
class KEmployeeRegistration;
}

class KEmployeeRegistration : public QWidget
{
    Q_OBJECT

public:
    explicit KEmployeeRegistration(QWidget *parent = nullptr);
    ~KEmployeeRegistration();
    bool judgeEmpty();

private slots:
    void on_m_register_clicked();

private:
    Ui::KEmployeeRegistration *ui;
    KUserService *userservice;
};

#endif // KEMPLOYEEREGISTRATION_H
