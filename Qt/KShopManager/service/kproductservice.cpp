#include "kproductservice.h"

KProductService::KProductService(QObject *parent) : QObject(parent)
{
    productDao = new KProductDAO(this);
}

QList<QMap<QString, QString>> KProductService::selectProductList(int category)
{
    QList<QMap<QString, QString>> tempList = productDao->selectProductListByCategory(category);
    // TODO 2022 06 06 此处不知为何有误
//    QList<KProductEntity> res;
//    QList<QMap<QString, QString>>::Iterator it = tempList.begin();
//    while(it != tempList.end())
//    {
//        KProductEntity rec;
//        rec.setId((*it)["id"].toInt());
//        rec.setName((*it)["name"]);
//        rec.setCategary((*it)["category"].toInt());
//        rec.setNumber((*it)["number"].toInt());
//        rec.setPurchasePrice((*it)["m_purchase_price"].toDouble());
//        rec.setId((*it)["m_selling_price"].toDouble());
//        res.append(rec);
//        ++it;
//    }
    return tempList;
}
