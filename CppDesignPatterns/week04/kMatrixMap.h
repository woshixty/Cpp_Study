//
// Created by 谢庭宇 on 2022/5/18.
//

#ifndef _WEEK04_KMATRIX_MAP_H_
#define _WEEK04_KMATRIX_MAP_H_

#include "kMatrix.h"
#include "kMatrixIterator.h"
#include <map>

template<typename T>
class KMatrixMap : public KMatrix<T> {
public:
    using matrix = std::map<std::pair<int, int>, T>;
    using int_pair = std::pair<int, int>;
    using iterator = KMatrixIterator<T>;

    iterator begin();
    iterator end();

    KMatrixMap() : KMatrix<T>::m_row(0), KMatrix<T>::m_column(0) {}
    KMatrixMap(size_t row, size_t column, T data = 0);
    KMatrixMap(KMatrixMap<T> &other);

    void setData(size_t row, size_t col, T value) override;
    T getData(size_t row, size_t col) const override;
    T &getDataRef(size_t row, size_t col) override;
    T *getDataPoint(size_t row, size_t col) override;

    void eraseRow(size_t row) override;
    void eraseColumns(size_t col) override;

    KMatrix<T> *getRightPointer(size_t row, size_t col) const override;

    KMatrixMap<T> &operator=(KMatrixMap<T> const &other);
    KMatrixMap<T> operator+(KMatrixMap<T> const &other);
    KMatrixMap<T> operator-(KMatrixMap<T> const &other);
    KMatrixMap<T> operator*(KMatrixMap<T> const &other);

    KMatrixMap<T> transpose() const;

private:
    matrix m_matrix;
};

template<typename T>
KMatrixIterator<T> KMatrixMap<T>::begin() { return KMatrixIterator<T>(0, 0, this); }

template<typename T>
KMatrixIterator<T> KMatrixMap<T>::end() { return KMatrixIterator<T>(KMatrix<T>::m_row, 0, this); }

template<typename T>
KMatrixMap<T>::KMatrixMap(size_t row, size_t column, T data) {
    KMatrix<T>::m_row = row;
    KMatrix<T>::m_column = column;
    if (data != (T) 0) {
        for (int i = 0; i < KMatrix<T>::m_row; ++i) {
            for (int j = 0; j < KMatrix<T>::m_column; ++j) {
                m_matrix[int_pair(i, j)] = data;
            }
        }
    }
}

template<typename T>
KMatrixMap<T>::KMatrixMap(KMatrixMap<T> &other) {
    KMatrix<T>::m_row = other.m_row;
    KMatrix<T>::m_column = other.m_row;
    m_matrix = other.m_matrix;
}

template<typename T>
void KMatrixMap<T>::setData(size_t row, size_t col, T value) {
    KMatrix<T>::judgeRowCol(row, col);
    if (value != (T) 0) {
        m_matrix[int_pair(row, col)] = value;
    }
}

template<typename T>
T KMatrixMap<T>::getData(size_t row, size_t col) const {
    KMatrix<T>::judgeRowCol(row, col);
    if (m_matrix.find(int_pair(row, col)) == m_matrix.end()) {
        return 0;
    } else {
        return m_matrix.find(int_pair(row, col))->second;
    }
}

template<typename T>
T &KMatrixMap<T>::getDataRef(size_t row, size_t col) {
    KMatrix<T>::judgeRowCol(row, col);
    if (m_matrix.find(int_pair(row, col)) == m_matrix.end()) {
        return 0;
    } else {
        return m_matrix.find(int_pair(row, col))->second;
    }
}

template<typename T>
T *KMatrixMap<T>::getDataPoint(size_t row, size_t col) {
    KMatrix<T>::judgeRowCol(row, col);
    if (m_matrix.find(int_pair(row, col)) == m_matrix.end()) {
        return 0;
    } else {
        return &m_matrix.find(int_pair(row, col))->second;
    }
}

template<typename T>
void KMatrixMap<T>::eraseRow(size_t row) {
    KMatrix<T>::judgeRowCol(row, 0);
    typename matrix::iterator it;
    for (it = m_matrix.begin(); it != m_matrix.end(); ++it) {
        int_pair key = it->first;
        m_matrix[int_pair(key.first - 1, key.second)] = it->second;
    }
    for (int i = 0; i < KMatrix<T>::m_column; ++i) {
        m_matrix.erase(int_pair(KMatrix<T>::m_row - 1, i));
    }
    KMatrix<T>::m_row--;
}

template<typename T>
void KMatrixMap<T>::eraseColumns(size_t col) {
    KMatrix<T>::judgeRowCol(0, col);
    typename matrix::iterator it;
    for (it = m_matrix.begin(); it != m_matrix.end(); ++it) {
        int_pair key = it->first;
        m_matrix[int_pair(key.first, key.second - 1)] = it->second;
    }
    for (int i = 0; i < KMatrix<T>::m_row; ++i) {
        m_matrix.erase(int_pair(i, KMatrix<T>::m_column - 1));
    }
    KMatrix<T>::m_column--;
}

template<typename T>
KMatrix<T> *KMatrixMap<T>::getRightPointer(size_t row, size_t col) const {
    return new KMatrixMap<T>(row, col);
}

template<typename T>
KMatrixMap<T> &KMatrixMap<T>::operator=(const KMatrixMap<T> &other) {
    KMatrix<T>::m_row = other.KMatrix<T>::m_row;
    KMatrix<T>::m_column = other.KMatrix<T>::m_column;
    m_matrix = other.m_matrix;
}

template<typename T>
KMatrixMap<T> KMatrixMap<T>::operator+(const KMatrixMap<T> &other) {
    auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrix<T>::operation(other, addType));
    return *res;
}

template<typename T>
KMatrixMap<T> KMatrixMap<T>::operator-(const KMatrixMap<T> &other) {
    auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrix<T>::operation(other, minusType));
    return *res;
}

template<typename T>
KMatrixMap<T> KMatrixMap<T>::operator*(const KMatrixMap<T> &other) {
    auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrix<T>::operation(other, multiplyType));
    return *res;
}

template<typename T>
KMatrixMap<T> KMatrixMap<T>::transpose() const {
    auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrix<T>::transposeBase());
    return *res;
}


#endif //_WEEK04_KMATRIX_MAP_H_
