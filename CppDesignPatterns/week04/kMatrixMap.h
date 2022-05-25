// -------------------------------------------------------
// kMatrixMap.cpp
// 创建者： xie tingyu
// 创建时间： 2022/5/21
// 功能描述：
// Copyright 2013 Kingsoft
// --------------------------------------------------------

#ifndef _WEEK04_KMATRIX_MAP_H_
#define _WEEK04_KMATRIX_MAP_H_

#include "kMatrix.h"
#include "kMatrixIterator.h"
#include <map>

template<typename T>
class KMatrixMap : public KMatrix<T>
{
public:
    using matrix = std::map<std::pair<int, int>, T>;
    using int_pair = std::pair<int, int>;
    using iterator = KMatrixIterator<T>;

    iterator begin();
    iterator end();

    KMatrixMap();
    KMatrixMap(size_t row, size_t column, T data = 0);
    KMatrixMap(KMatrixMap<T> const &other);
    // 使用数组构造矩阵
    KMatrixMap(size_t row, size_t column, T *src);
    KMatrixMap(size_t row, size_t column, matrix const &src);
    ~KMatrixMap() { m_matrix.clear(); }

    void setData(size_t row, size_t col, T value) override;
    T getData(size_t row, size_t col) const override;
    T &getDataRef(size_t row, size_t col) override;
    T *getDataPoint(size_t row, size_t col) override;

    void eraseRow(size_t row) override;
    void eraseColumns(size_t col) override;

    KMatrix<T> *getRightPointer(size_t row, size_t col) const override;
    void clear(size_t row, size_t col) override;

    KMatrixMap<T> &operator=(KMatrixMap<T> const &other);
    KMatrixMap<T> &operator+(KMatrixMap<T> const &other);
    KMatrixMap<T> operator-(KMatrixMap<T> const &other);
    KMatrixMap<T> operator*(KMatrixMap<T> const &other);

    bool operator==(KMatrixMap<T> &other);

    KMatrixMap<T> transpose() const;

private:
    matrix m_matrix;
};

template<typename T>
KMatrixIterator<T> KMatrixMap<T>::begin() { return KMatrixIterator<T>(0, 0, this); }

template<typename T>
KMatrixIterator<T> KMatrixMap<T>::end() { return KMatrixIterator<T>(KMatrix<T>::m_row, 0, this); }

template<typename T>
KMatrixMap<T>::KMatrixMap(size_t row, size_t column, T data)
{
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
    KMatrix<T>::m_row = row;
    KMatrix<T>::m_column = column;
    if (data != (T) 0)
    {
        for (int i = 0; i < KMatrix<T>::m_row; ++i)
        {
            for (int j = 0; j < KMatrix<T>::m_column; ++j)
            {
                m_matrix[int_pair(i, j)] = data;
            }
        }
    }
}

template<typename T>
KMatrixMap<T>::KMatrixMap(KMatrixMap<T> const &other)
{
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
    KMatrix<T>::m_row = other.m_row;
    KMatrix<T>::m_column = other.m_column;
    m_matrix = other.m_matrix;
}

template<typename T>
KMatrixMap<T>::KMatrixMap(size_t row, size_t column, T *src) {
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
    KMatrix<T>::m_row = row;
    KMatrix<T>::m_column = column;
    int point = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if(src[point] != (T)0) {
                m_matrix[int_pair(i, j)] = src[point++];
            }
        }
    }
}

template<typename T>
KMatrixMap<T>::KMatrixMap(size_t row, size_t column, KMatrixMap::matrix const &src) {
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
    KMatrix<T>::m_row = row;
    KMatrix<T>::m_column = column;
    m_matrix = src;
}

template<typename T>
void KMatrixMap<T>::setData(size_t row, size_t col, T value)
{
    KMatrix<T>::judgeRowCol(row, col);
    if (value != (T) 0)
        m_matrix[int_pair(row, col)] = value;
}

