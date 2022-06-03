#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

void MainWindow::openTable()
{
    //打开数据表
    tabModel = new QSqlTableModel(this, DB);
    //设置数据表
    tabModel->setTable("employee");
    //数据保存方式，OnManualSubmit , OnRowChange
    tabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //排序
    tabModel->setSort(tabModel->fieldIndex("empNo"),Qt::AscendingOrder);
    //查询数据
    if (!(tabModel->select()))
    {
        QMessageBox::critical(this, "错误信息", "打开数据表错误,错误信息\n" + tabModel->lastError().text(), QMessageBox::Ok,QMessageBox::NoButton);
        return;
    }

    //字段显示名
    tabModel->setHeaderData(tabModel->fieldIndex("empNo"),Qt::Horizontal,"工号");
    tabModel->setHeaderData(tabModel->fieldIndex("Name"),Qt::Horizontal,"姓名");
    tabModel->setHeaderData(tabModel->fieldIndex("Gender"),Qt::Horizontal,"性别");
    tabModel->setHeaderData(tabModel->fieldIndex("Height"),Qt::Horizontal,"身高");
    tabModel->setHeaderData(tabModel->fieldIndex("Birthday"),Qt::Horizontal,"出生日期");
    tabModel->setHeaderData(tabModel->fieldIndex("Mobile"),Qt::Horizontal,"手机");
    tabModel->setHeaderData(tabModel->fieldIndex("Province"),Qt::Horizontal,"省份");
    tabModel->setHeaderData(tabModel->fieldIndex("City"),Qt::Horizontal,"城市");
    tabModel->setHeaderData(tabModel->fieldIndex("Department"),Qt::Horizontal,"部门");
    tabModel->setHeaderData(tabModel->fieldIndex("Education"),Qt::Horizontal,"学历");
    tabModel->setHeaderData(tabModel->fieldIndex("Salary"),Qt::Horizontal,"工资");
    //这两个字段不再tableView中显示
    tabModel->setHeaderData(tabModel->fieldIndex("Memo"),Qt::Horizontal,"备注");
    tabModel->setHeaderData(tabModel->fieldIndex("Photo"),Qt::Horizontal,"照片");
    //关联选择模型
    theSelection=new QItemSelectionModel(tabModel);
    //theSelection当前项变化时触发currentChanged信号
    connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));
    //选择行变化时
    connect(theSelection,SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentRowChanged(QModelIndex,QModelIndex)));
    //设置数据模型
    ui->tableView->setModel(tabModel);
    //设置选择模型
    ui->tableView->setSelectionModel(theSelection);
    //隐藏列
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Memo"),true);
    //隐藏列
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Photo"),true);

    //tableView上为“性别”和“部门”两个字段设置自定义代理组件
    QStringList strList;
    strList<<"男"<<"女";
    bool isEditable=false;
    delegateSex.setItems(strList,isEditable);
    //Combbox选择型
    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Gender"),&delegateSex);

    strList.clear();
    strList<<"销售部"<<"技术部"<<"生产部"<<"行政部";
    isEditable=true;
    delegateDepart.setItems(strList,isEditable);
    //Combbox选择型
    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Department"),&delegateDepart);

    //创建界面组件与数据模型的字段之间的数据映射
    dataMapper= new QDataWidgetMapper();
    //设置数据模型
    dataMapper->setModel(tabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    //含有外键的
    //dataMapper->setItemDelegate(new QSqlRelationalDelegate(this));
    //界面组件与tabModel的具体字段之间的联系
    dataMapper->addMapping(ui->dbSpinEmpNo,tabModel->fieldIndex("empNo"));
    dataMapper->addMapping(ui->dbEditName,tabModel->fieldIndex("Name"));
    dataMapper->addMapping(ui->dbComboSex,tabModel->fieldIndex("Gender"));

    dataMapper->addMapping(ui->dbSpinHeight,tabModel->fieldIndex("Height"));
    dataMapper->addMapping(ui->dbEditBirth,tabModel->fieldIndex("Birthday"));
    dataMapper->addMapping(ui->dbEditMobile,tabModel->fieldIndex("Mobile"));

    dataMapper->addMapping(ui->dbComboProvince,tabModel->fieldIndex("Province"));
    dataMapper->addMapping(ui->dbEditCity,tabModel->fieldIndex("City"));
    dataMapper->addMapping(ui->dbComboDep,tabModel->fieldIndex("Department"));

    dataMapper->addMapping(ui->dbComboEdu,tabModel->fieldIndex("Education"));
    dataMapper->addMapping(ui->dbSpinSalary,tabModel->fieldIndex("Salary"));

    dataMapper->addMapping(ui->dbEditMemo,tabModel->fieldIndex("Memo"));

    //图片无法直接映射
    //dataMapper->addMapping(ui->dbPhoto,tabModel->fieldIndex("Photo"));

    //移动到首记录
    dataMapper->toFirst();

    //获取字段名称列表，填充ui->groupBoxSort组件
    getFieldNames();

    //更新actions和界面组件的使能状态
    ui->actOpenDB->setEnabled(false);

    ui->actRecAppend->setEnabled(true);
    ui->actRecInsert->setEnabled(true);
    ui->actRecDelete->setEnabled(true);
    ui->actScan->setEnabled(true);

    ui->groupBoxSort->setEnabled(true);
    ui->groupBoxFilter->setEnabled(true);
}

