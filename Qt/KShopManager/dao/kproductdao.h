#ifndef KPRODUCTDAO_H
#define KPRODUCTDAO_H

#include <QObject>
#include "kconstant.h"
#include "kproductentity.h"

class KProductdao : public QObject
{
    Q_OBJECT
public:
    explicit KProductdao(QObject *parent = nullptr);

signals:

public:
    bool insertOUpdateProductdao(KProductentity const &product, ActionType type);
    bool deleteProductdao(int id);
    KProductentity selectProductdao(int id);
};

#endif // KPRODUCTDAO_H
