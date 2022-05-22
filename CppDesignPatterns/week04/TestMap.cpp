// -------------------------------------------------------
// TestMap.cpp
// 创建者： xie tingyu
// 创建时间： 2022/5/21
// 功能描述： 测试类的相关功能
// Copyright 2013 Kingsoft
// --------------------------------------------------------

#include "kMatrixMap.h"

int main()
{
    KMatrixMap<int> matrix(3, 3, 1);
    KMatrixMap<int> matrix2(3, 3, 2);
    ((matrix + matrix) + matrix - matrix2).print();
    (matrix * matrix2 * matrix).print();

    KMatrixMap<int> matrix3(3, 1, 2);
    matrix3.print();
    KMatrixMap<int> resp = matrix3.transpose();
    (matrix3 * matrix3.transpose()).print();
    (matrix3.transpose() * matrix3).print();

    KMatrixMap<int> map = (matrix3 * matrix3.transpose());
    map.eraseRow(1);
    map.eraseColumns(1);
    map.print();
}