void MainWindow::getFieldNames()
{
    //获取所有字段名称
    //获取空记录，只有字段名
    QSqlRecord  emptyRec=tabModel->record();
    for (int i=0;i<emptyRec.count();i++)
        ui->comboFields->addItem(emptyRec.fieldName(i));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->splitter);

    //tableView显示属性设置
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);
    //ui->tableView->resizeColumnsToContents();
    //ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    //更新actPost和actCancel 的状态
    Q_UNUSED(current);
    Q_UNUSED(previous);
    //有未保存修改时可用
    ui->actSubmit->setEnabled(tabModel->isDirty());
    ui->actRevert->setEnabled(tabModel->isDirty());
}

void MainWindow::on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    // 行切换时的状态控制
    ui->actRecDelete->setEnabled(current.isValid());
    ui->actPhoto->setEnabled(current.isValid());
    ui->actPhotoClear->setEnabled(current.isValid());

    if (!current.isValid())
    {
        //清除图片显示
        ui->dbLabPhoto->clear();
        return;
    }

    //更细数据映射的行号
    dataMapper->setCurrentIndex(current.row());

    //获取行号
    int curRecNo=current.row();
    //获取当前记录
    QSqlRecord  curRec=tabModel->record(curRecNo);

    //图片字段内容为空
    if (curRec.isNull("Photo"))
        ui->dbLabPhoto->clear();
    else
    {
        QByteArray data=curRec.value("Photo").toByteArray();
        QPixmap pic;
        pic.loadFromData(data);
        ui->dbLabPhoto->setPixmap(pic.scaledToWidth(ui->dbLabPhoto->size().width()));
    }
}

void MainWindow::on_actOpenDB_triggered()
{
    //打开数据表
    QString aFile=QFileDialog::getOpenFileName(this,"选择数据库文件", "", "SQL Lite数据库(*.db *.db3)");
    //选择SQL Lite数据库文件
    if (aFile.isEmpty())
        return;

    //打开数据库
    //添加 SQL LITE数据库驱动
    DB=QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名称
    DB.setDatabaseName(aFile);
    //DB.setHostName();
    //DB.setUserName();
    //DB.setPassword();
    //打开数据库
    if (!DB.open())
    {
        QMessageBox::warning(this, "错误", "打开数据库失败", QMessageBox::Ok,QMessageBox::NoButton);
        return;
    }
    //打开数据表
    openTable();
}

void MainWindow::on_actRecAppend_triggered()
{
    //添加记录
    //在末尾添加一个记录
    tabModel->insertRow(tabModel->rowCount(),QModelIndex());
    //创建最后一行的ModelIndex
    QModelIndex curIndex=tabModel->index(tabModel->rowCount()-1,1);
    //清空选择项
    theSelection->clearSelection();
    //设置刚插入的行为当前选择行
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);

    //获得当前行
    int currow=curIndex.row();
    //自动生成编号
    tabModel->setData(tabModel->index(currow,0),2000+tabModel->rowCount());
    tabModel->setData(tabModel->index(currow,2),"男");
    //插入行时设置缺省值，需要在primeInsert()信号里去处理
}

