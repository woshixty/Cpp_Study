//
// Created by 谢庭宇 on 2022/5/20.
//

#ifndef CPPDESIGNPATTERNS_SINGLETON_H
#define CPPDESIGNPATTERNS_SINGLETON_H

#include<iostream>

template<typename T>

class Singleton {
public:
    static T &getInstance() {
        static T t;
        return t;
    }

    Singleton(const Singleton &) = delete;

    Singleton &operator=(const Singleton &) = delete;

protected:
    Singleton() = default;

    ~Singleton() = default;
};

class Test : public Singleton<Test> {
public:
    void myprint() {
        std::cout << "test Singleton" << std::endl;
    }
};

class Test2
{
public:
    void myprint()
    {
        std::cout<<"test Singleton"<<std::endl;
    }
};


#endif //CPPDESIGNPATTERNS_SINGLETON_H
