//
// Created by 谢庭宇 on 2022/5/18.
//

#include "KMatrix.h"
#include <iostream>

using namespace std;

template<typename T>
KMatrix<T>::KMatrix() :row(0), column(0) {

}

template<typename T>
KMatrix<T>::KMatrix(KMatrix<T> &src) :row(src.row), column(src.column) {
    // 拷贝的matrix
    matrix = src.getMatrix();
}

template<typename T>
KMatrix<T>::KMatrix(int row, int column) :row(row), column(column) {
    // 向matrix中放入row个容量为column的vector
    for (int i = 0; i < row; ++i) {
        matrix.push_back(vector<T>(column, (T) 0));
    }
}

template<typename T>
KMatrix<T>::KMatrix(int row, int column, T *src) :row(row), column(column) {
    int base = 0;
    for (int i = 0; i < row; ++i) {
        // 将第i行数据拷贝进去
        matrix.push_back(vector<T>(&src[base], &src[base + column]));
        base += column;
    }
}

template<typename T>
KMatrix<T>::KMatrix(vector<vector<T>> src, int row, int column) {
    this->row = row;
    this->column = column;
    for (int i = 0; i < row; ++i) {
        matrix.push_back(vector<T>(src[i]));
    }
}

template<typename T>
void KMatrix<T>::init(int row, int column) {
    // 向matrix中放入row个容量为column的vector
    matrix.clear();
    this->row = row;
    this->column = column;
    for (int i = 0; i < row; ++i) {
        matrix.push_back(vector<T>(column, (T) 0));
    }
}

template<typename T>
void KMatrix<T>::init(int row, int column, T *src) {
    // 先清空，再初始化
    matrix.clear();
    this->row = row;
    this->column = column;
    int base = 0;
    for (int i = 0; i < row; ++i) {
        // 将第i行数据拷贝进去
        matrix.push_back(vector<T>(&src[base], &src[base + column]));
        base += column;
    }
}

template<typename T>
inline int KMatrix<T>::getRows() const {
    return row;
}

template<typename T>
inline int KMatrix<T>::getCols() const {
    return column;
}

template<typename T>
void KMatrix<T>::setData(int row, int col, T value) {
    // TODO 超界判断
    matrix[row][col] = value;
}

template<typename T>
T KMatrix<T>::getData(int row, int col) const {
    // TODO 超界判断
    return matrix[row][col];
}

template<typename T>
void KMatrix<T>::eraseRow(int row) {
    // TODO 超界判断
    matrix.erase(matrix.begin() + row);
    this->row--;
}

template<typename T>
KMatrix<T>* KMatrix<T>::transpose() {
    // 交换行列值
    vector<vector<T>> data;
    for (int i = 0; i < column; ++i) {
        vector<T> currRow;
        for (int j = 0; j < row; ++j) {
            currRow.push_back(matrix[j][i]);
        }
        data.push_back(currRow);
    }
    KMatrix<T> *result = new KMatrix<T>(data, column, row);
    return result;
}

template<typename T>
void KMatrix<T>::print() const {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

template<typename T>
vector<vector<T>> &KMatrix<T>::getMatrix() {
    // 拷贝一份matrix返回
    return matrix;
}

//template<typename T>
//KMatrix<T> operator+(KMatrix<T> a, KMatrix<T> b)
