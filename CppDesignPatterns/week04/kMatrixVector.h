// -------------------------------------------------------
// kMatrixVector.h
// 创建者： xie tingyu
// 创建时间： 2022/5/21
// 功能描述： 使用vector实现的matrix类
// Copyright 2013 Kingsoft
// --------------------------------------------------------

#ifndef _WEEK04_KMATRIXVECTOR_H_
#define _WEEK04_KMATRIXVECTOR_H_

#include "kMatrix.h"
#include "kMatrixIterator.h"
#include <vector>

template<typename T>
class KMatrixVector : public KMatrix<T>
{
public:
    using matrix = std::vector<std::vector<T>>;
    using iterator = KMatrixIterator<T>;

    iterator begin();
    iterator end();

    KMatrixVector();
    KMatrixVector(size_t row, size_t column, T data = 0);
    KMatrixVector(KMatrixVector<T> const &other);
    // 使用数组构造矩阵
    KMatrixVector(size_t row, size_t column, T *src);
    KMatrixVector(size_t row, size_t column, matrix const &src);
    ~KMatrixVector() { m_matrix.clear(); }

    void setData(size_t row, size_t col, T value) override;
    T getData(size_t row, size_t col) const override;
    T &getDataRef(size_t row, size_t col) override;
    T *getDataPoint(size_t row, size_t col) override;

    void eraseRow(size_t row) override;
    void eraseColumns(size_t col) override;

    KMatrix<T> *getRightPointer(size_t row, size_t col) const override;
    void clear(size_t row, size_t col) override;

    KMatrixVector<T> &operator=(KMatrixVector<T> const &other);
    KMatrixVector<T> operator+(KMatrixVector<T> const &other);
    KMatrixVector<T> operator-(KMatrixVector<T> const &other);
    KMatrixVector<T> operator*(KMatrixVector<T> const &other);

    bool operator==(KMatrixVector<T> &other);

    KMatrixVector<T> transpose() const;

private:
    matrix m_matrix;
};

template<typename T>
KMatrixIterator<T> KMatrixVector<T>::begin() { return KMatrixIterator<T>(0, 0, this); }

template<typename T>
KMatrixIterator<T> KMatrixVector<T>::end()
{
    size_t row = KMatrix<T>::getRows();
    return KMatrixIterator<T>(row, 0, this);
}

template<typename T>
KMatrixVector<T>::KMatrixVector(size_t row, size_t column, T data)
{
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
    KMatrix<T>::m_row = row;
    KMatrix<T>::m_column = column;
    for (int i = 0; i < KMatrix<T>::m_row; ++i)
    {
        m_matrix.push_back(std::vector<T>(KMatrix<T>::m_column, data));
    }
}

template<typename T>
KMatrixVector<T>::KMatrixVector(const KMatrixVector &other): m_matrix(other.m_matrix)
{
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
    KMatrix<T>::m_row = other.m_row;
    KMatrix<T>::m_column = other.m_column;
}

template<typename T>
KMatrixVector<T>::KMatrixVector(size_t row, size_t column, T *src)
{
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
    KMatrix<T>::m_row = row;
    KMatrix<T>::m_column = column;
    size_t base = 0;
    for (size_t i = 0; i < row; ++i) {
        // 将第i行数据拷贝进去
        m_matrix.push_back(std::vector<T>(&src[base], &src[base + column]));
        base += column;
    }
}

template<typename T>
KMatrixVector<T>::KMatrixVector(size_t row, size_t column, matrix const &src)
{
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
    KMatrix<T>::m_row = row;
    KMatrix<T>::m_column = column;
    m_matrix = src;
}

template<typename T>
void KMatrixVector<T>::setData(size_t row, size_t col, T value)
{
    KMatrix<T>::judgeRowCol(row, col);
    m_matrix[row][col] = value;
}

template<typename T>
T KMatrixVector<T>::getData(size_t row, size_t col) const
{
    KMatrix<T>::judgeRowCol(row, col);
    return m_matrix[row][col];
}

template<typename T>
T &KMatrixVector<T>::getDataRef(size_t row, size_t col)
{
    KMatrix<T>::judgeRowCol(row, col);
    return m_matrix[row][col];
}

template<typename T>
T *KMatrixVector<T>::getDataPoint(size_t row, size_t col)
{
    KMatrix<T>::judgeRowCol(row, col);
    return &m_matrix[row][col];
}

template<typename T>
void KMatrixVector<T>::eraseRow(size_t row)
{
    KMatrix<T>::judgeRowCol(row, 0);
    m_matrix.erase(m_matrix.begin() + row);
    KMatrix<T>::m_row--;
}

template<typename T>
void KMatrixVector<T>::eraseColumns(size_t col)
{
    KMatrix<T>::judgeRowCol(0, col);
    for (int i = 0; i < KMatrix<T>::m_row; ++i)
    {
        m_matrix[i].erase(m_matrix[i].begin() + col);
    }
    KMatrix<T>::m_column--;
}

template<typename T>
KMatrix<T> *KMatrixVector<T>::getRightPointer(size_t row, size_t col) const
{
    return new KMatrixVector<T>(row, col);
}

template<typename T>
KMatrixVector<T> &KMatrixVector<T>::operator=(const KMatrixVector<T> &other)
{
    KMatrix<T>::m_row = other.KMatrix<T>::m_row;
    KMatrix<T>::m_column = other.KMatrix<T>::m_column;
    m_matrix = other.m_matrix;
    return *this;
}

template<typename T>
KMatrixVector<T> KMatrixVector<T>::operator+(const KMatrixVector<T> &other)
{
    auto *res = dynamic_cast<KMatrixVector<T> *>(KMatrix<T>::operation(other, addType));
    return *res;
}

template<typename T>
KMatrixVector<T> KMatrixVector<T>::operator-(const KMatrixVector<T> &other)
{
    auto *res = dynamic_cast<KMatrixVector<T> *>(KMatrix<T>::operation(other, minusType));
    return *res;
}

template<typename T>
KMatrixVector<T> KMatrixVector<T>::operator*(const KMatrixVector<T> &other)
{
    auto *res = dynamic_cast<KMatrixVector<T> *>(KMatrix<T>::operation(other, multiplyType));
    return *res;
}

template<typename T>
KMatrixVector<T> KMatrixVector<T>::transpose() const
{
    auto *res = dynamic_cast<KMatrixVector<T> *>(KMatrix<T>::transposeBase());
    return *res;
}

template<typename T>
bool KMatrixVector<T>::operator==(KMatrixVector<T> &other)
{
    return KMatrix<T>::sameMatrix(other);
}

template<typename T>
void KMatrixVector<T>::clear(size_t row, size_t col) {
    m_matrix.clear();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            m_matrix.push_back(std::vector<T>(col, 0));
        }
    }
}

template<typename T>
KMatrixVector<T>::KMatrixVector() : KMatrix<T>::m_row(0), KMatrix<T>::m_column(0)
{
    // 对模板泛型进行限制
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value, "not allowed");
}


#endif  // _WEEK04_KMATRIXVECTOR_H_
