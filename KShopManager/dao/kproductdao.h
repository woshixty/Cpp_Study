#ifndef KPRODUCTDAO_H
#define KPRODUCTDAO_H

#include <QObject>
#include "utils/kconstants.h"
#include "entity/kproductentity.h"

class KProductDAO : public QObject
{
    Q_OBJECT
public:
    explicit KProductDAO(QObject *parent = nullptr);

signals:

public:
    bool insertOUpdateProductdao(KProductEntity const &product, ActionType type);
    bool deleteProductdao(int id);
    KProductEntity selectProductdao(int id);
};

#endif // KPRODUCTDAO_H
