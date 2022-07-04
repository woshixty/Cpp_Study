#ifndef KPRODUCTDAO_H
#define KPRODUCTDAO_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlField>
#include "utils/kconstants.h"
#include "entity/kproductentity.h"

class KProductDAO : public QObject
{
    Q_OBJECT

public:
    explicit KProductDAO(QObject *parent = nullptr);
    ~KProductDAO();
    bool insertOUpdateProductdao(KProductEntity &product, ActionType type);
    bool deleteProductdao(int id);
    KProductEntity selectProductdao(int id);
    QList<QMap<QString, QString>> selectProductListByCategory(int category);

signals:

private:
    QSqlDatabase m_db;
    QSqlQuery *m_query;
    QSqlQueryModel *m_query_model;
};

#endif // KPRODUCTDAO_H
