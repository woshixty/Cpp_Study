#ifndef KEMPLOYEEINFORMATION_H
#define KEMPLOYEEINFORMATION_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class KEmployeeInformation;
}

class KEmployeeInformation : public QWidget
{
    Q_OBJECT

public:
    explicit KEmployeeInformation(QWidget *parent = nullptr);
    ~KEmployeeInformation();
    void setUserTableModel(QSqlTableModel *model);
    void initPage();

private:
    Ui::KEmployeeInformation *ui;
};

#endif // KEMPLOYEEINFORMATION_H
