//
// Created by 谢庭宇 on 2022/5/12.
//

#include "ShapeFactory.h"

Triangle *ShapeFactory::getTriangle(double a, double b, double c) {
    return new Triangle(a, b, c);
}

Square *ShapeFactory::getSquare(double side) {
    return new Square(side);
}

Rectangle *ShapeFactory::getRectangle(double l, double w) {
    return new Rectangle(l, w);
}

Trapezium *ShapeFactory::getTrapezium(double t, double b, double l, double r) {
    return new Trapezium(t, b, l, r);
}

Round *ShapeFactory::getRound(double r) {
    return new Round(r);
}
