#include "klogindialog.h"
#include "ui_klogindialog.h"

KLoginDialog::KLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KLoginDialog)
{
    ui->setupUi(this);
}

KLoginDialog::~KLoginDialog()
{
    delete ui;
}
