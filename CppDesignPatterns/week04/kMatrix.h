// -------------------------------------------------------
// kMatrix.h
// 创建者： xie tingyu
// 创建时间： 2022/5/21
// 功能描述： 定义虚基类，子类底层可以有不同的矩阵存储逻辑，对外提供一样的功能
// Copyright 2013 Kingsoft
// --------------------------------------------------------

#ifndef _WEEK04_KMATRIX_BASE_H_
#define _WEEK04_KMATRIX_BASE_H_

#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>

enum OperatorType
{
    addType, minusType, multiplyType
};

template<typename T>
class KMatrix
{
public:
    // TODO(xie tingyu)  kMatrix 和 KMatrixIterator 不可相互引用彼此的.h文件，需再将 KMatrixIterator 做一层抽象
    //  先在子类中实现相关方法
    //  virtual KMatrixIterator<T> begin() = 0;
    //  virtual KMatrixIterator<T> end() = 0;

    size_t getRows();
    size_t getCols();

    virtual void setData(size_t row, size_t col, T value) = 0;
    virtual T getData(size_t row, size_t col) const = 0;
    virtual T &getDataRef(size_t row, size_t col) = 0;
    virtual T *getDataPoint(size_t row, size_t col) = 0;

    virtual void eraseRow(size_t row) = 0;
    virtual void eraseColumns(size_t col) = 0;
    virtual void clear(size_t row, size_t col) = 0;

    /**
     * 虚基类获得指向子类对象的指针
     * 在做加减乘法时通过该接口回调动态new子类
     * @param row
     * @param col
     * @return 指向子类对象的指针
     */
    virtual KMatrix<T> *getRightPointer(size_t row, size_t col) const = 0;

    void print() const;

    void judgeRowCol(size_t row, size_t col) const;

    KMatrix<T> *transposeBase() const;

    /**
     * 子类实现set 与 get 位置（row，col）的接口以后，可以将共同代码放到基类中实现
     * 从而减少代码冗余
     * @param other
     * @param opeType 操作类型：加、减、乘
     * @return 指向子类对象的指针
     */
    KMatrix<T> *operation(KMatrix<T> const &other, OperatorType opeType);

    /**
     * 判断两个矩阵是否内容相同
     * @param other
     * @return
     */
    bool sameMatrix(KMatrix<T> const &other);

    /**
     * 初始化行列并清除数据
     * @param row
     * @param column
     */
    void initialize(size_t row, size_t column);

    // TODO 如果接口类声明运算符重载方法，可以实现底层存储逻辑不同的矩阵的运算，但是只能返回父类指针，不能实现连加操作，后续等待寻找更好的解决办法
    //  virtual KMatrix<T>* operator+(KMatrix<T> const &other) = 0;
    //  virtual KMatrix<T>* operator-(KMatrix<T> const &other) = 0;
    //  virtual KMatrix<T>* operator*(KMatrix<T> const &other) = 0;
    //  virtual KMatrix<T>* transposeBase() const = 0;

protected:
    size_t m_row{}, m_column{};
};

template<typename T>
size_t KMatrix<T>::getRows() { return m_row; }

template<typename T>
size_t KMatrix<T>::getCols() { return m_column; }

template<typename T>
void KMatrix<T>::print() const {
    for (size_t i = 0; i < KMatrix<T>::m_row; i++)
    {
        for (size_t j = 0; j < KMatrix<T>::m_column; j++)
        {
            std::cout << getData(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void KMatrix<T>::judgeRowCol(size_t row, size_t col) const
{
    if (row < 0 || row >= m_row || col < 0 || col >= m_column)
        throw std::out_of_range("越界错误！");
}

template<typename T>
KMatrix<T> *KMatrix<T>::transposeBase() const
{
    // 交换行列值
    KMatrix<T> *res = getRightPointer(m_column, m_row);
    for (size_t i = 0; i < KMatrix<T>::m_row; ++i)
    {
        for (size_t j = 0; j < KMatrix<T>::m_column; ++j)
        {
            res->setData(j, i, getData(i, j));
        }
    }
    return res;
}

template<typename T>
KMatrix<T> *KMatrix<T>::operation(const KMatrix<T> &other, OperatorType opeType)
{
    int row = other.m_row, column = other.m_column;
    KMatrix<T> *res;
    switch (opeType)
    {
        case addType:
        case minusType:
        {
            if (m_row != row || m_column != column)
                throw std::invalid_argument("矩阵结构不能加减");
            res = getRightPointer(row, column);
            for (size_t i = 0; i < row; ++i)
            {
                for (size_t j = 0; j < column; ++j)
                {
                    if (opeType == addType)
                        res->setData(i, j, getData(i, j) + other.getData(i, j));
                    else if (opeType == minusType)
                        res->setData(i, j, getData(i, j) - other.getData(i, j));
                }
            }
            break;
        }
        case multiplyType:
        {
            if (m_row != column || m_column != row)
                throw std::invalid_argument("矩阵结构不能相乘");
            res = getRightPointer(m_row, column);
            for (size_t i = 0; i < KMatrix<T>::m_row; ++i)
            {
                for (size_t j = 0; j < column; ++j)
                {
                    T data = 0;
                    for (size_t k = 0; k < KMatrix<T>::m_column; ++k)
                    {
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

template<typename T>
bool KMatrix<T>::sameMatrix(const KMatrix<T> &other)
{
    if(m_row != other.m_row || m_column != other.m_column)
        return false;
    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_column; ++j)
        {
            if(getData(i, j) != other.getData(i, j))
                return false;
        }
    }
    return true;
}

template<typename T>
void KMatrix<T>::initialize(size_t row, size_t column)
{
    clear(row, column);
    m_row = row;
    m_column = column;
}

#endif // _WEEK04_KMATRIX_BASE_H_
