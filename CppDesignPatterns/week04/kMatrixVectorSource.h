//
// Created by 谢庭宇 on 2022/5/18.
//

#ifndef _WEEK04_KMATRIX_VECTOR_H_
#define _WEEK04_KMATRIX_VECTOR_H_

#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>

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
    void eraseColumn(size_t col);

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

    // 转置
    KMatrixVectorSource<T> *transpose();

    // 输出
    void print() const;

private:
    size_t m_row{}, m_column{};

    std::vector<std::vector<T>> m_matrix;

    std::vector<std::vector<T>> &getMatrix();
};

template<typename T>
KMatrixVectorSource<T>::KMatrixVectorSource() :m_row(0), m_column(0) {

}

template<typename T>
KMatrixVectorSource<T>::KMatrixVectorSource(KMatrixVectorSource<T> &src) :m_row(src.m_row), m_column(src.m_column) {
    // 拷贝的matrix
    m_matrix = src.getMatrix();
}

template<typename T>
KMatrixVectorSource<T>::KMatrixVectorSource(size_t row, size_t column) :m_row(row), m_column(column) {
    // 向matrix中放入row个容量为column的std::vector
    for (size_t i = 0; i < row; ++i) {
        m_matrix.push_back(std::vector<T>(column, (T) 0));
    }
}

template<typename T>
KMatrixVectorSource<T>::KMatrixVectorSource(size_t row, size_t column, T *src) :m_row(row), m_column(column) {
    size_t base = 0;
    for (size_t i = 0; i < row; ++i) {
        // 将第i行数据拷贝进去
        m_matrix.push_back(std::vector<T>(&src[base], &src[base + column]));
        base += column;
    }
}

template<typename T>
KMatrixVectorSource<T>::KMatrixVectorSource(std::vector<std::vector<T>> src, size_t row, size_t column) {
    this->m_row = row;
    this->m_column = column;
    this->m_matrix = src;
}

template<typename T>
void KMatrixVectorSource<T>::initialize(size_t row, size_t column) {
    // 向matrix中放入row个容量为column的std::vector
    m_matrix.clear();
    this->m_row = row;
    this->m_column = column;
    for (size_t i = 0; i < row; ++i) {
        m_matrix.push_back(std::vector<T>(column, (T) 0));
    }
}

template<typename T>
void KMatrixVectorSource<T>::initialize(size_t row, size_t column, T *src) {
    // 先清空，再初始化
    m_matrix.clear();
    this->m_row = row;
    this->m_column = column;
    size_t base = 0;
    for (size_t i = 0; i < row; ++i) {
        // 将第i行数据拷贝进去
        m_matrix.push_back(std::vector<T>(&src[base], &src[base + column]));
        base += column;
    }
}

template<typename T>
inline size_t KMatrixVectorSource<T>::getRows() const {
    return m_row;
}

template<typename T>
inline size_t KMatrixVectorSource<T>::getCols() const {
    return m_column;
}

template<typename T>
void KMatrixVectorSource<T>::setData(size_t row, size_t col, T value) {
    if(row < 0 || row >= m_row || col < 0 || col >= m_column) {
        throw std::out_of_range("设置矩阵元素值越界！");
    }
    m_matrix[row][col] = value;
}

template<typename T>
T KMatrixVectorSource<T>::getData(size_t row, size_t col) const {
    if(row < 0 || row >= m_row || col < 0 || col >= m_column) {
        throw std::out_of_range("获取矩阵元素值越界！");
    }
    return m_matrix[row][col];
}

template<typename T>
void KMatrixVectorSource<T>::eraseRow(size_t row) {
    if(row < 0 || row >= m_row) {
        throw std::out_of_range("删除矩阵行越界！");
    }
    m_matrix.erase(m_matrix.begin() + row);
    this->m_row--;
}

template<typename T>
void KMatrixVectorSource<T>::eraseColumn(size_t col) {
    if(col < 0 || col >= m_row) {
        throw std::out_of_range("删除矩阵列越界！");
    }
    for (int i = 0; i < m_row; ++i) {
        m_matrix[i].erase(m_matrix[i].begin() + col);
    }
    this->m_column--;
}

template<typename T>
KMatrixVectorSource<T>* KMatrixVectorSource<T>::transpose() {
    // 交换行列值
    std::vector<std::vector<T>> data;
    for (size_t i = 0; i < m_column; ++i) {
        std::vector<T> currRow;
        for (size_t j = 0; j < m_row; ++j) {
            currRow.push_back(m_matrix[j][i]);
        }
        data.push_back(currRow);
    }
    auto *result = new KMatrixVectorSource<T>(data, m_column, m_row);
    return result;
}

template<typename T>
void KMatrixVectorSource<T>::print() const {
    for (size_t i = 0; i < m_row; i++) {
        for (size_t j = 0; j < m_column; j++) {
            std::cout << m_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template<typename T>
std::vector<std::vector<T>> &KMatrixVectorSource<T>::getMatrix() {
    // 拷贝一份matrix返回
    return m_matrix;
}

template<typename T>
KMatrixVectorSource<T>& KMatrixVectorSource<T>::operator=(KMatrixVectorSource<T> const &src) {
    this->m_row = src.m_row;
    this->m_column = src.m_column;
    this->m_matrix = src.getMatrix();
}

template<typename T>
KMatrixVectorSource<T>& KMatrixVectorSource<T>::operator=(std::vector<std::vector<T>> const &src) {
    this->m_row = src.size();
    this->m_column = src[0].size();
    this->m_matrix = src.getMatrix();
}


#endif //_WEEK04_KMATRIX_VECTOR_H_
