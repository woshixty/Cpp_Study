#include "kemployeeinformation.h"
#include "ui_kemployeeinformation.h"

KEmployeeInformation::KEmployeeInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KEmployeeInformation)
{
    ui->setupUi(this);
    ui->pages->setCurrentIndex(0);
}

KEmployeeInformation::~KEmployeeInformation()
{
    delete ui;
}

void KEmployeeInformation::setUserTableModel(QSqlTableModel *model)
{
    ui->info_update->setUserTableModel(model);
}

void KEmployeeInformation::initPage()
{
    ui->info_update->initPage();
}
