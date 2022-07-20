//
// Created by 谢庭宇 on 2022/5/29.
//

#include <memory>
#include <string>

using namespace std;
int main() {
    shared_ptr<string> p1;
    if(p1 && p1->empty())
        *p1 = "hi";
    string pp = reinterpret_cast<const char *>(p1.get());
}

