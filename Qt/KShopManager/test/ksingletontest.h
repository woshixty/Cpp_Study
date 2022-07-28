#ifndef KSINGLETONTEST_H
#define KSINGLETONTEST_H

#include <QObject>
#include <QTest>
#include "utils/ksingleton.h"

class KSingleTonTest : public QObject
{
    Q_OBJECT
public:

signals:


private slots:
    void case1_instance();
};

#endif // KSINGLETONTEST_H
