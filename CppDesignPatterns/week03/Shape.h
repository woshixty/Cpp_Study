//
// Created by 谢庭宇 on 2022/5/11.
//

#ifndef CPPDESIGNPATTERNS_SHAPE_H
#define CPPDESIGNPATTERNS_SHAPE_H

enum ShapeType {triangle, square, rectangle, trapezium, roundd, compoundshape};

void judgeType(ShapeType type);

class Shape {
public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual ShapeType type() const = 0;
};


#endif //CPPDESIGNPATTERNS_SHAPE_H
