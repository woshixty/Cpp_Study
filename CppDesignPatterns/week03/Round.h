//
// Created by 谢庭宇 on 2022/5/11.
//

#ifndef CPPDESIGNPATTERNS_ROUND_H
#define CPPDESIGNPATTERNS_ROUND_H

#include "Shape.h"
#include <math.h>

#define PI acos(-1)

class Round : public Shape {
private:
    double radius;
public:
    Round();

    // 使用工厂模式创建对象时判断边是否为负数
    Round(double r);

    Round(Shape *shape);

    ~Round();

    double perimeter() const override;

    double area() const override;

    ShapeType type() const override;
};


#endif //CPPDESIGNPATTERNS_ROUND_H
