#include "kroominformation.h"
#include "ui_kRoominformation.h"

KRoomInformation::KRoomInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KInformationRegistration)
{
    ui->setupUi(this);
    ui->m_check_in->initPage();
    ui->m_check_out->initPage();
    ui->tabWidget->setCurrentIndex(0);
}

KRoomInformation::~KRoomInformation()
{
    delete ui;
}

void KRoomInformation::setGuestTableModel(QSqlTableModel *model)
{
    ui->m_check_search->setSqlTableModel(model);
    ui->m_check_search->initPage();
}

KRoomCheckIn *KRoomInformation::getRoomCheckIn()
{
    return ui->m_check_in;
}

KRoomCheckOut *KRoomInformation::getRoomCheckOut()
{
    return ui->m_check_out;
}
