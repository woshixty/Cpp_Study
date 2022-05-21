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

    KMatrixMap() : m_row(0),
                   m_column(0) {}

    KMatrixMap(size_t row, size_t column, T data = 0) :
            m_row(row),
            m_column(column) {
        if (data != (T) 0) {
            for (int i = 0; i < m_row; ++i) {
                for (int j = 0; j < m_column; ++j) {
                    m_matrix[int_pair(i, j)] = data;
                }
            }
        }
    }

    size_t getRows() const override { return m_row; }

    size_t getCols() const override { return m_column; }

    void setData(size_t row, size_t col, T value) override {
        if (row < 0 || row >= m_row || col < 0 || col >= m_column) {
            throw std::out_of_range("设置矩阵元素值越界！");
        }
        if (value != (T) 0) {
            m_matrix[int_pair(row, col)] = value;
        }
    }

    T getData(size_t row, size_t col) const override {
        if (row < 0 || row >= m_row || col < 0 || col >= m_column) {
            throw std::out_of_range("获取矩阵元素值越界！");
        }
        if (m_matrix.find(int_pair(row, col)) == m_matrix.end()) {
            return 0;
        } else {
            return m_matrix.find(int_pair(row, col))->second;
        }
    }

    void eraseRow(size_t row) override {
        if (row < 0 || row >= m_row) {
            throw std::out_of_range("删除矩阵行越界！");
        }
        for (int i = 0; i < m_column; ++i) {
            m_matrix.erase(int_pair(row, i));
        }
        m_row--;
    }

    void eraseColumns(size_t col) override {
        if (col < 0 || col >= m_row) {
            throw std::out_of_range("删除矩阵列越界！");
        }
        for (int i = 0; i < m_row; ++i) {
            m_matrix.erase(int_pair(i, col));
        }
        m_column--;
    }

    KMatrixMap<T> &operator=(KMatrixMap<T> const &other) {
        m_row = other.m_row;
        m_column = other.m_column;
        m_matrix = other.m_matrix;
    }

    KMatrixMap<T> operator+(KMatrixMap<T> const &other) {
        int row = other.m_row, column = other.m_column;
        if (m_row != row || m_column != column) {
            throw std::invalid_argument("矩阵结构不一样，不能相加");
        }
        KMatrixMap<T> res(row, column);
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                res.setData(i, j, getData(i, j) + other.getData(i, j));
            }
        }
        return res;
    }

    KMatrixMap<T> operator-(KMatrixMap<T> const &other) {
        int row = other.m_row, column = other.m_column;
        if (m_row != other.m_row || m_column != other.m_column) {
            throw std::invalid_argument("矩阵结构不一样，不能相减");
        }
        KMatrixMap<T> res(row, column);
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                res.setData(i, j, getData(i, j) - other.getData(i, j));
            }
        }
        return res;
    }

    KMatrixMap<T> operator*(KMatrixMap<T> const &other) {
        int row = other.m_row, column = other.m_column;
        if (m_row != column || m_column != row) {
            throw std::invalid_argument("矩阵结构不能相乘");
        }
        KMatrixMap<T> res(m_row, column);
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

    KMatrixMap<T> transpose() const {
        // 交换行列值
        KMatrixMap<T> res(m_column, m_row);
        for (size_t i = 0; i < m_row; ++i) {
            for (size_t j = 0; j < m_column; ++j) {
                res.setData(j, i, getData(i, j));
            }
        }
        return res;
    }

    void print() const override {
        for (size_t i = 0; i < m_row; i++) {
            for (size_t j = 0; j < m_column; j++) {
                std::cout << getData(i, j) << "\t";
            }
            std::cout << std::endl;
        }
    }

private:
    size_t m_row, m_column;

    matrix m_matrix;
};


#endif //WEEK04_KMATRIX_PLUS_H
