// -------------------------------------------------------
// kMatrixIterator.h
// 创建者： xie tingyu
// 创建时间： 2022/5/21
// 功能描述： matrix的自定义迭代器
// Copyright 2013 Kingsoft
// --------------------------------------------------------

#ifndef _WEEK04_KMATRIX_ITERATOR_H_
#define _WEEK04_KMATRIX_ITERATOR_H_

#include <iterator>
#include "kMatrix.h"

template<typename T>
class KMatrixIterator
{
public:
    // 迭代器相关属性
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value = T;
    using reference = T &;
    using pointer = T *;

    // 构造函数
    KMatrixIterator(size_t row, size_t column, KMatrix<T> *matrix) :
            m_curRow(row),
            m_curColumn(column),
            m_matrix(matrix) {}
    KMatrixIterator(KMatrixIterator<T> const &other) :
            m_curRow(other.m_curRow),
            m_curColumn(other.m_curColumn),
            m_matrix(other.m_matrix) {}
    // 拷贝赋值函数
    KMatrixIterator &operator=(KMatrixIterator<T> const &other);

    size_t getCurRow() const;
    size_t getCurColumn() const;

    bool operator==(KMatrixIterator<T> const &other) const;
    bool operator!=(KMatrixIterator<T> const &other) const;

    value get() { return m_matrix->getData(m_curRow, m_curColumn); };
    reference operator*() const;
    pointer operator->() const;

    KMatrixIterator<T> &operator++();
    KMatrixIterator<T> &operator--();

private:
    size_t m_curRow = 0;
    size_t m_curColumn = 0;
    KMatrix<T> *m_matrix = nullptr;
};

template<typename T>
KMatrixIterator<T> &KMatrixIterator<T>::operator=(const KMatrixIterator<T> &other)
{
    if (other != *this)
    {
        m_curRow = other.row;
        m_curColumn = other.column;
        m_matrix = other.m_matrix;
    }
}

template<typename T>
size_t KMatrixIterator<T>::getCurRow() const { return m_curRow; }

template<typename T>
size_t KMatrixIterator<T>::getCurColumn() const { return m_curColumn; }

template<typename T>
bool KMatrixIterator<T>::operator==(const KMatrixIterator<T> &other) const
{
    return m_curRow == other.m_curRow && m_curColumn == other.m_curColumn && m_matrix == other.m_matrix;
}

template<typename T>
bool KMatrixIterator<T>::operator!=(const KMatrixIterator<T> &other) const
{
    return m_curRow != other.m_curRow || m_curColumn != other.m_curColumn || m_matrix != other.m_matrix;
}

template<typename T>
T &KMatrixIterator<T>::operator*() const
{
    return m_matrix->getDataRef(m_curRow, m_curColumn);
}

template<typename T>
T *KMatrixIterator<T>::operator->() const
{
    return m_matrix->getDataPoint(m_curRow, m_curColumn);
}

template<typename T>
KMatrixIterator<T> &KMatrixIterator<T>::operator++()
{
    m_curColumn++;
    m_curRow += m_curColumn / m_matrix->getCols();
    m_curColumn %= m_matrix->getCols();
    return *this;
}

template<typename T>
KMatrixIterator<T> &KMatrixIterator<T>::operator--()
{
    m_curColumn--;
    if (m_curColumn < 0)
    {
        if (m_curRow > 0)
        {
            m_curRow--;
            m_curColumn = m_matrix->getCols() - 1;
        }
        else
        {
            m_curColumn = 0;
            m_curRow = 0;
        }
    }
    return *this;
}

#endif //_WEEK04_KMATRIX_ITERATOR_H_
