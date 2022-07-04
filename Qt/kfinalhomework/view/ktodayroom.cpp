#include "ktodayroom.h"
#include "ui_ktodayroom.h"

KTodayRoom::KTodayRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KTodayRoom)
{
    ui->setupUi(this);
    ui->m_table_room_info->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

KTodayRoom::~KTodayRoom()
{
    delete ui;
}

void KTodayRoom::setTableModel(QSqlTableModel *model)
{
    m_room_table_model = model;
}

void KTodayRoom::initPage()
{
    // 字段显示名
    m_room_table_model->setHeaderData(m_room_table_model->fieldIndex("id"),Qt::Horizontal,"房间ID");
    m_room_table_model->setHeaderData(m_room_table_model->fieldIndex("room_type"),Qt::Horizontal,"房间类型");
    m_room_table_model->setHeaderData(m_room_table_model->fieldIndex("room_today_price"),Qt::Horizontal,"今日价格");
    m_room_table_model->setHeaderData(m_room_table_model->fieldIndex("room_normal_price"),Qt::Horizontal,"门市价格");
    m_room_table_model->setHeaderData(m_room_table_model->fieldIndex("room_vip_price"),Qt::Horizontal,"VIP价格");

    // 关联选择模型
    m_selection = new QItemSelectionModel(m_room_table_model);

    // 设置只能选择行
    ui->m_table_room_info->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置数据模型
    ui->m_table_room_info->setModel(m_room_table_model);
    // 设置选择模型
    ui->m_table_room_info->setSelectionModel(m_selection);

    // 隐藏列
    ui->m_table_room_info->setColumnHidden(m_room_table_model->fieldIndex("room_pix_map"), true);

    ui->m_table_room_info->resizeColumnsToContents();
}

void KTodayRoom::on_checkin_room_m()
{
    initPage();
}
