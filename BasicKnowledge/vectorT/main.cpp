//
// Created by 谢庭宇 on 2022/5/18.
//
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 创建vector
    vector<int> v1;
    vector<int> v2(v1);
    vector<int> v3(10, -1);
    vector<string> v4(10, "hi");

    int a[5] = {1, 2, 3, 4, 5};
    // 本质为一个模板类
    // 半开区间：[&a[0], &a[5])
    vector<int> vt(&a[0], &a[5]);
    // 1 第一个元素
    cout << "first data = " << vt.front() << endl;
    // 2 最后一个元素
    cout << "last data = " << vt.back() << endl;
    // 3 元素个数
    cout << "data size = " << vt.size() << endl;
    // 4 输出数组
    for (int i = 0; i < vt.size(); ++i)
    {
        cout << vt[i] << " ";
    }
    cout << endl;

    vector<int>::iterator it;
    for(it = vt.begin(); it != vt.end(); ++it)
    {
        cout << *it << endl;
    }
}