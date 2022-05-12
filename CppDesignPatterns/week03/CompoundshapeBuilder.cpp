//
// Created by 谢庭宇 on 2022/5/12.
//

#include "CompoundshapeBuilder.h"
#include "Compoundshape.h"

CompoundshapeBuilder::CompoundshapeBuilder() {

}

CompoundshapeBuilder::~CompoundshapeBuilder() {
    for (auto iter = shapes.begin(); iter != shapes.end();) {
        Shape *temp = *iter;
        iter++;
        delete temp;
    }
}

CompoundshapeBuilder *CompoundshapeBuilder::build(Shape *buildPara) {
    shapes.push_back(Compoundshape::copyShape(buildPara));
    return this;
}

Shape *CompoundshapeBuilder::getShape() {
    Compoundshape *shape = new Compoundshape();
    for (auto iter = shapes.begin(); iter != shapes.end(); iter++) {
        shape->addShape(*iter);
    }
    return shape;
}
