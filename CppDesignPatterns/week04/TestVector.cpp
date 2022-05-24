// -------------------------------------------------------
// TestVector.cpp
// 创建者： xie tingyu
// 创建时间： 2022/5/21
// 功能描述： 测试类的相关功能
// Copyright 2013 Kingsoft
// --------------------------------------------------------

#include "kMatrixVector.h"
#include "kMatrixIterator.h"

using namespace std;

int main()
{
    // 构造函数
    KMatrixVector<int> matrix(3, 3, 1);
    cout << "matrix ori" << endl;
    matrix.print();
    cout << "---------" << endl << endl;

    KMatrixVector<int> matrixCopy = matrix;
    matrix.setData(0, 2, 9);

    KMatrixVector<int> matrixEraRow = matrix;
    matrixEraRow.eraseRow(1);
    KMatrixVector<int> matrixEraCol = matrix;
    matrixEraCol.eraseColumns(1);

    KMatrixVector<int> add = matrix + matrixCopy;
    KMatrixVector<int> min = matrix - matrixCopy;
    KMatrixVector<int> mul = matrixEraCol * matrixEraRow;

    KMatrixVector<int> transpose = matrix.transpose();

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
}