template<typename T>
T KMatrixMap<T>::getData(size_t row, size_t col) const
{
    KMatrix<T>::judgeRowCol(row, col);
    if (m_matrix.find(int_pair(row, col)) == m_matrix.end())
    {
        return 0;
    }
    else
    {
        return m_matrix.find(int_pair(row, col))->second;
    }
}

template<typename T>
T &KMatrixMap<T>::getDataRef(size_t row, size_t col)
{
    KMatrix<T>::judgeRowCol(row, col);
    if (m_matrix.find(int_pair(row, col)) == m_matrix.end())
    {
        m_matrix[int_pair(row, col)] = 0;
    }
    return m_matrix.find(int_pair(row, col))->second;
}

template<typename T>
T *KMatrixMap<T>::getDataPoint(size_t row, size_t col)
{
    KMatrix<T>::judgeRowCol(row, col);
    if (m_matrix.find(int_pair(row, col)) == m_matrix.end())
    {
        m_matrix[int_pair(row, col)] = 0;
    }
    return &m_matrix.find(int_pair(row, col))->second;
}

template<typename T>
void KMatrixMap<T>::eraseRow(size_t row)
{
    KMatrix<T>::judgeRowCol(row, 0);
    typename matrix::iterator it;
    for (it = m_matrix.begin(); it != m_matrix.end(); ++it)
    {
        int_pair key = it->first;
        m_matrix[int_pair(key.first - 1, key.second)] = it->second;
    }
    for (int i = 0; i < KMatrix<T>::m_column; ++i)
    {
        m_matrix.erase(int_pair(KMatrix<T>::m_row - 1, i));
    }
    KMatrix<T>::m_row--;
}

template<typename T>
void KMatrixMap<T>::eraseColumns(size_t col)
{
    KMatrix<T>::judgeRowCol(0, col);
    typename matrix::iterator it;
    for (it = m_matrix.begin(); it != m_matrix.end(); ++it)
    {
        int_pair key = it->first;
        m_matrix[int_pair(key.first, key.second - 1)] = it->second;
    }
    for (int i = 0; i < KMatrix<T>::m_row; ++i)
    {
        m_matrix.erase(int_pair(i, KMatrix<T>::m_column - 1));
    }
    KMatrix<T>::m_column--;
}

template<typename T>
KMatrix<T> *KMatrixMap<T>::getRightPointer(size_t row, size_t col) const
{
    return new KMatrixMap<T>(row, col);
}

template<typename T>
KMatrixMap<T> &KMatrixMap<T>::operator=(KMatrixMap<T> const &other)
{
    KMatrix<T>::m_row = other.KMatrix<T>::m_row;
    KMatrix<T>::m_column = other.KMatrix<T>::m_column;
    m_matrix = other.m_matrix;
    return *this;
}

template<typename T>
KMatrixMap<T> &KMatrixMap<T>::operator+(const KMatrixMap<T> &other)
{
    auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrix<T>::operation(other, addType));
    return *res;
}

template<typename T>
KMatrixMap<T> KMatrixMap<T>::operator-(const KMatrixMap<T> &other)
{
    auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrix<T>::operation(other, minusType));
    return *res;
}

template<typename T>
KMatrixMap<T> KMatrixMap<T>::operator*(const KMatrixMap<T> &other)
{
    auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrix<T>::operation(other, multiplyType));
    return *res;
}

template<typename T>
bool KMatrixMap<T>::operator==(KMatrixMap<T> &other)
{
    return KMatrix<T>::sameMatrix(other);
}

template<typename T>
KMatrixMap<T> KMatrixMap<T>::transpose() const
{
    auto * res = dynamic_cast<KMatrixMap<T> *>(KMatrix<T>::transposeBase());
    return *res;
}

template<typename T>
void KMatrixMap<T>::clear(size_t row, size_t col)
{
    m_matrix.clear();
}

template<typename T>
KMatrixMap<T>::KMatrixMap() : KMatrix<T>::m_row(0), KMatrix<T>::m_column(0) {
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
}


#endif //_WEEK04_KMATRIX_MAP_H_
