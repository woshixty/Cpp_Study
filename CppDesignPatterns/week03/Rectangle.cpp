//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Rectangle.h"
#include <iostream>
#include <math.h>

using namespace std;

Rectangle::Rectangle() : sideA(0.0), sideB(0.0), sideC(0.0) {}

Rectangle::Rectangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}

Rectangle::~Rectangle() {}

void Rectangle::setSides(double a, double b, double c) {
    if (a + b > c && b + c > a && a + c > b) {
        sideA = a;
        sideB = b;
        sideC = c;
    } else {
        cout << "不能构成三角形" << endl;
    }
}

double Rectangle::perimeter() const {
    return sideA + sideB + sideC;
}

double Rectangle::area() const {
    double s = (sideA + sideB + sideC) / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

ShapeType Rectangle::type() const {
    return triangle;
}