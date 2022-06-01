// --------------------------------------------------------
// expression.h
// 创建者： Tian
// 创建时间： 2022/5/23
// 表达式类，封装了表达式求值的逻辑
// --------------------------------------------------------
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stack>

class Expression
{
public:
    Expression();

    Expression& restart(void);                  // 重置状态，开始运算
    int         finish(void);                   // 最终运算，并返回状态
    double      getResult(void);                // 获取计算结果，应在finish后调用
    int         getState(void);                 // 获取当前状态
    Expression& operate(char ope);              // 入栈操作
    Expression& append(double num, char ope);   // 追加运算
    Expression& appendNum(double num);          // 追加操作数

    static const int  CALCULATING   =  0; // 计算过程中
    static const int  OK            =  1; // 计算成功
    static const int  EMPTY_EXPR    =  2; // 空表达式
    static const int  RES_NOT_DEF   = -1; // 结果未定义
    static const int  DIV_BY_ZERO   = -2; // 除数不能为零
    static const int  BAD_EXPR      = -3; // 错误表达式

private:
    std::stack<double> operandStk;  // 操作数栈
    std::stack<char>   operatorStk; // 运算符栈
    int                state;       // 计算状态

    static const char PRIORITY[7][7]; // 运算符优先关系表

    static char   procede(char a, char b);                       // 比较两运算符优先级
    static double calculate(double num1, double num2, char ope); // 通过运算符计算
};

#endif // EXPRESSION_H
