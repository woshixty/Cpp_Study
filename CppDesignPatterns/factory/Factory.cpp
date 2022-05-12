//
// Created by 谢庭宇 on 2022/5/10.
//

#include "Factory.h"
#include "Product.h"
#include <iostream>

using namespace std;

Factory::Factory() {

}

Factory::~Factory() {

}

ConcreteFactory::ConcreteFactory() {
    cout << "ConcreteFactory" << endl;
}

ConcreteFactory::~ConcreteFactory() {

}

Product *ConcreteFactory::CreateProduct() {
    return new ConcreteProduct();
}
