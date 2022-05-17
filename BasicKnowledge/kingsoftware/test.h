//
// Created by 谢庭宇 on 2022/5/17.
//

#ifndef BASICKNOWLEDGE_TEST_H
#define BASICKNOWLEDGE_TEST_H

template<typename T>
class Test {
public:
    bool deleteEle(T data);
};

template<typename T>
T doSum(T a, T b) {
    T temp = a + b;
    return temp;
}


#endif //BASICKNOWLEDGE_TEST_H
