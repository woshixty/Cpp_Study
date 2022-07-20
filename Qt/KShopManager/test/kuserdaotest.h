#ifndef KUSERDAOTEST_H
#define KUSERDAOTEST_H

#include <QObject>
#include <QTest>

class UserDaoTest : public QObject
{
    Q_OBJECT
public:

signals:

private slots:
    void case1_update_or_insert();
};

#endif // KUSERDAOTEST_H
