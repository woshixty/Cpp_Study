//
// Created by 谢庭宇 on 2022/5/22.
//

#include "kMatrixMap.h"

int main() {
    KMatrixMap<int> matrix(3, 3, 1);
    KMatrixMap<int> matrix2(3, 3, 2);
    ((matrix + matrix) + matrix - matrix2).print();
    (matrix * matrix2 * matrix).print();

    KMatrixMap<int> matrix3(3, 1, 2);
    matrix3.print();
    matrix3.transpose().print();
    (matrix3 * matrix3.transpose()).print();
    (matrix3.transpose() * matrix3).print();
}