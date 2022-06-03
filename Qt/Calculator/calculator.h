// --------------------------------------------------------
// calculator.h
// 创建者： Tian
// 创建时间： 2022/5/23
// 计算器类，封装了计算器逻辑部分
// --------------------------------------------------------
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <screenedit.h>
#include <expression.h>
#include <QChar>

class Calculator
{
public:
    Calculator(ScreenEdit& scr);

    void numberBtn(int num);     // 数字按键按
    void dotBtn(void);           // 点按键
    int  operatorBtn(QChar ope); // 运算符按键，当操作需要改变按键状态时，返回1，否则返回0
    int  equalBtn(void);         // 等于按键，当操作需要改变按键状态时，返回1，否则返回0
    void clearBtn(void);         // 清除按键
    void backspaceBtn(void);     // 回退按键

    static const int INPUTING_STAT  =  1; // 数字输入状态
    static const int NUM_ECHO_STAT  =  0; // 数字回显状态
    static const int ERROR_STAT     = -1; // 错误计算状态

private:
    ScreenEdit& screen;     // 屏幕
    Expression  expression; // 表达式求解器

    double currNum;    // 当前数字
    int    leftCount;  // 括号数差
    bool   endWithP;   // 是否以右括号结尾
    int    state;      // 计算器状态

    static char opeTranslate(QChar ope); // 转换运算符
};

#endif // CALCULATOR_H
