//
// Created by 谢庭宇 on 2022/5/18.
//

#ifndef _WEEK04_KMATRIX_MAP_H_
#define _WEEK04_KMATRIX_MAP_H_

#include "kMatrixBase.h"
#include <map>

template<typename T>
class KMatrixMap : public KMatrixBase<T> {
public:
    using matrix = std::map<std::pair<int, int>, T>;
    using int_pair = std::pair<int, int>;

    KMatrixMap() : KMatrixBase<T>::m_row(0),
                   KMatrixBase<T>::m_column(0) {}

    KMatrixMap(size_t row, size_t column, T data = 0) {
        KMatrixBase<T>::m_row = row;
        KMatrixBase<T>::m_column = column;
        if (data != (T) 0) {
            for (int i = 0; i < KMatrixBase<T>::m_row; ++i) {
                for (int j = 0; j < KMatrixBase<T>::m_column; ++j) {
                    m_matrix[int_pair(i, j)] = data;
                }
            }
        }
    }

    void setData(size_t row, size_t col, T value) override {
        KMatrixBase<T>::judgeRowCol(row, col);
        if (value != (T) 0) {
            m_matrix[int_pair(row, col)] = value;
        }
    }

    T getData(size_t row, size_t col) const override {
        KMatrixBase<T>::judgeRowCol(row, col);
        if (m_matrix.find(int_pair(row, col)) == m_matrix.end()) {
            return 0;
        } else {
            return m_matrix.find(int_pair(row, col))->second;
        }
    }

    void eraseRow(size_t row) override {
        KMatrixBase<T>::judgeRowCol(row, 0);
        typename matrix::iterator it;
        for (it = m_matrix.begin(); it != m_matrix.end(); ++it) {
            int_pair key = it->first;
            m_matrix[int_pair(key.first - 1, key.second)] = it->second;
        }
        for (int i = 0; i < KMatrixBase<T>::m_column; ++i) {
            m_matrix.erase(int_pair(KMatrixBase<T>::m_row - 1, i));
        }
        KMatrixBase<T>::m_row--;
    }

    void eraseColumns(size_t col) override {
        KMatrixBase<T>::judgeRowCol(0, col);
        typename matrix::iterator it;
        for (it = m_matrix.begin(); it != m_matrix.end(); ++it) {
            int_pair key = it->first;
            m_matrix[int_pair(key.first, key.second - 1)] = it->second;
        }
        for (int i = 0; i < KMatrixBase<T>::m_row; ++i) {
            m_matrix.erase(int_pair(i, KMatrixBase<T>::m_column - 1));
        }
        KMatrixBase<T>::m_column--;
    }

    KMatrixBase<T> *getRightPointer(size_t row, size_t col) const override {
        return new KMatrixMap<T>(row, col);
    }

    KMatrixMap<T> &operator=(KMatrixMap<T> const &other) {
        KMatrixBase<T>::m_row = other.KMatrixBase<T>::m_row;
        KMatrixBase<T>::m_column = other.KMatrixBase<T>::m_column;
        m_matrix = other.m_matrix;
    }

    KMatrixMap<T> operator+(KMatrixMap<T> const &other) {
        auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrixBase<T>::operation(other, addType));
        return *res;
    }

    KMatrixMap<T> operator-(KMatrixMap<T> const &other) {
        auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrixBase<T>::operation(other, minusType));
        return *res;
    }

    KMatrixMap<T> operator*(KMatrixMap<T> const &other) {
        auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrixBase<T>::operation(other, multiplyType));
        return *res;
    }

    KMatrixMap<T> transpose() const {
        auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrixBase<T>::transposeBase());
        return *res;
    }

private:
    matrix m_matrix;
};


#endif //_WEEK04_KMATRIX_MAP_H_
