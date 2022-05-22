// -------------------------------------------------------
// TestVector.cpp
// 创建者： xie tingyu
// 创建时间： 2022/5/21
// 功能描述： 测试类的相关功能
// Copyright 2013 Kingsoft
// --------------------------------------------------------

#include "kMatrixVector.h"
#include "kMatrixIterator.h"

int main()
{
    KMatrixVector<int> matrix(3, 3, 1);
    KMatrixVector<int> matrix2(3, 3, 2);
    ((matrix + matrix) + matrix - matrix2).print();
    (matrix * matrix2 * matrix).print();

    KMatrixVector<int> matrix3(3, 1, 2);
    matrix3.print();
    matrix3.transpose().print();
    (matrix3 * matrix3.transpose()).print();
    (matrix3.transpose() * matrix3).print();

    matrix2.setData(0, 0, 10);
    matrix2.setData(1, 1, 15);
    matrix2.setData(2, 2, 20);
    KMatrixIterator<int> it = matrix2.begin();
    for (; it != matrix2.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}