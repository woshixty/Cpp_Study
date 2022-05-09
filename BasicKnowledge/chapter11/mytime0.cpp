//
// Created by 谢庭宇 on 2022/5/6.
//

#include "mytime0.h"

Time::Time() {

}

Time::Time(int h, int m) {

}

void Time::AddMin(int m) {

}

void Time::AddHr(int h) {

}

void Time::Reset(int h, int m) {

}

Time Time::Sum(const Time &t) const {
    return Time();
}

void Time::Show() const {

}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator*(const Time &t, double m) {
    return Time();
}

ostream &  operator<<(ostream &os, const Time & t) {
    os << t.hours << t.minutes;
}
