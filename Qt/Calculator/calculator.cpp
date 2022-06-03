#include "calculator.h"
#include <qdebug.h>

Calculator::Calculator(ScreenEdit& scr):
    screen(scr),
    currNum(0),
    leftCount(0),
    endWithP(false),
    state(NUM_ECHO_STAT)
{
    expression.restart();
}

void Calculator::numberBtn(int num)
{
    switch (state)
    {
    case INPUTING_STAT:
        currNum = screen.appendScreenNum(num);
        break;
    case NUM_ECHO_STAT:
        currNum = screen.setScreenNum(num);
        if (currNum != 0) state = INPUTING_STAT;
        break;
    case ERROR_STAT:
        clearBtn();
        currNum = screen.setScreenNum(num);
        state = INPUTING_STAT;
        break;
    default:
        break;
    }
}

void Calculator::dotBtn()
{
    switch (state)
    {
    case INPUTING_STAT:
        currNum = screen.appendDot();
        break;
    case NUM_ECHO_STAT:
        screen.clearScreenNum();
        currNum = screen.appendDot();
        state = INPUTING_STAT;
        break;
    case ERROR_STAT:
        clearBtn();
        currNum = screen.appendDot();
        state = INPUTING_STAT;
        break;
    default:
        break;
    }
}

int Calculator::operatorBtn(QChar ope)
{
    if (ope == QChar('('))
    {
        if (endWithP)
        {
            expression.restart();
            leftCount = 0;
            state = NUM_ECHO_STAT;
            screen.clearExp();
        }
        expression.operate(opeTranslate('('));
        screen.appendExpOpe('(');
        leftCount++;
        endWithP = false;
        if (leftCount == 1) return 1;
        else return 0;
    }

    int calState;

    if (ope == QChar(')'))
    {
        if (leftCount - 1 >= 0)
        {
            if (!endWithP)
            {
                screen.appendExpNum(currNum);
                expression.appendNum(currNum);
            }
            screen.appendExpOpe(')');
            expression.operate(opeTranslate(')'));
            calState = expression.getState();
            if (calState != Expression::CALCULATING)
            {
                if (calState == Expression::DIV_BY_ZERO)
                    screen.setScreenStr("除数不能为零");
                else if (calState == Expression::RES_NOT_DEF)
                    screen.setScreenStr("结果未定义");
                screen.appendExpOpe('=');
                state = ERROR_STAT;
                return 2;
            }

            currNum = screen.setScreenNum(expression.getResult());
            state = NUM_ECHO_STAT;
            leftCount--;
            endWithP = true;
            if (leftCount == 0) return 1;
        }
        endWithP = true;
        return 0;
    }

    switch (state)
    {
    case INPUTING_STAT: // 大部分同下
        state = NUM_ECHO_STAT;
    case NUM_ECHO_STAT:
        if (endWithP)
        {
            expression.operate(opeTranslate(ope));
            screen.appendExpOpe(ope);
        }
        else
        {
            expression.append(currNum, opeTranslate(ope));

            calState = expression.getState();
            if (calState != Expression::CALCULATING)
            {
                if (calState == Expression::DIV_BY_ZERO)
                    screen.setScreenStr("除数不能为零");
                else if (calState == Expression::RES_NOT_DEF)
                    screen.setScreenStr("结果未定义");
                screen.appendExpOpe('=');
                state = ERROR_STAT;
                return 1;
            }

            screen.appendExpNum(currNum).appendExpOpe(ope);
            currNum = screen.setScreenNum(expression.getResult());
        }
        break;
    case ERROR_STAT: // 不可达状态
    default:
        break;
    }
    endWithP = false;

    return 0;
}

int Calculator::equalBtn()
{
    int calState;
    int isErr = 0;
    switch (state)
    {
    case INPUTING_STAT: // 同下
    case NUM_ECHO_STAT:
        if (!endWithP && leftCount == 0)
        {
            screen.appendExpNum(currNum);
            expression.appendNum(currNum);
        }
        while (leftCount > 0)
        {
            if (operatorBtn(')') == 2)
            {
                return 1;
            }
        }
        calState = expression.finish();
        if (calState == Expression::OK)
        {
            currNum = screen.setScreenNum(expression.getResult());
            screen.appendExpOpe('=');
            state = NUM_ECHO_STAT;
        }
        else if (calState == Expression::EMPTY_EXPR)
        {
            state = NUM_ECHO_STAT;
        }
        else
        {
            if (calState == Expression::DIV_BY_ZERO)
                screen.setScreenStr("除数不能为零");
            else if (calState == Expression::RES_NOT_DEF)
                screen.setScreenStr("结果未定义");
            screen.appendExpOpe('=');
            state = ERROR_STAT;
            isErr = 1;
        }

        expression.restart();
        leftCount = 0;
        endWithP = false;
        break;
    case ERROR_STAT:
        clearBtn();
        break;
    default:
        break;
    }

    return isErr;
}

void Calculator::clearBtn()
{
    expression.restart();
    screen.clear();
    currNum = 0;
    leftCount = 0;
    endWithP = false;
    state = NUM_ECHO_STAT;
}

void Calculator::backspaceBtn()
{
    switch (state)
    {
    case INPUTING_STAT:
        currNum = screen.backspace();
        if (currNum == 0) state = NUM_ECHO_STAT;
        break;
    case NUM_ECHO_STAT:
        currNum = screen.backspace();
        if (currNum != 0) state = INPUTING_STAT;
        break;
    case ERROR_STAT:
        clearBtn();
        break;
    default:
        break;
    }
}

char Calculator::opeTranslate(QChar ope)
{
    if (ope == QChar(L'×')) return '*';
    if (ope == QChar(L'÷')) return '/';
    return ope.toLatin1();
}

