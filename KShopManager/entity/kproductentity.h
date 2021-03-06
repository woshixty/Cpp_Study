#ifndef KPRODUCTENTITY_H
#define KPRODUCTENTITY_H

#include <QObject>

class KProductEntity : public QObject
{
    Q_OBJECT
public:
    explicit KProductEntity(QObject *parent = nullptr);
    void setId(int id);
    void setName(QString name);

signals:

private:
    int m_id;
    QString m_name;
    int m_category;
    int m_number;
    double m_purchase_price;
    double m_selling_price;
    // TODO 2022 06 03 图片存储类型先暂用QString
    QString picture;
};


#endif // KPRODUCTENTITY_H
