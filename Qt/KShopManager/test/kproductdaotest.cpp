#include "kproductdaotest.h"

void KProductDaoTest::case1_update_or_insert()
{
    KProductEntity entity;
    entity.setId(9);
    entity.setName("Macbook Pro");
    entity.setCategary(1);
    entity.setNumber(109);
    entity.setPurchasePrice(9234.90);
    entity.setSellingPrice(10234.90);
    KProductDAO *dao = new KProductDAO();
    bool res;
    // 插入数据
    res = dao->insertOUpdateProductdao(entity, INSERT);
    QVERIFY(res == true);
    // 更新数据
    entity.setName("MacBookAir");
    res = dao->insertOUpdateProductdao(entity, UPDATE);
    QVERIFY(res == true);
}

void KProductDaoTest::case1_delete()
{
    KProductDAO *dao = new KProductDAO();
    bool res = dao->deleteProductdao(9);
    QVERIFY(res == true);
}

void KProductDaoTest::case1_select()
{
    KProductDAO *dao = new KProductDAO();
    KProductEntity res = dao->selectProductdao(1);
    QVERIFY(res.getNumber() == 100);
}
