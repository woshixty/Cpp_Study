//
// Created by 谢庭宇 on 2022/5/11.
// 长方形

#ifndef CPPDESIGNPATTERNS_RECTANGLE_H
#define CPPDESIGNPATTERNS_RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape{
private:
    double sideA, sideB, sideC;
public:
    Rectangle();
    // 使用工厂模式创建对象时判断三边是否正常
    Rectangle(double a, double b, double c);
    ~Rectangle();
    void setSides(double a, double b, double c);
    double perimeter() const override;
    double area() const override;
    ShapeType type() const override;
};


#endif //CPPDESIGNPATTERNS_RECTANGLE_H
