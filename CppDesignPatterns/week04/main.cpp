//
// Created by 谢庭宇 on 2022/5/18.
//

#include "KMatrix.h"
#include "KMatrix.cpp"
#include <iostream>

using namespace std;

double a[4] = {
        1, 2,
        3, 4
};

double b[4] = {
        5, 6,
        7, 8
};

int main() {
//    kMatrix1era.transpose();
//    KMatrix<double> kMatrix1re();

    KMatrix<double> kMatrix;
    kMatrix.init(3, 3);
    cout << "kMatrix" << endl;
    kMatrix.print();
    cout << "---------" << endl << endl;

    KMatrix<double> kMatrix1(2, 2);
    cout << "kMatrix1" << endl;
    kMatrix1.print();
    cout << "---------" << endl << endl;

    KMatrix<double> kMatrix2;
    kMatrix2.init(2, 2, a);
    cout << "kMatrix2" << endl;
    kMatrix2.print();
    cout << "---------" << endl << endl;

    KMatrix<double> kMatrix3(2, 2, b);
    cout << "kMatrix3" << endl;
    kMatrix3.print();
    cout << "---------" << endl << endl;

    KMatrix<double> kMatrix1copy(kMatrix1);
    kMatrix1copy.setData(0, 0, 10);
    cout << "kMatrix1copy" << endl;
    kMatrix1copy.print();
    cout << "---------" << endl << endl;

    KMatrix<double> kMatrix1era(kMatrix1);
    kMatrix1era.eraseRow(0);
    kMatrix1era.setData(0, 0, 20);
    cout << "kMatrix1era" << "row : " << kMatrix1era.getRows() << "cols : " << kMatrix1era.getCols() << endl;
    kMatrix1era.print();
    cout << "---------" << endl << endl;

    KMatrix<double> *p = kMatrix1era.transpose();
    cout << "kMatrix1re" << endl;
    p->print();
    cout << "---------" << endl << endl;

    cout << "kMatrix3 + kMatrix2" << endl;
    (kMatrix3 + kMatrix2)->print();
    cout << "---------" << endl << endl;
}