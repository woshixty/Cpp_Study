#include "kproductsellwindows.h"
#include "ui_kproductsellwindows.h"
#include "entity/kproductentity.h"

KProductSellWindows::KProductSellWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KProductSellWindows)
{
    ui->setupUi(this);
    m_product_service = new KProductService(this);
    // TODO 2022 06 07 考虑当前种类商品不存在的情况
    // 先默认为品类为其他的商品
    m_product_list = m_product_service->selectProductList(0);
    // 设置按钮
    ui->m_buy_btn->setEnabled(false);
    // 当前商品索引
    m_curr_product_index = 0;
    initNameList();
    // 未操作数据库提示
    ui->m_record->setText("由于时间原因\n此处的类别查询商品列表走数据库\n出售与下单操作未走数据库\n\n");
}

KProductSellWindows::~KProductSellWindows()
{
    delete ui;
}

void KProductSellWindows::initNameList()
{
    ui->m_product_namelist->clear();
    QList<QMap<QString, QString>>::Iterator it = m_product_list.begin();
    while(it != m_product_list.end())
    {
        ui->m_product_namelist->addItem((*it)["name"]);
        ++it;
    }
    // 设置当前索引值
    // TODO 2022 06 06 m_product_namelist为空
    // 设置购买数量最大值并重置为0
    ui->m_product_number_tobuy
            ->setMaximum(m_product_list.value(m_curr_product_index).value("number").toInt());
    ui->m_product_number_tobuy
            ->setValue(0);
    // 单价
    ui->m_product_price->setText(
                QString::number(m_product_list.value(m_curr_product_index).value("m_purchase_price").toDouble())
                );
    // 库存
    ui->m_product_number->setText(
                QString::number(m_product_list.value(m_curr_product_index).value("number").toInt())
                );
    // 总价
    ui->m_total_price->setText("0");
    // 当前商品索引
    m_curr_product_index = 0;
}


void KProductSellWindows::on_m_product_categorylist_currentIndexChanged(int index)
{
    // 当前商品索引
    m_curr_product_index = 0;
//    // 检索当前品类
    qDebug() << index;
    m_product_list.clear();
    if(m_product_service != nullptr)
        delete m_product_service;
    m_product_service = new KProductService(this);
    m_product_list = m_product_service->selectProductList(index);
    // 初始化列表
    initNameList();
}


void KProductSellWindows::on_m_product_namelist_currentIndexChanged(int index)
{
    // 当前商品索引
    m_curr_product_index = index;
    // 初始化列表
    // 设置购买数量最大值并重置为0
    ui->m_product_number_tobuy
            ->setMaximum(m_product_list.value(m_curr_product_index).value("number").toInt());
    ui->m_product_number_tobuy
            ->setValue(0);
    // 单价
    ui->m_product_price->setText(
                QString::number(m_product_list.value(m_curr_product_index).value("m_purchase_price").toDouble())
                );
    // 库存
    ui->m_product_number->setText(
                QString::number(m_product_list.value(m_curr_product_index).value("number").toInt())
                );
    // 总价
    ui->m_total_price->setText("0");
}


void KProductSellWindows::on_m_product_number_tobuy_valueChanged(int arg1)
{
    double total = m_product_list.value(m_curr_product_index).value("m_purchase_price").toDouble()
            * arg1;
    // 总价
    ui->m_total_price->setText(QString::number(total));
}


void KProductSellWindows::on_m_sell_btn_clicked()
{
    // TODO 2022 06 07 修改数据库逻辑之后加上
    if(ui->m_product_number_tobuy->value() == 0)
    {
        QMessageBox::warning(this, "出售数量为0！", "出售数量为0！");
        return;
    }
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->m_record->append(current_date + "   售出：" + m_product_list.value(m_curr_product_index).value("name"));
    ui->m_record->append("数量：" + QString::number(ui->m_product_number_tobuy->value())
                         + "    单价¥：" + ui->m_product_price->text()
                         + "   总价¥：" + ui->m_total_price->text() + "\n");

    // 纪录商品
    QMap<QString, QString> temp;
    temp.insert("name", m_product_list.value(m_curr_product_index).value("name"));
    temp.insert("number", ui->m_product_number->text());
    temp.insert("price", ui->m_product_price->text());
    temp.insert("total_price", ui->m_total_price->text());
    m_product_sell_list.append(temp);
    m_total_money += ui->m_total_price->text().toInt();


    // 库存变化
    int newNumber = ui->m_product_number->text().toInt() - ui->m_product_number_tobuy->value();
    ui->m_product_number->setText(QString::number(newNumber));
    // 设置出售数量最大值
    ui->m_product_number_tobuy->setMaximum(newNumber);

    // 设置按钮
    ui->m_buy_btn->setEnabled(true);
}


void KProductSellWindows::on_m_buy_btn_clicked()
{
    // TODO 2022 06 07 修改数据库逻辑之后加上
    // 设置按钮
    ui->m_buy_btn->setEnabled(false);
    // 向右边显示
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    KSnowFlake sf;
    struct timeval tv;
    ui->m_record->append("下单时间：" + current_date);
    ui->m_record->append("订单编号：" + QString::number(sf.getNextId(tv.tv_sec)));
    ui->m_record->append("付款总额¥：" + QString::number(m_total_money) + "\n");
    m_total_money = 0;
}

