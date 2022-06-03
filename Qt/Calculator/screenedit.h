// --------------------------------------------------------
// screenedit.h
// 创建者： Tian
// 创建时间： 2022/5/23
// 屏幕类，封装了计算器屏幕的对应操作
// --------------------------------------------------------
#ifndef SCREENEDIT_H
#define SCREENEDIT_H

#include <QWidget>

namespace Ui {
class ScreenEdit;
}

class ScreenEdit : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenEdit(QWidget *parent = 0);
    ~ScreenEdit();

    double getScreenNum(void) const;        // 获取屏幕实际数
    double setScreenNum(double num);        // 设置屏幕数字，返回设置后的实际数
    void   setScreenStr(QString str);       // 设置屏幕显示字符串
    double appendScreenNum(uint num);       // 在屏幕数字后追加一个数字，返回追加后的实际数
    double appendDot(void);                 // 在屏幕数字后追加小数点
    double backspace(void);                 // 回退一个数字

    ScreenEdit& appendExpNum(double num);   // 表达式追加一个数字
    ScreenEdit& appendExpOpe(QChar ope);    // 表达式追加一个操作符

    void   clearScreenNum(void);            // 清空屏幕数字
    void   clearExp(void);                  // 清空表达式
    void   clear(void);                     // 清空所有屏幕

private:
    Ui::ScreenEdit *ui;

    double realNum; // 屏幕数字的实际数
    bool   isExpEnd;// 表达式是否终结

    static const int TXT_MAX_LEN =   12;   // 屏幕显示最长字数

    static QString trimToStr(double num);  // 将double转为字符串，并且去掉多余的零
};

#endif // SCREENEDIT_H
