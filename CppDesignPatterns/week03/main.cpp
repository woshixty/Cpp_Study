//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Shape.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    Shape* shape = new Rectangle(3,4,5);
    cout << shape->area() << endl;
    cout << shape->perimeter() << endl;
    cout << shape->type() << endl;
}