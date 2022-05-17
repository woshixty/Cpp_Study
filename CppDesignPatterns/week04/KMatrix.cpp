//
// Created by 谢庭宇 on 2022/5/18.
//

#include "KMatrix.h"

template<typename T>
void KMatrix<T>::init(int row, int column)
{

}

template<typename T>
int KMatrix<T>::getRows() const
{
    return matrix.size();
}

template<typename T>
int KMatrix<T>::getCols()
{
    if (matrix.empty())
        return 0;
    return matrix[0].size();
}

template<typename T>
void KMatrix<T>::setData(int row, int col, T value)
{

}

template<typename T>
T KMatrix<T>::getData(int row, int col)
{
    return nullptr;
}

template<typename T>
void KMatrix<T>::eraseRow(int row)
{

}

template<typename T>
KMatrix<T> operator+(KMatrix<T> a, KMatrix<T> b)
{
    return KMatrix<T>();
}

template<typename T>
KMatrix<T> operator-(KMatrix<T> a, KMatrix<T> b)
{
    return KMatrix<T>();
}

template<typename T>
KMatrix<T> operator*(KMatrix<T> a, KMatrix<T> b)
        {
    return KMatrix<T>();
}

template<typename T>
KMatrix<T> KMatrix<T>::transpose() const
{
    return KMatrix<T>();
}

template<typename T>
void KMatrix<T>::print() const
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {

        }
    }
}

template<typename T>
vector<vector<T>> &KMatrix<T>::getMatrix()
{
    return matrix;
}
