#include "screenedit.h"
#include "ui_screenedit.h"

ScreenEdit::ScreenEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScreenEdit),
    realNum(0.0),
    isExpEnd(false)
{
    ui->setupUi(this);
    QFont font = ui->mainEdit->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing, 3);
    ui->mainEdit->setFont(font);
}

ScreenEdit::~ScreenEdit()
{
    delete ui;
}

QString ScreenEdit::trimToStr(double num)
{
    QString src = QString::number(num, 'f', TXT_MAX_LEN - 1).mid(0, TXT_MAX_LEN);
    if (!src.contains('.'))
        return src;
    auto it = src.rbegin();
    int len = src.length();
    for (; it != src.rend() && *it == '0'; it++, len--);
    if (src.at(len - 1) == '.')
        len--;
    return src.mid(0, len);
}

double ScreenEdit::getScreenNum() const
{
    return realNum;
}

double ScreenEdit::setScreenNum(double num)
{
    ui->mainEdit->setText(trimToStr(num));
    realNum = ui->mainEdit->text().toDouble();
    return realNum;
}

void ScreenEdit::setScreenStr(QString str)
{
    ui->mainEdit->setText(str);
    realNum = 0;
}

double ScreenEdit::appendScreenNum(uint num)
{
    QString old = ui->mainEdit->text();
    if (old.length() >= TXT_MAX_LEN)
        return realNum;

    QString str = old.append(QString::number(num));
    ui->mainEdit->setText(str);
    realNum = str.toDouble();
    return realNum;
}

double ScreenEdit::appendDot()
{
    QString old = ui->mainEdit->text();
    if (old.length() >= TXT_MAX_LEN || old.contains('.'))
        return realNum;

    ui->mainEdit->setText(old.append('.'));
    return realNum;
}

double ScreenEdit::backspace()
{
    QString old = ui->mainEdit->text();
    QString backed = old.mid(0, old.length() - 1);
    if (backed.isEmpty() || backed == "0." || backed == "-") backed = "0";
    ui->mainEdit->setText(backed);
    realNum = backed.toDouble();
    return realNum;
}

ScreenEdit &ScreenEdit::appendExpNum(double num)
{
    if (isExpEnd)
    {
        clearExp();
        isExpEnd = false;
    }

    QString old = ui->expEdit->text();
    ui->expEdit->setText(old.append(' ').append(trimToStr(num)));
    return *this;
}

ScreenEdit &ScreenEdit::appendExpOpe(QChar ope)
{
    if (isExpEnd)
    {
        clearExp();
        isExpEnd = false;
    }
    if (ope == QChar('=')) isExpEnd = true;

    QString old = ui->expEdit->text();
    ui->expEdit->setText(old.append(' ').append(ope));
    return *this;
}

void ScreenEdit::clearScreenNum()
{
    ui->mainEdit->clear();
    ui->mainEdit->setText("0");
    realNum = 0.0;
}

void ScreenEdit::clearExp()
{
    ui->expEdit->clear();
}

void ScreenEdit::clear()
{
    clearScreenNum();
    clearExp();
}




