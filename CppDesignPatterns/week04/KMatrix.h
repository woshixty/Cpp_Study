//
// Created by 谢庭宇 on 2022/5/18.
//

#ifndef CPPDESIGNPATTERNS_KMATRIX_H
#define CPPDESIGNPATTERNS_KMATRIX_H

#include <vector>

using namespace std;

template<typename T>
class KMatrix {
public:
    // 初始化行列信息
    void init(int row, int column);

    // 获得行
    int getRows() const;

    // 获得列
    int getCols();

    // 设置值
    void setData(int row, int col, T value);

    // 得到值
    T getData(int row, int col);

    // 删除行
    void eraseRow(int row);

    // 加
    friend KMatrix<T> operator+(KMatrix<T> a, KMatrix<T> b);

    // 减
    friend KMatrix<T> operator-(KMatrix<T> a, KMatrix<T> b);

    // 乘
    friend KMatrix<T> operator*(KMatrix<T> a, KMatrix<T> b);

    // 转置
    KMatrix<T> transpose() const;

    // 输出
    void print() const;

private:
    vector<vector<T>> matrix;

    vector<vector<T>> &getMatrix();
};


#endif //CPPDESIGNPATTERNS_KMATRIX_H
