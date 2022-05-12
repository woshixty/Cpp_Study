//
// Created by 谢庭宇 on 2022/5/12.
//

#ifndef CPPDESIGNPATTERNS_SHAPEFACTORY_H
#define CPPDESIGNPATTERNS_SHAPEFACTORY_H

#include "Rectangle.h"
#include "Triangle.h"
#include "Trapezium.h"
#include "Round.h"
#include "Square.h"

class ShapeFactory {
public:
    Triangle *getTriangle(double a, double b, double c);
    Square *getSquare(double side);
    Rectangle *getRectangle(double l, double w);
    Trapezium *getTrapezium(double t, double b, double l, double r);
    Round *getRound(double r);
};


#endif //CPPDESIGNPATTERNS_SHAPEFACTORY_H
