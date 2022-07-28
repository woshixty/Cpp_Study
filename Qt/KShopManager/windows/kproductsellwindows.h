#ifndef KPRODUCTSELLWINDOWS_H
#define KPRODUCTSELLWINDOWS_H

#include <QWidget>
#include <QDateTime>
#include "service/kproductservice.h"
#include "entity/kproductentity.h"
#include "utils/ksnowflake.h"

namespace Ui {
class KProductSellWindows;
}

class KProductSellWindows : public QWidget
{
    Q_OBJECT

public:
    explicit KProductSellWindows(QWidget *parent = nullptr);
    ~KProductSellWindows();
    void initNameList();

private slots:

    void on_m_product_categorylist_currentIndexChanged(int index);

    void on_m_product_namelist_currentIndexChanged(int index);

    void on_m_product_number_tobuy_valueChanged(int arg1);

    void on_m_sell_btn_clicked();

    void on_m_buy_btn_clicked();

private:
    Ui::KProductSellWindows *ui;
    KProductService *m_product_service;
    QList<QMap<QString, QString>> m_product_list;
    QList<QMap<QString, QString>> m_product_sell_list;
    int m_curr_product_index;
    int m_total_money = 0;
};

#endif // KPRODUCTSELLWINDOWS_H
