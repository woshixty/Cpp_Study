//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Trapezium.h"
#include <math.h>

Trapezium::Trapezium() : top(0.0), bottom(0.0), left(0.0), right(0.0) {}

Trapezium::Trapezium(double t, double b, double l, double r) : top(t), bottom(b), left(l), right(r) {}

Trapezium::~Trapezium() {}

double Trapezium::perimeter() const {
    return top + bottom + left + right;
}

double Trapezium::area() const {
    double x = abs(top - bottom);
    if (x == 0) {
        // 为平行四边形
        return 0.0;
    }
    double p = (left + right + x) / 2.0;
    double s = sqrt(p * (p - left) * (p - right) * (p - x));
    return (top + bottom) * s / x;
}

ShapeType Trapezium::type() const {
    return trapezium;
}
