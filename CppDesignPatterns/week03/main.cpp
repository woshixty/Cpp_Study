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
#include "CompoundshapeBuilder.h"
#include "ShapeFactory.h"
#include <iostream>

using namespace std;

int main() {
    ShapeFactory shapeFactory;

    cout << "Rectangle" << endl;
    Shape *rectangle = shapeFactory.getRectangle(3, 3);
    cout << rectangle->area() << endl;
    cout << rectangle->perimeter() << endl;
    cout << rectangle->type() << endl;
    cout << "--------------------------------" << endl;

    cout << "Square" << endl;
    Shape *square = shapeFactory.getSquare(3);
    cout << square->area() << endl;
    cout << square->perimeter() << endl;
    cout << square->type() << endl;
    cout << "--------------------------------" << endl;

    cout << "Triangle" << endl;
    Shape *triangle = shapeFactory.getTriangle(3, 4, 5);
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

    cout << "CompoundshapeBuilder" << endl;
    CompoundshapeBuilder *builder = new CompoundshapeBuilder();
    Shape *builderShape = builder->build(rectangle)->build(square)->build(triangle)->getShape();
    cout << builderShape->area() << endl;
    cout << builderShape->perimeter() << endl;
    cout << builderShape->type() << endl;
    cout << "--------------------------------" << endl;
}