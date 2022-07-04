#ifndef KUSERDAOTEST_H
#define KUSERDAOTEST_H

#include <QObject>
#include <QTest>
#include "dao/kuserdao.h"
//#include "utils/ksingleton.h"

class KUserDaoTest : public QObject
{
    Q_OBJECT
public:

signals:

private slots:
    void case1_update_or_insert();
};


#endif // KUSERDAOTEST_H
