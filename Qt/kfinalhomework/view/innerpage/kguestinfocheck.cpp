#include "kguestinfocheck.h"
#include "ui_kguestinfocheck.h"

KGuestInfoCheck::KGuestInfoCheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KGuestInfoCheck)
{
    ui->setupUi(this);
    m_room_service = new KRoomService;
}

KGuestInfoCheck::~KGuestInfoCheck()
{
    if(m_room_service != NULL)
        delete m_room_service;
    delete ui;
}

void KGuestInfoCheck::initPage()
{
    rooms = m_room_service->selectRooms(NULL);
    QStringList list;
    for(int i = 0; i < rooms.size(); i++)
        list << rooms[i]["id"] + "-" + rooms[i]["room_type"];
    qDebug() << "void KRoomCheckIn::initPage():" << list.size();
    ui->m_room_list->clear();
    ui->m_room_list->addItems(list);

    if(m_guest_table_model == NULL)
        return;
    m_guest_table_model->select();

    // 字段显示名
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("id"),Qt::Horizontal,"ID");
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("name"),Qt::Horizontal,"姓名");
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("user_phone"),Qt::Horizontal,"手机号码");
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("user_room_number"),Qt::Horizontal,"房间号");
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("user_status"),Qt::Horizontal,"当前入住情况");
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("user_permission"),Qt::Horizontal,"用户身份");
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("user_consume_money"),Qt::Horizontal,"消费总额");
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("user_check_in"),Qt::Horizontal,"入住时间");
    m_guest_table_model->setHeaderData(m_guest_table_model->fieldIndex("user_check_out"),Qt::Horizontal,"退房时间");

    // 关联选择模型
    m_selection = new QItemSelectionModel(m_guest_table_model);

    // 设置只能选择行
    ui->m_table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置数据模型
    ui->m_table_view->setModel(m_guest_table_model);
    // 设置选择模型
    ui->m_table_view->setSelectionModel(m_selection);

    ui->m_table_view->resizeColumnsToContents();
}

void KGuestInfoCheck::setSqlTableModel(QSqlTableModel *model)
{
    m_guest_table_model = model;
    initPage();
}

void KGuestInfoCheck::on_m_search_roomid_clicked()
{
    int index = ui->m_room_list->currentIndex();
    m_guest_table_model->setFilter(QObject::tr("user_room_number = %1").arg(rooms[index]["id"]));
    m_guest_table_model->select();
}


void KGuestInfoCheck::on_m_search_name_clicked()
{
    QString name = ui->m_name_edit->text();
    qDebug() << "name：" << name;
    m_guest_table_model->setFilter(QObject::tr("name like '%%1%'").arg(name));
    m_guest_table_model->select();
}


void KGuestInfoCheck::on_m_search_btn_clicked()
{
    QString id = ui->m_idnumber_edit->text();
    qDebug() << "id：" << id;
    m_guest_table_model->setFilter(QObject::tr("id LIKE '%%1%'").arg(id));
    m_guest_table_model->select();
}

