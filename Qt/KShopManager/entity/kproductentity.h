#ifndef KPRODUCTENTITY_H
#define KPRODUCTENTITY_H

#include <QString>

class KProductEntity
{
public:
    KProductEntity() {}
    KProductEntity(KProductEntity &other)
    {
        m_id = other.m_id;
        m_name = other.m_name;
        m_category = other.m_category;
        m_number = other.m_number;
        m_purchase_price = other.m_purchase_price;
        m_selling_price = other.m_selling_price;
        picture = other.picture;
    }
    void setId(int id) {m_id = id;}
    void setName(QString name) {m_name = name;}
    void setCategary(int category) {m_category = category;}
    void setNumber(int number) {m_number = number;}
    void setPurchasePrice(double price) {m_purchase_price = price;}
    void setSellingPrice(double price) {m_selling_price = price;}
    int getId() {return m_id;}
    QString getName() {return m_name;}
    int getCategary() {return m_category;}
    int getNumber() {return m_number;}
    double getPurchasePrice() {return m_purchase_price;}
    double getSellingPrice() {return m_selling_price;}

private:
    int m_id;
    QString m_name;
    int m_category;
    int m_number;
    double m_purchase_price;
    double m_selling_price;
    // TODO 2022 06 03 图片存储类型先暂用QString
    QString picture = nullptr;
};


#endif // KPRODUCTENTITY_H
