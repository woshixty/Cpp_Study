//
// Created by 谢庭宇 on 2022/5/21.
//

#ifndef _WEEK04_KMATRIXVECTOR_H_
#define _WEEK04_KMATRIXVECTOR_H_

#include "kMatrixBase.h"
#include "kMatrixMap.h"
#include <iostream>
#include <vector>

template<typename T>
class KMatrixVector : public KMatrixBase<T> {
public:
    using matrix = std::vector<std::vector<T>>;

    KMatrixVector() : KMatrixBase<T>::m_row(0),
                      KMatrixBase<T>::m_column(0) {}

    KMatrixVector(size_t row, size_t column, T data = 0) {
        KMatrixBase<T>::m_row = row;
        KMatrixBase<T>::m_column = column;
        for (int i = 0; i < KMatrixBase<T>::m_row; ++i) {
            m_matrix.push_back(std::vector<T>(KMatrixBase<T>::m_column, data));
        }
    }

    KMatrixVector(KMatrixVector const &other) : m_matrix(other.m_matrix) {
        KMatrixBase<T>::m_row = other.m_row;
        KMatrixBase<T>::m_column = other.m_column;
    }

    void setData(size_t row, size_t col, T value) override {
        KMatrixBase<T>::judgeRowCol(row, col);
        m_matrix[row][col] = value;
    }

    T getData(size_t row, size_t col) const override {
        KMatrixBase<T>::judgeRowCol(row, col);
        return m_matrix[row][col];
    }

    void eraseRow(size_t row) override {
        KMatrixBase<T>::judgeRowCol(row, 0);
        m_matrix.erase(m_matrix.begin() + row);
        KMatrixBase<T>::m_row--;
    }

    void eraseColumns(size_t col) override {
        KMatrixBase<T>::judgeRowCol(0, col);
        for (int i = 0; i < KMatrixBase<T>::m_row; ++i) {
            m_matrix[i].erase(m_matrix[i].begin() + col);
        }
        KMatrixBase<T>::m_column--;
    }

    KMatrixBase<T> *getRightPointer(size_t row, size_t col) const override {
        return new KMatrixVector<T>(row, col);
    }

    KMatrixVector<T> &operator=(KMatrixVector<T> const &other) {
        KMatrixBase<T>::m_row = other.KMatrixBase<T>::m_row;
        KMatrixBase<T>::m_column = other.KMatrixBase<T>::m_column;
        m_matrix = other.m_matrix;
    }

    KMatrixVector<T> operator+(KMatrixVector<T> const &other) {
        auto * res = dynamic_cast<KMatrixVector<T> *>(KMatrixBase<T>::operation(other, addType));
        return *res;
    }

    KMatrixVector<T> operator-(KMatrixVector<T> const &other) {
        auto * res = dynamic_cast<KMatrixVector<T> *>(KMatrixBase<T>::operation(other, minusType));
        return *res;
    }

    KMatrixVector<T> operator*(KMatrixVector<T> const &other) {
        auto * res = dynamic_cast<KMatrixVector<T> *>(KMatrixBase<T>::operation(other, multiplyType));
        return *res;
    }

    KMatrixVector<T> transpose() const {
        auto * res = dynamic_cast<KMatrixVector<T> *>(KMatrixBase<T>::transposeBase());
        return *res;
    }

private:
    matrix m_matrix;
};


#endif
