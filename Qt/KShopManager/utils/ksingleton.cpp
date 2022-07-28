#include "ksingleton.h"
#include <QtCore/QCoreApplication>

KSingleton *KSingleton::m_instance = 0;

KSingleton::KSingleton(): QObject(qApp)
{
}
