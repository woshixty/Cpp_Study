#include "kemployeeupdate.h"
#include "ui_kemployeeupdate.h"

KEmployeeUpdate::KEmployeeUpdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KEmployeeUpdate)
{
    ui->setupUi(this);
}

KEmployeeUpdate::~KEmployeeUpdate()
{
    if(m_data_mapper != NULL)
        delete m_data_mapper;
    delete ui;
}

void KEmployeeUpdate::setUserTableModel(QSqlTableModel *model)
{
    m_user_table_model = model;
}

void KEmployeeUpdate::initPage()
{
    m_user_table_model->select();
//    int rows = m_user_table_model->rowCount();
//    QStringList list;
//    for(int i = 0; i < rows; ++i)
//    {
//        QSqlRecord record = m_user_table_model->record(i);
//        QString name = record.value(3).toString();
//        list << name;
//    }
//    ui->m_employees->addItems(list);

    // 设置表头
    m_user_table_model->setHeaderData(m_user_table_model->fieldIndex("username"),Qt::Horizontal,"员工账号");
    m_user_table_model->setHeaderData(m_user_table_model->fieldIndex("name"),Qt::Horizontal,"员工姓名");
    m_user_table_model->setHeaderData(m_user_table_model->fieldIndex("phone_number"),Qt::Horizontal,"手机号码");
    m_user_table_model->setHeaderData(m_user_table_model->fieldIndex("birthday"),Qt::Horizontal,"生日");
    m_user_table_model->setHeaderData(m_user_table_model->fieldIndex("address"),Qt::Horizontal,"地址");
    m_user_table_model->setHeaderData(m_user_table_model->fieldIndex("email"),Qt::Horizontal,"邮箱");

    // 关联选择模型
    m_the_selection = new QItemSelectionModel(m_user_table_model);

    // 当前项变化时触发currentChanged信号
    connect(m_the_selection, SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));
    // 选择行变化时
    connect(m_the_selection,SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentRowChanged(QModelIndex,QModelIndex)));

    // 设置只能选择行
    ui->m_user_table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置数据模型
    ui->m_user_table_view->setModel(m_user_table_model);
    // 设置选择模型
    ui->m_user_table_view->setSelectionModel(m_the_selection);

    // 隐藏列
    ui->m_user_table_view->setColumnHidden(m_user_table_model->fieldIndex("id"), true);
    ui->m_user_table_view->setColumnHidden(m_user_table_model->fieldIndex("password"), true);
    ui->m_user_table_view->setColumnHidden(m_user_table_model->fieldIndex("sex"), true);

    // 创建界面组件和数据模型之间的数据映射
    m_data_mapper = new QDataWidgetMapper();
    m_data_mapper->setModel(m_user_table_model);
    m_data_mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    // 界面组件和具体字段之间的联系
    m_data_mapper->addMapping(ui->m_username_edit, m_user_table_model->fieldIndex("username"));
    m_data_mapper->addMapping(ui->m_password_edit, m_user_table_model->fieldIndex("password"));
    m_data_mapper->addMapping(ui->m_password_again_edit, m_user_table_model->fieldIndex("password"));
    m_data_mapper->addMapping(ui->m_name_edit, m_user_table_model->fieldIndex("name"));
    // 性别 TODO
    int index = m_user_table_model->fieldIndex("sex");
    int sexnumber = m_user_table_model->record(0).value(index).toInt();
    qDebug() << "sexnumber：" << sexnumber;
    sexnumber == 1 ? ui->m_man_btn->setChecked(true) : ui->m_woman_btn->setChecked(true);
    m_data_mapper->addMapping(ui->m_birthday_edit, m_user_table_model->fieldIndex("birthday"));
    m_data_mapper->addMapping(ui->m_phone_edit, m_user_table_model->fieldIndex("phone_number"));
    m_data_mapper->addMapping(ui->m_address_edit, m_user_table_model->fieldIndex("address"));
    m_data_mapper->addMapping(ui->m_email_edit, m_user_table_model->fieldIndex("email"));

    // 移到首纪录
    m_data_mapper->toFirst();
}

void KEmployeeUpdate::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(current);
    Q_UNUSED(previous);
}

void KEmployeeUpdate::on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    // 当前行号
    int curRecNum = current.row();
    // 更换数据映射的行号
    m_data_mapper->setCurrentIndex(curRecNum);
    // 更改category
//    QSqlRecord rec = m_user_table_model->record(curRecNum);
//    ui->m_employees->setCurrentIndex(rec.value(2).toInt());
    // 获取当前纪录
//    QSqlRecord curRec = m_user_table_model->record(curRecNum);
//    Q_UNUSED(curRec);
    // 更新数据映射的行号
    m_data_mapper->setCurrentIndex(current.row());
}

void KEmployeeUpdate::on_m_update_clicked()
{
    //保存修改
    bool ok = m_user_table_model->submitAll();
    if (!ok)
        QMessageBox::information(this, "消息", "数据保存错误,错误信息\n" + m_user_table_model->lastError().text(),
                                 QMessageBox::Ok,QMessageBox::NoButton);
    else
        QMessageBox::information(this, "消息", "数据保存成功！", QMessageBox::Ok,QMessageBox::NoButton);
}

