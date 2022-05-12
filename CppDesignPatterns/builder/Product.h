//
// Created by 谢庭宇 on 2022/5/11.
//

#ifndef CPPDESIGNPATTERNS_PRODUCT_H
#define CPPDESIGNPATTERNS_PRODUCT_H


class Product {
public:
    Product();

    ~Product();

    void ProducePart();
};

class ProductPart {
public:
    ProductPart();

    ~ProductPart();

    ProductPart *BuildPart();
};


#endif //CPPDESIGNPATTERNS_PRODUCT_H
