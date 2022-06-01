// --------------------------------------------------------
// keyboardwidget.h
// 创建者： Tian
// 创建时间： 2022/5/24
// 计算器键盘类，封装了信号槽调用关系及按键UI操作
// --------------------------------------------------------
#ifndef KEYBOARDWIDGET_H
#define KEYBOARDWIDGET_H

#include <QWidget>
#include <calculator.h>

namespace Ui {
class KeyboardWidget;
}

class KeyboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KeyboardWidget(QWidget *parent = 0);
    ~KeyboardWidget();

    void setCalculator(Calculator* cal); // 设置计算器类

private slots:
    void on_parentheseLeftButton_clicked();
    void on_parentheseRightButton_clicked();
    void on_clearButton_clicked();
    void on_backspaceButton_clicked();
    void on_num7Button_clicked();
    void on_num8Button_clicked();
    void on_num9Button_clicked();
    void on_addButton_clicked();
    void on_num4Button_clicked();
    void on_num5Button_clicked();
    void on_num6Button_clicked();
    void on_minusButton_clicked();
    void on_num1Button_clicked();
    void on_num2Button_clicked();
    void on_num3Button_clicked();
    void on_timesButton_clicked();
    void on_dotButton_clicked();
    void on_num0Button_clicked();
    void on_divideButton_clicked();
    void on_calculateButton_clicked();

private:
    Ui::KeyboardWidget *ui;

    Calculator* calculator;
    bool        isOpeDisabled;
    bool        isParentheseEnabled;

    void disableOpeBtn(void);   // 取消运算符按钮
    void enableOpeBtn(void);    // 使能运算符按钮
};

#endif // KEYBOARDWIDGET_H
