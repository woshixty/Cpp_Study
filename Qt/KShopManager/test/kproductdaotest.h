#ifndef KPRODUCTDAOTEST_H
#define KPRODUCTDAOTEST_H

#include <QObject>
#include <QTest>
#include "entity/kproductentity.h"
#include "dao/kproductdao.h"
#include "utils/kconstants.h"

class KProductDaoTest : public QObject
{
    Q_OBJECT
public:

signals:

private slots:
    void case1_update_or_insert();
    void case1_delete();
    void case1_select();
};

#endif // KPRODUCTDAOTEST_H
