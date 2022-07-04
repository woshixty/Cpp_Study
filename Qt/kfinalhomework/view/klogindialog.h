#ifndef KLOGINDIALOG_H
#define KLOGINDIALOG_H

#include <QDialog>

namespace Ui {
class KLoginDialog;
}

class KLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KLoginDialog(QWidget *parent = nullptr);
    ~KLoginDialog();

private:
    Ui::KLoginDialog *ui;
};

#endif // KLOGINDIALOG_H
