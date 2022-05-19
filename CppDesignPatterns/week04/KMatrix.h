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
    // 空构造函数
    KMatrix();

    // 拷贝构造函数
    KMatrix(KMatrix<T> &src);

    // 构造 0 矩阵
    KMatrix(int row, int column);

    // 使用数组构造矩阵
    KMatrix(int row, int column, T *src);

    // 使用矩阵构造矩阵
    KMatrix(vector<vector<T>> src, int row, int column);

    // 初始化行列信息赋值为0
    void init(int row, int column);

    // 初始化行列信息并赋值
    void init(int row, int column, T *src);

    // 获得行
    int getRows() const;

    // 获得列
    int getCols() const;

    // 设置值
    void setData(int row, int col, T value);

    // 得到值
    T getData(int row, int col) const;

    // 删除行
    void eraseRow(int row);

    // 加
    friend KMatrix<T>* operator+(KMatrix<T> a, KMatrix<T> b) {
        // TODO 判断能否相加
        vector<vector<T>> newMatrix;
        for (int i = 0; i < a.row; ++i) {
            vector<T> newRow;
            for (int j = 0; j < a.column; ++j) {
                newRow.push_back(a.matrix[i][j] + b.matrix[i][j]);
            }
            newMatrix.push_back(newRow);
        }
        KMatrix<T> *result = new KMatrix<T>(newMatrix, a.row, a.column);
        return result;
    }

    // 减
    friend KMatrix<T> operator-(KMatrix<T> a, KMatrix<T> b);

    // 乘
    friend KMatrix<T> operator*(KMatrix<T> a, KMatrix<T> b);

    // 转置
    KMatrix<T>* transpose();

    // 输出
    void print() const;

private:
    int row, column;

    vector<vector<T>> matrix;

    vector<vector<T>> &getMatrix();
};

template<typename T>
KMatrix<T> operator-(KMatrix<T> a, KMatrix<T> b) {
    // TODO 判断能否相减
    return KMatrix<T>();
}

template<typename T>
KMatrix<T> operator*(KMatrix<T> a, KMatrix<T> b) {
    // TODO 判断能否相乘
    return KMatrix<T>();
}


#endif //CPPDESIGNPATTERNS_KMATRIX_H
