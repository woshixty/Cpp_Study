#include "keyboardwidget.h"
#include "ui_keyboardwidget.h"

KeyboardWidget::KeyboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyboardWidget),
    isOpeDisabled(false),
    isParentheseEnabled(false)
{
    ui->setupUi(this);
}

KeyboardWidget::~KeyboardWidget()
{
    delete ui;
}

void KeyboardWidget::disableOpeBtn()
{
    ui->addButton->setDisabled(true);
    ui->minusButton->setDisabled(true);
    ui->divideButton->setDisabled(true);
    ui->timesButton->setDisabled(true);
    ui->parentheseLeftButton->setDisabled(true);
    ui->parentheseRightButton->setDisabled(true);
    isOpeDisabled = true;
}

void KeyboardWidget::enableOpeBtn()
{
    ui->addButton->setDisabled(false);
    ui->minusButton->setDisabled(false);
    ui->divideButton->setDisabled(false);
    ui->timesButton->setDisabled(false);
    ui->parentheseLeftButton->setDisabled(false);
    ui->parentheseRightButton->setDisabled(false);
    isOpeDisabled = false;
}

void KeyboardWidget::setCalculator(Calculator *cal)
{
    calculator = cal;
}

void KeyboardWidget::on_parentheseLeftButton_clicked()
{
    if (calculator->operatorBtn(QChar('(')))
    {
        ui->parentheseRightButton->setDisabled(false);
        isParentheseEnabled = true;
    }
}

void KeyboardWidget::on_parentheseRightButton_clicked()
{
    int returnCode = calculator->operatorBtn(QChar(')'));
    if (returnCode == 1)
    {

        ui->parentheseRightButton->setDisabled(true);
        isParentheseEnabled = false;
    }
    else if (returnCode == 2)
    {
        isOpeDisabled = true;
        disableOpeBtn();
    }
}

void KeyboardWidget::on_clearButton_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    isParentheseEnabled = false;
    ui->parentheseRightButton->setDisabled(true);
    calculator->clearBtn();
}

void KeyboardWidget::on_backspaceButton_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->backspaceBtn();
}

void KeyboardWidget::on_num7Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(7);
}

void KeyboardWidget::on_num8Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(8);
}

void KeyboardWidget::on_num9Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(9);
}

void KeyboardWidget::on_addButton_clicked()
{
    if(calculator->operatorBtn(QChar('+')))
    {
        isOpeDisabled = true;
        disableOpeBtn();
    }
}

void KeyboardWidget::on_num4Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(4);
}

void KeyboardWidget::on_num5Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(5);
}

void KeyboardWidget::on_num6Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(6);
}

void KeyboardWidget::on_minusButton_clicked()
{
    if (calculator->operatorBtn(QChar('-')))
    {
        isOpeDisabled = true;
        disableOpeBtn();
    }
}

void KeyboardWidget::on_num1Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(1);
}

void KeyboardWidget::on_num2Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(2);
}

void KeyboardWidget::on_num3Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(3);
}

void KeyboardWidget::on_timesButton_clicked()
{
    if (calculator->operatorBtn(QChar(L'×')))
    {
        isOpeDisabled = true;
        disableOpeBtn();
    }
}

void KeyboardWidget::on_dotButton_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->dotBtn();
}

void KeyboardWidget::on_num0Button_clicked()
{
    if (isOpeDisabled) enableOpeBtn();
    calculator->numberBtn(0);
}

void KeyboardWidget::on_divideButton_clicked()
{
    if(calculator->operatorBtn(QChar(L'÷')))
    {
        isOpeDisabled = true;
        disableOpeBtn();
    }
}

void KeyboardWidget::on_calculateButton_clicked()
{
    if (calculator->equalBtn())
    {
        if (isOpeDisabled)
        {
            enableOpeBtn();
            if (!isParentheseEnabled)
            {
                ui->parentheseRightButton->setDisabled(true);
            }
        }
        else
        {
            disableOpeBtn();
        }
    }
}
