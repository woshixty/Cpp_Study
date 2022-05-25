//
// Created by 谢庭宇 on 2022/5/24.
//
#include "kMatrixBuilder.h"
#include "kMatrixMap.h"
#include "kMatrixVector.h"

int main() {
    KMatrixBuilder<double> *builder = new KMatrixBuilder<double>(3, 4);
    builder->buildMapMatrix(0, 0, 1)->buildMapMatrix(1, 1, 4);
    KMatrixMap<double> map1 = builder->getMapMatrix();
    map1.print();
    builder->buildVectorMatrix(2, 2, 10)
            ->buildVectorMatrix(0, 0, 19);
    KMatrixVector<double> vec1 = builder->getVectorMatrix();
    vec1.print();
    builder->resize(10, 10);
    map1 = builder->getMapMatrix();
    map1.print();
}