//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Rectangle.h"

Rectangle::Rectangle() : length(0.0), width(0.0) {}

Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

Rectangle::~Rectangle() {}

double Rectangle::perimeter() const {
    return 2 * (length + width);
}

double Rectangle::area() const {
    return length * width;
}

ShapeType Rectangle::type() const {
    return rectangle;
}