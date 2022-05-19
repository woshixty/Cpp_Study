//
// Created by 谢庭宇 on 2022/5/20.
//

#include "Singleton.h"

int main() {
    Test::getInstance().myprint();
    Singleton<Test>::getInstance().myprint();
    return 0;
}