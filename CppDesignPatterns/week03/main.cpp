//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Trapezium.h"
#include "Round.h"
#include "Square.h"
#include "Compoundshape.h"
#include <iostream>
#include <stdarg.h>

using namespace std;

int main() {
    cout << "Rectangle" << endl;
    Shape *rectangle = new Rectangle(3, 4);
    cout << rectangle->area() << endl;
    cout << rectangle->perimeter() << endl;
    cout << rectangle->type() << endl;
    cout << "--------------------------------" << endl;

    cout << "Square" << endl;
    Shape *square = new Square(3);
    cout << square->area() << endl;
    cout << square->perimeter() << endl;
    cout << square->type() << endl;
    cout << "--------------------------------" << endl;

    cout << "Triangle" << endl;
    Shape *triangle = new Triangle(3, 4, 5);
    cout << triangle->area() << endl;
    cout << triangle->perimeter() << endl;
    cout << triangle->type() << endl;
    cout << "--------------------------------" << endl;

    cout << "Trapezium" << endl;
    Shape *trapezium = new Trapezium(3, 11, 5, 5);
    cout << trapezium->area() << endl;
    cout << trapezium->perimeter() << endl;
    cout << trapezium->type() << endl;
    cout << "--------------------------------" << endl;

    cout << "Round" << endl;
    Shape *round = new Round(3);
    cout << round->area() << endl;
    cout << round->perimeter() << endl;
    cout << round->type() << endl;
    cout << "--------------------------------" << endl;

    cout << "Compoundshape" << endl;
    Compoundshape *compoundshape = new Compoundshape();
    compoundshape->addShape(rectangle);
    compoundshape->addShape(square);
    compoundshape->addShape(triangle);
    cout << compoundshape->area() << endl;
    cout << compoundshape->perimeter() << endl;
    cout << compoundshape->type() << endl;
    cout << "--------------------------------" << endl;
}