//
// Created by 谢庭宇 on 2022/5/24.
//

#ifndef _WEEK04_KMATRIX_BUILDER_H_
#define _WEEK04_KMATRIX_BUILDER_H_

#include <map>
#include <vector>
#include "kMatrixMap.h"
#include "kMatrixVector.h"

template<typename T>
class KMatrixBuilder {
public:
    KMatrixBuilder(int row, int column);

    ~KMatrixBuilder();

    KMatrixBuilder *buildMapMatrix(int row, int column, T data);

    KMatrixBuilder *buildVectorMatrix(int row, int column, T data);

    KMatrixMap<T> getMapMatrix();

    KMatrixVector<T> getVectorMatrix();

    void resize(int row, int column);

private:
    size_t m_row;
    size_t m_column;
    std::map<std::pair<int, int>, T> m_map_matrix;
    std::vector<std::vector<T>> m_vector_matrix;
};

template<typename T>
KMatrixBuilder<T> *KMatrixBuilder<T>::buildMapMatrix(int row, int column, T data) {
    if (row >= m_row || column >= m_column || row < 0 || column < 0)
        std::cout << "越界错误" << std::endl;
    else
        m_map_matrix[std::pair<int, int>(row, column)] = data;
    return this;
}

template<typename T>
KMatrixBuilder<T> *KMatrixBuilder<T>::buildVectorMatrix(int row, int column, T data) {
    if (row >= m_row || column >= m_column || row < 0 || column < 0)
        std::cout << "越界错误" << std::endl;
    else
        m_vector_matrix[row][column] = data;
    return this;
}

template<typename T>
KMatrixMap<T> KMatrixBuilder<T>::getMapMatrix() {
    return KMatrixMap<T>(m_row, m_column, m_map_matrix);
}

template<typename T>
KMatrixVector<T> KMatrixBuilder<T>::getVectorMatrix() {
    return KMatrixVector<T>(m_row, m_column, m_vector_matrix);
}

template<typename T>
void KMatrixBuilder<T>::resize(int row, int column) {
    m_column = row;
    m_row = column;
    m_vector_matrix.clear();
    m_map_matrix.clear();
    for (int i = 0; i < row; ++i) {
        m_vector_matrix.push_back(std::vector<T>(column, 0));
    }
}

template<typename T>
KMatrixBuilder<T>::KMatrixBuilder(int row, int column) : m_row(row), m_column(column) {
    for (int i = 0; i < row; ++i) {
        m_vector_matrix.push_back(std::vector<T>(column, 0));
    }
}

#endif // _WEEK04_KMATRIX_BUILDER_H_
