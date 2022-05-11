//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Round.h"

Round::Round() : radius(0.0){}

Round::Round(double r) : radius(r) {}

Round::~Round() {}

double Round::perimeter() const {
    return 2 * radius * PI;
}

double Round::area() const {
    return PI * radius * radius;
}

ShapeType Round::type() const {
    return circle;
}
