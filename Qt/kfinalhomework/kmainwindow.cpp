#include "kmainwindow.h"
#include "ui_kmainwindow.h"

KMainWindow::KMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KMainWindow)
{
    ui->setupUi(this);
    initDataBase();
    initQueryModel();
    KTodayRoom *todayRoom = new KTodayRoom(this);
    todayRoom->setTableModel(m_room_table_model);
    todayRoom->initPage();
    ui->m_stack_pages->insertWidget(0, todayRoom);

    KRoomStatus *rooStatus = new KRoomStatus(this);
    rooStatus->setTableModel(m_room_info_table_model);
    rooStatus->initPage();
    ui->m_stack_pages->insertWidget(1, rooStatus);

    KRoomInformation *roomInfomation = new KRoomInformation(this);
    roomInfomation->setGuestTableModel(m_guest_table_model);
    ui->m_stack_pages->insertWidget(2, roomInfomation);

    KEmployeeInformation *employeeInformation = new KEmployeeInformation(this);
    employeeInformation->setUserTableModel(m_user_table_model);
    employeeInformation->initPage();
    ui->m_stack_pages->insertWidget(3, employeeInformation);

    ui->m_stack_pages->setCurrentIndex(0);
    connect(roomInfomation->getRoomCheckIn(), SIGNAL(checkin()), rooStatus, SLOT(on_checkin_room()), Qt::QueuedConnection);
    connect(roomInfomation->getRoomCheckIn(), SIGNAL(checkin()), roomInfomation->getRoomCheckOut(), SLOT(on_checkin_room_m()), Qt::QueuedConnection);

    connect(roomInfomation->getRoomCheckOut(), SIGNAL(checkout_m()), rooStatus, SLOT(on_checkout_room()), Qt::QueuedConnection);
    connect(roomInfomation->getRoomCheckOut(), SIGNAL(checkout_m()), roomInfomation->getRoomCheckIn(), SLOT(on_checkout_room_m()), Qt::QueuedConnection);
}

KMainWindow::~KMainWindow()
{
    delete ui;
}

void KMainWindow::initDataBase()
{
    bool ok;
    QString database = "/Users/xietingyu/Desktop/kfinalhomework.db3";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(database);

    ok = m_db.open();
    if(!ok)
    {
        qDebug() << "[KDataBase::initDataBase]:: " << m_db.lastError().text();
        return;
    }
    // 创建表等等
}

void KMainWindow::initQueryModel()
{
    // 打开数据表
    m_room_table_model = new QSqlTableModel(this, m_db);
    // 设置数据表
    m_room_table_model->setTable("room");
    // 数据保存方式，OnManualSubmit , OnRowChange
    m_room_table_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 排序
    m_room_table_model->setSort(m_room_table_model->fieldIndex("id"),Qt::AscendingOrder);
    // 查询数据
    if (!(m_room_table_model->select()))
    {
       QMessageBox::critical(this, "错误信息", "打开数据表错误,错误信息\n" + m_room_table_model->lastError().text(), QMessageBox::Ok,QMessageBox::NoButton);
       return;
    }

    // 打开数据表
    m_room_info_table_model = new QSqlTableModel(this, m_db);
    // 设置数据表
    m_room_info_table_model->setTable("room_info");
    // 数据保存方式，OnManualSubmit , OnRowChange
    m_room_info_table_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 排序
    m_room_info_table_model->setSort(m_room_info_table_model->fieldIndex("id"),Qt::AscendingOrder);
    // 查询数据
    if (!(m_room_info_table_model->select()))
    {
       QMessageBox::critical(this, "错误信息", "打开数据表错误,错误信息\n" + m_room_info_table_model->lastError().text(), QMessageBox::Ok,QMessageBox::NoButton);
       return;
    }

    // 打开数据表
    m_user_table_model = new QSqlTableModel(this, m_db);
    // 设置数据表
    m_user_table_model->setTable("user");
    // 数据保存方式，OnManualSubmit , OnRowChange
    m_user_table_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 排序
    m_user_table_model->setSort(m_user_table_model->fieldIndex("id"),Qt::AscendingOrder);
    // 查询数据
    if (!(m_user_table_model->select()))
    {
       QMessageBox::critical(this, "错误信息", "打开数据表错误,错误信息\n" + m_user_table_model->lastError().text(), QMessageBox::Ok,QMessageBox::NoButton);
       return;
    }

    // 打开数据表
    m_guest_table_model = new QSqlTableModel(this, m_db);
    // 设置数据表
    m_guest_table_model->setTable("guest");
    // 数据保存方式，OnManualSubmit , OnRowChange
    m_guest_table_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 排序
    m_guest_table_model->setSort(m_guest_table_model->fieldIndex("id"),Qt::AscendingOrder);
    // 查询数据
    if (!(m_guest_table_model->select()))
    {
       QMessageBox::critical(this, "错误信息", "打开数据表错误,错误信息\n" + m_guest_table_model->lastError().text(), QMessageBox::Ok,QMessageBox::NoButton);
       return;
    }
}


void KMainWindow::on_m_sider_clicked(const QModelIndex &index)
{
    QString tagName = index.data().toString();
    if(tagName.compare("今日价格信息") == 0)
        ui->m_stack_pages->setCurrentIndex(0);
    else if(tagName.compare("客房信息查询") == 0)
        ui->m_stack_pages->setCurrentIndex(1);
    else if(tagName.compare("客房信息登记") == 0)
        ui->m_stack_pages->setCurrentIndex(2);
    else if(tagName.compare("员工信息录入") == 0)
        ui->m_stack_pages->setCurrentIndex(3);
}

