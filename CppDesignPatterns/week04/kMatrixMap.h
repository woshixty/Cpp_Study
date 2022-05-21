//
// Created by 谢庭宇 on 2022/5/18.
//

#ifndef _WEEK04_KMATRIX_MAP_H_
#define _WEEK04_KMATRIX_MAP_H_
#include "kMatrixBase.h"
#include <map>

template<typename T>
class KMatrixMap : public KMatrixBase<T>{
public:
    KMatrixMap() : KMatrixBase<T>(0, 0, mapType) {}
    KMatrixMap(KMatrixBase<T> &src) : KMatrixBase<T>(src.m_row, src.m_column, mapType) {
    }

    void setData(size_t row, size_t col, T value) override {
        if(row < 0 || row >= KMatrixBase<T>::m_row || col < 0 || col >= KMatrixBase<T>::m_column) {
            throw std::out_of_range("设置矩阵元素值越界！");
        }
    }

    T getData(size_t row, size_t col) const override {
        if(row < 0 || row >= KMatrixBase<T>::m_row || col < 0 || col >= KMatrixBase<T>::m_column) {
            throw std::out_of_range("获取矩阵元素值越界！");
        }
    }

    void eraseRow(size_t row) override {
        if(row < 0 || row >= KMatrixBase<T>::m_row) {
            throw std::out_of_range("删除矩阵行越界！");
        }
        KMatrixBase<T>::m_row--;
    }

    void eraseColumns(size_t col) override {
        if(col < 0 || col >= KMatrixBase<T>::m_row) {
            throw std::out_of_range("删除矩阵列越界！");
        }
        KMatrixBase<T>::m_column--;
    }

//    std::unique_ptr<KMatrixBase<T>> operator-(KMatrixBase<T> const &other);
//
//    std::unique_ptr<KMatrixBase<T>> operator*(KMatrixBase<T> const &other);
//
//    std::unique_ptr<KMatrixBase<T>> transpose() const;
//
//    void print() const;

    void toVectorMatrix(std::vector<std::vector<T>> &src) {
//        std::vector<std::vector<T>> res(KMatrixBase<T>::m_row, std::vector<T>(KMatrixBase<T>::m_column, (T) 0));
        typename std::map<std::pair<int, int>, T>::iterator it;
        for (it = m_matrix.begin(); it != m_matrix.end(); ++it) {
            src[it->first.first][it->first.second] = it->second;
        }
//        return res;
    }

private:
    std::map<std::pair<int, int>, T> m_matrix;

    std::map<std::pair<int, int>, T> &getMatrix();
};


#endif //WEEK04_KMATRIX_PLUS_H
