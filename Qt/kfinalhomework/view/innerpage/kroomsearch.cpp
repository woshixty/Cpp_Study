#include "kroomsearch.h"
#include "ui_kroomsearch.h"

KRoomSearch::KRoomSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRoomSearch)
{
    ui->setupUi(this);
}

KRoomSearch::~KRoomSearch()
{
    delete ui;
}
