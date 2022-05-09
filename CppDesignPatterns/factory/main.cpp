//
// Created by 谢庭宇 on 2022/5/10.
//

#include "Factory.h"
#include "Product.h"
#include <iostream>

using namespace std;

int main() {
    Factory* fac = new ConcreteFactory();
    Product* p = fac->CreateProduct();
    return 0;
}