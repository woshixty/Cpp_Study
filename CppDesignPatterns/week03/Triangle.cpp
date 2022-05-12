//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Triangle.h"
#include <iostream>
#include <math.h>

using namespace std;

Triangle::Triangle() : sideA(0.0), sideB(0.0), sideC(0.0) {}

Triangle::Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}

Triangle::Triangle(Shape *shape) {
    if (shape != nullptr && shape->type() == triangle) {
        Triangle *p = dynamic_cast<Triangle *>(shape);
        sideA = p->sideA;
        sideB = p->sideB;
        sideC = p->sideC;
    } else {
        sideA = 0;
        sideB = 0;
        sideC = 0;
        cout << "类型不可用于构造Triangle" << endl;
    }
}

Triangle::~Triangle() {}

void Triangle::setSides(double a, double b, double c) {
    if (a + b > c && b + c > a && a + c > b) {
        sideA = a;
        sideB = b;
        sideC = c;
    } else {
        cout << "不能构成三角形" << endl;
    }
}

double Triangle::perimeter() const {
    return sideA + sideB + sideC;
}

double Triangle::area() const {
    double s = (sideA + sideB + sideC) / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

ShapeType Triangle::type() const {
    return triangle;
}
