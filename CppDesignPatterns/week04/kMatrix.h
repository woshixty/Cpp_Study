//
// Created by 谢庭宇 on 2022/5/21.
//

#ifndef _WEEK04_KMATRIX_BASE_H_
#define _WEEK04_KMATRIX_BASE_H_

#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>

enum OperatorType {
    addType, minusType, multiplyType
};

template<typename T>
class KMatrix {
public:
    // TODO
//    virtual KMatrixIterator<T> begin() = 0;
//    virtual KMatrixIterator<T> begin() = 0;

    size_t getRows();
    size_t getCols();

    virtual void setData(size_t row, size_t col, T value) = 0;
    virtual T getData(size_t row, size_t col) const = 0;
    virtual T &getDataRef(size_t row, size_t col) = 0;
    virtual T *getDataPoint(size_t row, size_t col) = 0;

    virtual void eraseRow(size_t row) = 0;
    virtual void eraseColumns(size_t col) = 0;

    virtual KMatrix<T> *getRightPointer(size_t row, size_t col) const = 0;

    void print() const;

    void judgeRowCol(size_t row, size_t col) const;

    KMatrix<T> *transposeBase() const;

    KMatrix<T> *operation(KMatrix<T> const &other, OperatorType opeType);

    // TODO 如果接口类声明运算符重载方法，可以实现底层存储逻辑不同的矩阵的运算，但是只能返回父类指针，不能实现连加操作，后续等待寻找更好的解决办法
//    virtual KMatrix<T>* operator+(KMatrix<T> const &other) = 0;
//    virtual KMatrix<T>* operator-(KMatrix<T> const &other) = 0;
//    virtual KMatrix<T>* operator*(KMatrix<T> const &other) = 0;
//    virtual KMatrix<T>* transposeBase() const = 0;

protected:
    size_t m_row{}, m_column{};
};

template<typename T>
size_t KMatrix<T>::getRows() { return m_row; }

template<typename T>
size_t KMatrix<T>::getCols() { return m_column; }

template<typename T>
void KMatrix<T>::print() const {
    for (size_t i = 0; i < KMatrix<T>::m_row; i++) {
        for (size_t j = 0; j < KMatrix<T>::m_column; j++) {
            std::cout << getData(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void KMatrix<T>::judgeRowCol(size_t row, size_t col) const {
    if (row < 0 || row >= m_row || col < 0 || col >= m_column) {
        throw std::out_of_range("越界错误！");
    }
}

template<typename T>
KMatrix<T> *KMatrix<T>::transposeBase() const {
    // 交换行列值
    KMatrix<T> *res = getRightPointer(m_column, m_row);
    for (size_t i = 0; i < KMatrix<T>::m_row; ++i) {
        for (size_t j = 0; j < KMatrix<T>::m_column; ++j) {
            res->setData(j, i, getData(i, j));
        }
    }
    return res;
}

template<typename T>
KMatrix<T> *KMatrix<T>::operation(const KMatrix<T> &other, OperatorType opeType) {
    int row = other.m_row, column = other.m_column;
    KMatrix<T> *res;
    switch (opeType) {
        case addType:
        case minusType: {
            if (m_row != row || m_column != column) {
                throw std::invalid_argument("矩阵结构不能加减");
            }
            res = getRightPointer(row, column);
            for (size_t i = 0; i < row; ++i) {
                for (size_t j = 0; j < column; ++j) {
                    if (opeType == addType) {
                        res->setData(i, j, getData(i, j) + other.getData(i, j));
                    } else if (opeType == minusType) {
                        res->setData(i, j, getData(i, j) - other.getData(i, j));
                    }
                }
            }
            break;
        }
        case multiplyType: {
            if (m_row != column || m_column != row) {
                throw std::invalid_argument("矩阵结构不能相乘");
            }
            res = getRightPointer(m_row, column);
            for (size_t i = 0; i < KMatrix<T>::m_row; ++i) {
                for (size_t j = 0; j < column; ++j) {
                    T data = 0;
                    for (size_t k = 0; k < KMatrix<T>::m_column; ++k) {
                        data += getData(i, k) * other.getData(k, j);
                    }
                    res->setData(i, j, data);
                }
            }
            break;
        }
        default:
            res = getRightPointer(0, 0);
    }
    return res;
}

#endif // _WEEK04_KMATRIX_BASE_H_
