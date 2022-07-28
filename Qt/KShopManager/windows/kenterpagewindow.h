#ifndef KENTERPAGEWINDOW_H
#define KENTERPAGEWINDOW_H

#include <QWidget>

namespace Ui {
class KEnterPageWindow;
}

class KEnterPageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit KEnterPageWindow(QWidget *parent = nullptr);
    ~KEnterPageWindow();

private:
    Ui::KEnterPageWindow *ui;
};

#endif // KENTERPAGEWINDOW_H
