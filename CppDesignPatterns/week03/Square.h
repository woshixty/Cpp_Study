//
// Created by 谢庭宇 on 2022/5/11.
//

#ifndef CPPDESIGNPATTERNS_SQUARE_H
#define CPPDESIGNPATTERNS_SQUARE_H

#include "Shape.h"

class Square : public Shape{
private:
    double side;
public:
    Square();
    // 使用工厂模式创建对象时判断边是否为负数
    Square(double s);
    Square(Shape *shape);
    ~Square();
    double perimeter() const override;
    double area() const override;
    ShapeType type() const override;
};


#endif //CPPDESIGNPATTERNS_SQUARE_H
