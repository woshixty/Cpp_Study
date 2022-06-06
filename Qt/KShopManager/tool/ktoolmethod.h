#ifndef KTOOLMETHOD_H
#define KTOOLMETHOD_H

#include <QString>
#include "kconstant.h"

// enum ProductCategory {COMPUTER_C = 0, PHONE_C, FOOD_C, CLOTHING_C};
QString getProductCatogory(ProductCategory catogory)
{
    switch (catogory)
    {
    case COMPUTER_C:
        return "电脑办公";
    case PHONE_C:
        return "手机";
    case FOOD_C:
        return "食物";
    case CLOTHING_C:
        return "服饰";
    default :
        return "其他";
    }
}

#endif // KTOOLMETHOD_H
