//
// Created by 谢庭宇 on 2022/5/11.
// 复合形状

#ifndef CPPDESIGNPATTERNS_COMPOUNDSHAPE_H
#define CPPDESIGNPATTERNS_COMPOUNDSHAPE_H

#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Trapezium.h"
#include "Round.h"
#include "Square.h"
#include <vector>

class Compoundshape : public Shape{
private:
    std::vector<Shape *> shapes;
public:
    ~Compoundshape();
    void addShape(Shape * shape);
    double perimeter() const override;
    double area() const override;
    ShapeType type() const override;
};


#endif //CPPDESIGNPATTERNS_COMPOUNDSHAPE_H