void MainWindow::on_actRecInsert_triggered()
{
    //插入记录
    QModelIndex curIndex=ui->tableView->currentIndex();
    tabModel->insertRow(curIndex.row(),QModelIndex());
    //清除已有选择
    theSelection->clearSelection();
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}

void MainWindow::on_actRevert_triggered()
{
    //取消修改
    tabModel->revertAll();
    ui->actSubmit->setEnabled(false);
    ui->actRevert->setEnabled(false);
}

void MainWindow::on_actSubmit_triggered()
{
    //保存修改
    bool res=tabModel->submitAll();
    if (!res)
        QMessageBox::information(this, "消息", "数据保存错误,错误信息\n"+tabModel->lastError().text(), QMessageBox::Ok,QMessageBox::NoButton);
    else
    {
        ui->actSubmit->setEnabled(false);
        ui->actRevert->setEnabled(false);
    }
}

void MainWindow::on_actRecDelete_triggered()
{
    //删除当前记录
    //获取当前选择单元格的模型索引
    QModelIndex curIndex=theSelection->currentIndex();
    //删除最后一行
    tabModel->removeRow(curIndex.row());
}

void MainWindow::on_actPhoto_triggered()
{
    //设置照片
    QString aFile=QFileDialog::getOpenFileName(this,"选择图片文件","","照片(*.jpg)");
    if (aFile.isEmpty())
        return;

    QByteArray data;
    //fileName为二进制数据文件名
    QFile* file=new QFile(aFile);
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    file->close();

    int curRecNo=theSelection->currentIndex().row();
    //获取当前记录
    QSqlRecord  curRec=tabModel->record(curRecNo);
    //设置字段数据
    curRec.setValue("Photo",data);
    tabModel->setRecord(curRecNo,curRec);

    QPixmap pic;
    //在界面上显示
    pic.load(aFile);
    ui->dbLabPhoto->setPixmap(pic.scaledToWidth(ui->dbLabPhoto->width()));
}

void MainWindow::on_actPhotoClear_triggered()
{
    int curRecNo=theSelection->currentIndex().row();
    //获取当前记录
    QSqlRecord  curRec=tabModel->record(curRecNo);

    //设置为空值
    curRec.setNull("Photo");
    tabModel->setRecord(curRecNo,curRec);

    ui->dbLabPhoto->clear();
}

void MainWindow::on_radioBtnAscend_clicked()
{
    //升序
    tabModel->setSort(ui->comboFields->currentIndex(),Qt::AscendingOrder);
    tabModel->select();
}

void MainWindow::on_radioBtnDescend_clicked()
{
    //降序
    tabModel->setSort(ui->comboFields->currentIndex(),Qt::DescendingOrder);
    tabModel->select();
}

void MainWindow::on_radioBtnMan_clicked()
{
    tabModel->setFilter(" Gender='男' ");
    //tabModel->select();
}

void MainWindow::on_radioBtnWoman_clicked()
{
    tabModel->setFilter(" Gender='女' ");
    //=tabModel->select();
}

void MainWindow::on_radioBtnBoth_clicked()
{
    tabModel->setFilter("");
}

void MainWindow::on_comboFields_currentIndexChanged(int index)
{
    //选择字段进行排序
    if (ui->radioBtnAscend->isChecked())
        tabModel->setSort(index,Qt::AscendingOrder);
    else
        tabModel->setSort(index,Qt::DescendingOrder);
    tabModel->select();
}

void MainWindow::on_actScan_triggered()
{
    //涨工资，记录遍历
    if (tabModel->rowCount()==0)
        return;

    for (int i=0;i<tabModel->rowCount();i++)
    {
        //获取当前记录
        QSqlRecord aRec=tabModel->record(i);
        float salary=aRec.value("Salary").toFloat();
        salary=salary*1.1;
        aRec.setValue("Salary",salary);
        tabModel->setRecord(i,aRec);
    }

    //索引方式刷新记录,速度一样
    //    float   salary;
    //    for (int i=0;i<tabModel->rowCount();i++)
    //    {
    //        salary=tabModel->data(tabModel->index(i,10)).toFloat();
    //        salary=salary*1.1;
    //        tabModel->setData(tabModel->index(i,10),salary);
    //    }

    if (tabModel->submitAll())
        QMessageBox::information(this, "消息", "涨工资计算完毕", QMessageBox::Ok,QMessageBox::NoButton);
}
