//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Round.h"
#include <iostream>

using namespace std;

Round::Round() : radius(0.0) {}

Round::Round(double r) : radius(r) {}

Round::Round(Shape *shape) {
    if (shape != nullptr && shape->type() == circle) {
        Round *p = dynamic_cast<Round *>(shape);
        radius = p->radius;
    } else {
        radius = 0.0;
        cout << "类型不可用于构造Round" << endl;
    }
}

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
