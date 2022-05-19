//
// Created by 谢庭宇 on 2022/5/19.
//

#ifndef CPPDESIGNPATTERNS_TEST_H
#define CPPDESIGNPATTERNS_TEST_H

template<typename T>
class Test {
public:
    T data;
    Test(T *data) : data(*data) {}

};


#endif //CPPDESIGNPATTERNS_TEST_H
