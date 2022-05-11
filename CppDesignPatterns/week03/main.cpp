//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Trapezium.h"
#include "Square.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Rectangle" << endl;
    Shape *shape = new Rectangle(3, 4);
    cout << shape->area() << endl;
    cout << shape->perimeter() << endl;
    cout << shape->type() << endl;

    cout << "Square" << endl;
    shape = new Square(3);
    cout << shape->area() << endl;
    cout << shape->perimeter() << endl;
    cout << shape->type() << endl;

    cout << "Triangle" << endl;
    shape = new Triangle(3, 4, 5);
    cout << shape->area() << endl;
    cout << shape->perimeter() << endl;
    cout << shape->type() << endl;

    cout << "Trapezium" << endl;
    shape = new Trapezium(3, 11, 5, 5);
    cout << shape->area() << endl;
    cout << shape->perimeter() << endl;
    cout << shape->type() << endl;
}