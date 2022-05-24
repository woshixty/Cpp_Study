// -------------------------------------------------------
// TestMap.cpp
// 创建者： xie tingyu
// 创建时间： 2022/5/21
// 功能描述： 测试类的相关功能
// Copyright 2013 Kingsoft
// --------------------------------------------------------

#include "kMatrixMap.h"
#include <iostream>

using namespace std;
int main()
{
    // 构造函数
    KMatrixMap<int> matrix(3, 3, 1);
    cout << "matrix ori" << endl;
    matrix.print();
    cout << "---------" << endl << endl;

    KMatrixMap<int> matrixCopy = matrix;
    matrix.setData(0, 2, 9);

    KMatrixMap<int> matrixEraRow = matrix;
    matrixEraRow.eraseRow(1);
    KMatrixMap<int> matrixEraCol = matrix;
    matrixEraCol.eraseColumns(1);

    KMatrixMap<int> add = matrix + matrixCopy;
    KMatrixMap<int> min = matrix - matrixCopy;
    KMatrixMap<int> mul = matrixEraCol * matrixEraRow;

    KMatrixMap<int> transpose = matrix.transpose();

    cout << "matrix after" << endl;
    matrix.print();
    cout << "---------" << endl << endl;

    cout << "matrixCopy" << endl;
    matrixCopy.print();
    cout << "---------" << endl << endl;

    cout << "matrixEraRow" << endl;
    matrixEraRow.print();
    cout << "---------" << endl << endl;

    cout << "matrixEraCol" << endl;
    matrixEraCol.print();
    cout << "---------" << endl << endl;

    cout << "add" << endl;
    add.print();
    cout << "---------" << endl << endl;

    cout << "min" << endl;
    min.print();
    cout << "---------" << endl << endl;

    cout << "mul" << endl;
    mul.print();
    cout << "---------" << endl << endl;

    cout << "transpose" << endl;
    transpose.print();
    cout << "---------" << endl << endl;

    cout << "KMatrixIterator" << endl;
    KMatrixIterator<int> it = matrix.begin();
    for (; it != matrix.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "---------" << endl << endl;

    cout << "==" << endl;
    KMatrixMap<int> a(3, 4, 7);
    KMatrixMap<int> b(3, 4, 6);
    bool f = a == b;
    cout << f << endl;
    cout << "---------" << endl << endl;
}