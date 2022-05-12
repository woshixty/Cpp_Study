//
// Created by 谢庭宇 on 2022/5/11.
// 长方形

#ifndef CPPDESIGNPATTERNS_RECTANGLE_H
#define CPPDESIGNPATTERNS_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle();

    // 使用工厂模式创建对象时判断边是否正常
    Rectangle(double l, double w);

    Rectangle(Shape *shape);

    ~Rectangle();

    double perimeter() const override;

    double area() const override;

    ShapeType type() const override;
};


#endif //CPPDESIGNPATTERNS_RECTANGLE_H
