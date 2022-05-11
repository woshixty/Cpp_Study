//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Square.h"

Square::Square() : side(0.0){}

Square::Square(double s) : side(s) {}

Square::~Square() {}

double Square::perimeter() const {
    return 4 * side;
}

double Square::area() const {
    return side * side;
}

ShapeType Square::type() const {
    return square;
}
