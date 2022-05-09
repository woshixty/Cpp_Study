//
// Created by 谢庭宇 on 2022/5/6.
//

#ifndef BASICKNOWLEDGE_MYTIME0_H
#define BASICKNOWLEDGE_MYTIME0_H
#include <ostream>

using namespace std;
class Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time & t) const;
    Time operator+(const Time & t) const;
    void Show() const;
    friend Time operator*(const Time & t, double m);
    friend ostream & operator<<(ostream & os, const Time & t);
};


#endif //BASICKNOWLEDGE_MYTIME0_H
