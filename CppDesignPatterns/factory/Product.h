//
// Created by 谢庭宇 on 2022/5/10.
//

#ifndef CPPDESIGNPATTERNS_PRODUCT_H
#define CPPDESIGNPATTERNS_PRODUCT_H


class Product {
public:
    virtual ~Product() = 0;

protected:
    // 屏蔽构造函数
    Product();
};

class ConcreteProduct : public Product {
public:
    ~ConcreteProduct();

    ConcreteProduct();
};


#endif //CPPDESIGNPATTERNS_PRODUCT_H
