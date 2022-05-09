//
// Created by 谢庭宇 on 2022/5/10.
//

#ifndef CPPDESIGNPATTERNS_FACTORY_H
#define CPPDESIGNPATTERNS_FACTORY_H

class Product;

class Factory {
public:
    virtual ~Factory() = 0;
    virtual Product* CreateProduct() = 0;

protected:
    Factory();

private:
};

class ConcreteFactory:public Factory {
public:
    ~ConcreteFactory();
    ConcreteFactory();
    Product* CreateProduct();
};

#endif //CPPDESIGNPATTERNS_FACTORY_H
