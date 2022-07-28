#ifndef KSINGLETON_H
#define KSINGLETON_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include "dao/kproductdao.h"
#include "dao/kuserdao.h"

class KSingleton : public QObject
{
    Q_OBJECT
public:
//    static KProductDAO* m_product_dao;
//    static KUserDAO* m_user_dao;
    static KSingleton* instance()
    {
        static QMutex mutex;
        if (m_instance == nullptr) {
            QMutexLocker locker(&mutex);
            if (!m_instance)
                m_instance = new KSingleton();
        }
        return m_instance;
    }

    static KProductDAO* instanceOfProductDao(QObject *parent = nullptr)
    {
        static QMutex mutex;
        if (m_product_dao == nullptr) {
            QMutexLocker locker(&mutex);
            if (!m_product_dao)
                m_product_dao = new KProductDAO(parent);
        }
        return m_product_dao;
    }

    static KUserDAO* instanceOfUserDao(QObject *parent = nullptr)
    {
        static QMutex mutex;
        if (m_user_dao == nullptr) {
            QMutexLocker locker(&mutex);
            if (!m_user_dao)
                m_user_dao = new KUserDAO(parent);
        }
        return m_user_dao;
    }

signals:

private:
    KSingleton();
    static KSingleton* m_instance;
    static KProductDAO* m_product_dao;
    static KUserDAO* m_user_dao;
};

#endif // KSINGLETON_H
