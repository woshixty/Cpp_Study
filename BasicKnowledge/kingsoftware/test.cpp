//
// Created by 谢庭宇 on 2022/5/17.
//

#include "test.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int a[6] = {26, 5, 76, 1, 6, 3};
    vector<int, allocator<int>> vi(a, a + 6);
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));
}

template<typename T>
bool Test<T>::deleteEle(T data) {
    cout << data << endl;
    return false;
}