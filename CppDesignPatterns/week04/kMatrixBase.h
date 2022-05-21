//
// Created by 谢庭宇 on 2022/5/21.
//

#ifndef _WEEK04_KMATRIX_BASE_H_
#define _WEEK04_KMATRIX_BASE_H_

#include <iostream>
#include <memory>

enum MatrixType {vectorType, mapType};

template<typename T>
class KMatrixBase {
public:
    virtual size_t getRows() const = 0;

    virtual size_t getCols() const = 0;

    virtual void setData(size_t row, size_t col, T value) = 0;

    virtual T getData(size_t row, size_t col) const = 0;

    virtual void eraseRow(size_t row) = 0;

    virtual void eraseColumns(size_t col) = 0;

    virtual void print() const = 0;

    // TODO 如果接口类声明运算符重载方法，可以实现底层存储逻辑不同的矩阵的运算，但是只能返回父类指针，不能实现连加操作，后续等待寻找更好的解决办法
//    virtual KMatrixBase<T>* operator+(KMatrixBase<T> const &other) = 0;
//    virtual KMatrixBase<T>* operator-(KMatrixBase<T> const &other) = 0;
//    virtual KMatrixBase<T>* operator*(KMatrixBase<T> const &other) = 0;
//    virtual KMatrixBase<T>* transpose() const = 0;
};

#endif
