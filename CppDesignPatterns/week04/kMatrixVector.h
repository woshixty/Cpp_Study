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

    KMatrixVector() : m_row(0),
                      m_column(0) {}

    KMatrixVector(size_t row, size_t column, T data = 0) :
            m_row(row),
            m_column(column) {
        for (int i = 0; i < m_row; ++i) {
            m_matrix.push_back(std::vector<T>(m_column, data));
        }
    }

    KMatrixVector(KMatrixVector const &other) :
            m_row(other.m_row),
            m_column(other.m_column),
            m_matrix(other.m_matrix) {}

    size_t getRows() const override { return m_row; }

    size_t getCols() const override { return m_column; }

    void setData(size_t row, size_t col, T value) override {
        if (row < 0 || row >= m_row || col < 0 || col >= m_column) {
            throw std::out_of_range("设置矩阵元素值越界！");
        }
        m_matrix[row][col] = value;
    }

    T getData(size_t row, size_t col) const override {
        if (row < 0 || row >= m_row || col < 0 || col >= m_column) {
            throw std::out_of_range("获取矩阵元素值越界！");
        }
        return m_matrix[row][col];
    }

    void eraseRow(size_t row) override {
        if (row < 0 || row >= m_row) {
            throw std::out_of_range("删除矩阵行越界！");
        }
        m_matrix.erase(m_matrix.begin() + row);
        m_row--;
    }

    void eraseColumns(size_t col) override {
        if (col < 0 || col >= m_row) {
            throw std::out_of_range("删除矩阵列越界！");
        }
        for (int i = 0; i < m_row; ++i) {
            m_matrix[i].erase(m_matrix[i].begin() + col);
        }
        m_column--;
    }

    KMatrixVector<T> &operator=(KMatrixVector<T> const &other) {
        m_row = other.m_row;
        m_column = other.m_column;
        for (int i = 0; i < other.m_row; ++i) {
            m_matrix.push_back(std::vector<T>(other.m_matrix[i]));
        }
    }

    KMatrixVector<T> operator+(KMatrixVector<T> const &other) {
        int row = other.m_row, column = other.m_column;
        if (m_row != row || m_column != column) {
            throw std::invalid_argument("矩阵结构不一样，不能相加");
        }
        KMatrixVector<T> res(row, column);
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                res.setData(i, j, m_matrix[i][j] + other.getData(i, j));
            }
        }
        return res;
    }

    KMatrixVector<T> operator-(KMatrixVector<T> const &other) {
        int row = other.m_row, column = other.m_column;
        if (m_row != other.m_row || m_column != other.m_column) {
            throw std::invalid_argument("矩阵结构不一样，不能相减");
        }
        KMatrixVector<T> res(row, column);
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                res.setData(i, j, m_matrix[i][j] - other.getData(i, j));
            }
        }
        return res;
    }

    KMatrixVector<T> operator*(KMatrixVector<T> const &other) {
        int row = other.m_row, column = other.m_column;
        if (m_row != column || m_column != row) {
            throw std::invalid_argument("矩阵结构不能相乘");
        }
        KMatrixVector<T> res(m_row, column);
        for (size_t i = 0; i < m_row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                T data = 0;
                for (size_t k = 0; k < m_column; ++k) {
                    data += getData(i, k) * other.getData(k, j);
                }
                res.setData(i, j, data);
            }
        }
        return res;
    }

    KMatrixVector<T> transpose() const {
        // 交换行列值
        KMatrixVector<T> res(m_column, m_row);
        for (size_t i = 0; i < m_row; ++i) {
            for (size_t j = 0; j < m_column; ++j) {
                res.setData(j, i, m_matrix[i][j]);
            }
        }
        return res;
    }

    void print() const override {
        for (size_t i = 0; i < m_row; i++) {
            for (size_t j = 0; j < m_column; j++) {
                std::cout << m_matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

private:
    size_t m_row{}, m_column{};

    matrix m_matrix;
};


#endif
