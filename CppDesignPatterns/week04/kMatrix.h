//
// Created by 谢庭宇 on 2022/5/21.
//

#ifndef _WEEK04_KMATRIX_H_
#define _WEEK04_KMATRIX_H_

#include <iostream>
#include <vector>

template<typename T>
class KMatrixVectorSource {
public:
    // 空构造函数
    KMatrixVectorSource();
    // 拷贝构造函数
    KMatrixVectorSource(KMatrixVectorSource<T> &src);
    // 构造 0 矩阵
    KMatrixVectorSource(size_t row, size_t column);
    // 使用数组构造矩阵
    KMatrixVectorSource(size_t row, size_t column, T *src);
    // 使用矩阵构造矩阵
    KMatrixVectorSource(std::vector<std::vector<T>> src, size_t row, size_t column);

    // 初始化行列信息赋值为0
    void initialize(size_t row, size_t column);
    // 初始化行列信息并赋值
    void initialize(size_t row, size_t column, T *src);

    // 获得行
    size_t getRows() const;
    // 获得列
    size_t getCols() const;
    // 设置值
    void setData(size_t row, size_t col, T value);
    // 得到值
    T getData(size_t row, size_t col) const;

    // 删除行
    void eraseRow(size_t row);
    // 删除列
    void eraseColumn(size_t col);

    // 转置
    KMatrixVectorSource<T> *transpose();
    // 输出
    void print() const;

    // =重载
    KMatrixVectorSource<T>& operator=(KMatrixVectorSource<T> const &src);
    KMatrixVectorSource<T>& operator=(std::vector<std::vector<T>> const &src);

    // 加
    friend KMatrixVectorSource<T> *operator+(KMatrixVectorSource<T> a, KMatrixVectorSource<T> b) {
        if (a.m_row != b.m_row || a.m_column != b.m_column) {
            throw std::invalid_argument("矩阵结构不一样，不能相加");
        }
        std::vector<std::vector<T>> newMatrix;
        for (size_t i = 0; i < a.m_row; ++i) {
            std::vector<T> newRow;
            for (size_t j = 0; j < a.m_column; ++j) {
                newRow.push_back(a.m_matrix[i][j] + b.m_matrix[i][j]);
            }
            newMatrix.push_back(newRow);
        }
        auto *result = new KMatrixVectorSource<T>(newMatrix, a.m_row, a.m_column);
        return result;
    }
    // 减
    friend KMatrixVectorSource<T> *operator-(KMatrixVectorSource<T> a, KMatrixVectorSource<T> b) {
        if (a.m_row != b.m_row || a.m_column != b.m_column) {
            throw std::invalid_argument("矩阵结构不一样，不能相减");
        }
        std::vector<std::vector<T>> newMatrix;
        for (size_t i = 0; i < a.m_row; ++i) {
            std::vector<T> newRow;
            for (size_t j = 0; j < a.m_column; ++j) {
                newRow.push_back(a.m_matrix[i][j] - b.m_matrix[i][j]);
            }
            newMatrix.push_back(newRow);
        }
        auto *result = new KMatrixVectorSource<T>(newMatrix, a.m_row, a.m_column);
        return result;
    }
    // 乘
    friend KMatrixVectorSource<T> *operator*(KMatrixVectorSource<T> a, KMatrixVectorSource<T> b) {
        if (a.m_row != b.m_column || a.m_column != b.m_row) {
            throw std::invalid_argument("矩阵结构不能相乘");
        }
        std::vector<std::vector<T>> newMatrix;
        size_t newRow = a.m_row;
        size_t newColumn = b.m_column;
        for (size_t i = 0; i < newRow; ++i) {
            std::vector<T> temp;
            for (size_t j = 0; j < newColumn; ++j) {
                T data = (T) 0;
                for (size_t k = 0; k < a.m_column; ++k) {
                    data += a.getData(i, k) * b.getData(k, j);
                }
                temp.push_back(data);
            }
            newMatrix.push_back(temp);
        }
        auto *result = new KMatrixVectorSource<T>(newMatrix, newRow, newColumn);
        return result;
    }

private:
    size_t m_row, m_column;

    std::vector<std::vector<T>> m_matrix;

    std::vector<std::vector<T>> &getMatrix();
};

#endif //_WEEK04_KMATRIX_H_
