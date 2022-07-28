#ifndef KPRODUCTSERVICE_H
#define KPRODUCTSERVICE_H

#include <QObject>
#include <QList>
#include "dao/kproductdao.h"
#include "entity/kproductentity.h"

class KProductService : public QObject
{
    Q_OBJECT
public:
    explicit KProductService(QObject *parent = nullptr);
    QList<QMap<QString, QString>> selectProductList(int category);

signals:

public slots:

private:
    KProductDAO * productDao;
};

#endif // KPRODUCTSERVICE_H
