//
// Created by 谢庭宇 on 2022/5/11.
//

#ifndef CPPDESIGNPATTERNS_BUILDER_H
#define CPPDESIGNPATTERNS_BUILDER_H

#include <string>

using namespace std;

class Product;

class Builder {
public:
    virtual ~Builder();

    virtual void BuildPartA(const string &buildPara) = 0;

    virtual void BuildPartB(const string &buildPara) = 0;

    virtual void BuildPartC(const string &buildPara) = 0;

    virtual Product *GetProduct() = 0;

protected:
    Builder();
};

class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder();

    ~ConcreteBuilder();

    void BuildPartA(const string &buildPara);

    void BuildPartB(const string &buildPara);

    void BuildPartC(const string &buildPara);

    Product *GetProduct();

protected:
private:
};

#endif //CPPDESIGNPATTERNS_BUILDER_H
