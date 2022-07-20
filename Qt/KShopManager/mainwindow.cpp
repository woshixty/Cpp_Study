#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tool/ktoolmethod.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->m_stacked_function->setCurrentIndex(1);
    openDatabase();
    initTable();
}

MainWindow::~MainWindow()
{
    if(m_table_model != nullptr)
        delete m_table_model;
    if(m_the_selection != nullptr)
        delete m_the_selection;
    if(m_data_mapper != nullptr)
        delete m_data_mapper;
    if(m_db.isOpen())
        m_db.close();
    delete ui;
}

void MainWindow::openDatabase()
{
    // 打开数据表
    QString aFile = "/Users/xietingyu/Desktop/Cpp_Study/Qt/KShopManager/kshoppingcentre.db3";
    // 添加 SQL LITE数据库驱动
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    // 设置数据库名称
    m_db.setDatabaseName(aFile);
    // 打开数据库
    if (!m_db.open())
    {
        QMessageBox::warning(this, "错误", "打开数据库失败", QMessageBox::Ok,QMessageBox::NoButton);
        return;
    }
}

void MainWindow::initTable()
{
    // 打开数据表
    m_table_model = new QSqlTableModel(this, m_db);
    // 设置数据表
    m_table_model->setTable("product");
    // 数据保存方式，OnManualSubmit , OnRowChange
    m_table_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 排序
    m_table_model->setSort(m_table_model->fieldIndex("id"),Qt::AscendingOrder);
    // 查询数据
    if (!(m_table_model->select()))
    {
       QMessageBox::critical(this, "错误信息", "打开数据表错误,错误信息\n" + m_table_model->lastError().text(), QMessageBox::Ok,QMessageBox::NoButton);
       return;
    }

    // 字段显示名
//    m_table_model->setHeaderData(m_table_model->fieldIndex("id"),Qt::Horizontal,"商品ID");
    m_table_model->setHeaderData(m_table_model->fieldIndex("name"),Qt::Horizontal,"商品名称");
//    不能直接映射
    m_table_model->setHeaderData(m_table_model->fieldIndex("category"),Qt::Horizontal,"商品类别");
    m_table_model->setHeaderData(m_table_model->fieldIndex("number"),Qt::Horizontal,"商品数量");
    m_table_model->setHeaderData(m_table_model->fieldIndex("purchase_price"),Qt::Horizontal,"商品进价");
    m_table_model->setHeaderData(m_table_model->fieldIndex("selling_price"),Qt::Horizontal,"商品售价");
    m_table_model->setHeaderData(m_table_model->fieldIndex("picture"),Qt::Horizontal,"商品图片");

    // 关联选择模型
    m_the_selection = new QItemSelectionModel(m_table_model);

    // m_the_selection当前项变化时触发currentChanged信号
    connect(m_the_selection, SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));
    // 选择行变化时
    connect(m_the_selection,SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentRowChanged(QModelIndex,QModelIndex)));

    // 设置只能选择行
    ui->m_table_product->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置数据模型
    ui->m_table_product->setModel(m_table_model);
    // 设置选择模型
    ui->m_table_product->setSelectionModel(m_the_selection);
    // 隐藏列
    ui->m_table_product->setColumnHidden(m_table_model->fieldIndex("picture"), true);
    ui->m_table_product->verticalHeader()->hide();
    ui->m_table_product->setColumnHidden(m_table_model->fieldIndex("id"), true);
    ui->m_table_product->verticalHeader()->hide();

    // TODO 2022 06 04 设置category、number、purchase_price、selling_price的自定义组件

    // 创建界面组件和数据模型之间的数据映射
    m_data_mapper = new QDataWidgetMapper();
    m_data_mapper->setModel(m_table_model);
    m_data_mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    // 界面组件和具体字段之间的联系
    m_data_mapper->addMapping(ui->m_product_name, m_table_model->fieldIndex("name"));
    m_data_mapper->addMapping(ui->m_product_category, m_table_model->fieldIndex("category"));
    m_data_mapper->addMapping(ui->m_product_number, m_table_model->fieldIndex("number"));
    m_data_mapper->addMapping(ui->m_product_purchase_price, m_table_model->fieldIndex("purchase_price"));
    m_data_mapper->addMapping(ui->m_product_selling_price, m_table_model->fieldIndex("selling_price"));
    // TODO 2022 06 04 照片映射

    // 移到首纪录
    m_data_mapper->toFirst();
    QSqlRecord rec = m_table_model->record(0);
    ui->m_product_category->setCurrentIndex(rec.value(2).toInt());
}

void MainWindow::on_m_sider_clicked(const QModelIndex &index)
{
    qDebug() << "index.row()" << index.row();
    qDebug() << "index.column()" << index.column();
    qDebug() << "index.data()" << index.data().toString();
    qDebug() << "index.parent().data()" << index.parent().data().toString();
//    int i = ui->m_stacked_function->currentIndex();
    //    ui->m_stacked_function->setCurrentIndex((i + 1) % 2);
}

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(current);
    Q_UNUSED(previous);
    if(m_table_model->isDirty())
    {
        ui->m_save_product_btn->styleSheet();
    }
    // TODO 2022 06 取消按钮的使能
}

void MainWindow::on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    qDebug() << "on_currentRowChanged";
    // 各个按钮的使能
    ui->m_delete_product_btn->setEnabled(current.isValid());
    ui->m_clear_product_btn->setEnabled(current.isValid());
    // 当前行号
    int curRecNum = current.row();
    // 更换数据映射的行号
    m_data_mapper->setCurrentIndex(curRecNum);
    // 更改category
    QSqlRecord rec = m_table_model->record(curRecNum);
    ui->m_product_category->setCurrentIndex(rec.value(2).toInt());
    // TODO 2022 06 显示图片
    // 获取当前纪录
    QSqlRecord curRecord = m_table_model->record(curRecNum);
    Q_UNUSED(curRecord);
}


void MainWindow::on_m_insert_product_btn_clicked()
{
    // 在末尾添加一个记录
    m_table_model->insertRow(m_table_model->rowCount(), QModelIndex());
    // 创建最后一行的ModelIndex
    QModelIndex curIndex = m_table_model->index(m_table_model->rowCount() - 1, 1);
    // 清空选择项
    m_the_selection->clearSelection();
    // 设置刚插入的行为当前选择行
    m_the_selection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
    // 获得当前行
//    int currow=curIndex.row();
//    // 自动生成编号
//    // 插入行时设置缺省值，需要在primeInsert()信号里去处理
}


void MainWindow::on_m_save_product_btn_clicked()
{
    //保存修改
    bool res = m_table_model->submitAll();
    if (!res)
        QMessageBox::information(this, "消息", "数据保存错误,错误信息\n" + m_table_model->lastError().text(), QMessageBox::Ok,QMessageBox::NoButton);
}


void MainWindow::on_m_product_category_currentIndexChanged(int index)
{
    // table中的种类和组件中的category相互转换
    QModelIndex table_index = ui->m_table_product->currentIndex();
    table_index = table_index.sibling(table_index.row(), 2);
    m_table_model->setData(table_index, index);
}


void MainWindow::on_m_delete_product_btn_clicked()
{
    // 获取当前选择单元格的模型索引
    QModelIndex curIndex = m_the_selection->currentIndex();
    // 删除当前记录
    m_table_model->removeRow(curIndex.row());
}

