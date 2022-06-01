#include "expression.h"

Expression::Expression() : state(0) {}

const char Expression::PRIORITY[7][7] = {
//  +   -   *   /   (   )   #
  {'>','>','<','<','<','>','>'},  // +
  {'>','>','<','<','<','>','>'},  // -
  {'>','>','>','>','<','>','>'},  // *
  {'>','>','>','>','<','>','>'},  // /
  {'<','<','<','<','<','=','0'},  // (
  {'>','>','>','>','0','>','>'},  // )
  {'<','<','<','<','<','0','='}   // #
};

Expression &Expression::restart()
{
    while (!operandStk.empty()) operandStk.pop();
    while (!operatorStk.empty()) operatorStk.pop();

    operatorStk.push('#');
    state = CALCULATING;
    return *this;
}

int Expression::finish()
{
    if (state != CALCULATING) return state;
    if (operandStk.empty())
    {
        state = EMPTY_EXPR;
        return state;
    }
    operate('#');
    return state;
}

double Expression::getResult()
{
    return operandStk.top();
}

int Expression::getState()
{
    return state;
}

Expression &Expression::append(double num, char ope)
{
    if (state != CALCULATING) return *this;
    operandStk.push(num);
    operate(ope);
    return *this;
}

Expression &Expression::appendNum(double num)
{
    if (state != CALCULATING) return *this;
    operandStk.push(num);
    return *this;
}

Expression& Expression::operate(char ope)
{
    if (state != CALCULATING) return *this;
    double num1, num2;
    char lastOpe;
    switch (procede(operatorStk.top(), ope))
    {
    case '>':
        num1 = operandStk.top();
        operandStk.pop();
        num2 = operandStk.top();
        operandStk.pop();
        lastOpe = operatorStk.top();
        operatorStk.pop();

        if (num1 == 0 && num2 == 0 && lastOpe == '/')
        {
            state = RES_NOT_DEF;
            return *this;
        }
        else if (num1 == 0 && lastOpe == '/')
        {
            state = DIV_BY_ZERO;
            return *this;
        }

        operandStk.push(calculate(num1, num2, lastOpe));
        operate(ope);
        break;
    case '=':
        operatorStk.pop();
        break;
    case '<':
        operatorStk.push(ope);
        break;
    default:
        state = BAD_EXPR;
        return *this;
    }

    if (operatorStk.empty()) state = OK;
    return *this;
}

char Expression::procede(char a, char b)
{
    int i,j;

    switch(a)
    {
    case'+': i=0; break;
    case'-': i=1; break;
    case'*': i=2; break;
    case'/': i=3; break;
    case'(': i=4; break;
    case')': i=5; break;
    case'#': i=6; break;
    }
    switch(b)
    {
    case'+': j=0; break;
    case'-': j=1; break;
    case'*': j=2; break;
    case'/': j=3; break;
    case'(': j=4; break;
    case')': j=5; break;
    case'#': j=6; break;
    }

    return PRIORITY[i][j];
}

double Expression::calculate(double num1, double num2, char ope)
{
    switch (ope)
    {
    case '+':
        return num2 + num1;
    case '-':
        return num2 - num1;
    case '*':
        return num2 * num1;
    case '/':
        return num2 / num1;
    default:
        return 0;
    }
}
