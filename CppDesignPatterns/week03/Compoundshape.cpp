//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Compoundshape.h"
#include <vector>

using namespace std;

void Compoundshape::addShape(Shape *shape) {
    Shape *point = copyShape(shape);
    shapes.push_back(point);
}

double Compoundshape::perimeter() const {
    double perimeter = 0.0;
    for (auto iter = shapes.begin(); iter != shapes.end(); iter++) {
        perimeter += (*iter)->perimeter();
    }
    return perimeter;
}

double Compoundshape::area() const {
    double area = 0.0;
    for (auto iter = shapes.begin(); iter != shapes.end(); iter++) {
        area += (*iter)->area();
    }
    return area;
}

ShapeType Compoundshape::type() const {
    return compoundshape;
}

Compoundshape::~Compoundshape() {
    for (auto iter = shapes.begin(); iter != shapes.end(); ) {
        Shape *temp = *iter;
        iter++;
        delete temp;
    }
}
