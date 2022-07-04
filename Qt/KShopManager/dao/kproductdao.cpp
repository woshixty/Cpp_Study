#include "kproductdao.h"

KProductDAO::KProductDAO(QObject *parent) : QObject(parent)
{
    QString aFile = "/Users/xietingyu/Desktop/Cpp_Study/Qt/KShopManager/kshoppingcentre.db3";
    if (!aFile.isEmpty()) {
        // 打开数据库
        // 添加 SQL LITE数据库驱动
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库名称
        m_db.setDatabaseName(aFile);
        // 打开数据库
        if (!m_db.open())
        {
            qDebug() << "数据库打开失败";
            QMessageBox::warning(NULL, "错误", "打开数据库失败", QMessageBox::Ok, QMessageBox::NoButton);
            return;
        }
    }
    m_query = new QSqlQuery();
    m_query_model = new QSqlQueryModel();
}

KProductDAO::~KProductDAO()
{
    if(m_query != NULL)
        delete m_query;
    if(m_query_model != NULL)
        delete m_query_model;
    if(m_db.isOpen())
        m_db.close();
}

bool KProductDAO::insertOUpdateProductdao(KProductEntity &product, ActionType type)
{
    m_query->clear();
    QString sql;
    // 先查询是更新还是插入
    switch (type) {
    case INSERT:
        sql = "INSERT INTO product "
              "(name, category, number, purchase_price, selling_price) "
              "VALUES "
              "(:name, :category, :number, :purchase_price, :selling_price);";
        break;
    case UPDATE:
        sql = "UPDATE product "
              "SET name = :name, category = :category, number = :number, "
              "purchase_price = :purchase_price, selling_price = :selling_price WHERE id = :id;";
        break;
    default:
        // 啥也不做
        break;
    }
    m_query->prepare(sql);
    m_query->bindValue(":name", product.getName());
    m_query->bindValue(":category", product.getCategary());
    m_query->bindValue(":number", product.getNumber());
    m_query->bindValue(":purchase_price", product.getPurchasePrice());
    m_query->bindValue(":selling_price", product.getSellingPrice());
    m_query->bindValue(":id", product.getId());
    m_query->exec();
    return m_query->isActive();
}

bool KProductDAO::deleteProductdao(int id)
{
    m_query->clear();
    QString sql = "DELETE FROM product WHERE id = :id";
    m_query->prepare(sql);
    m_query->bindValue(":id", id);
    m_query->exec();
    return m_query->isActive();
}

KProductEntity KProductDAO::selectProductdao(int id)
{
    m_query_model->clear();
    QString sql = "SELECT * FROM product WHERE id = " + QString::number(id);
    m_query_model->setQuery(sql);
    KProductEntity result;
    for(int i = 0; i < m_query_model->rowCount(); i++)
    {
        QSqlRecord qrecord = m_query_model->record(i);
        // 注意顺序！
        result.setId(qrecord.field(0).value().toInt());
        result.setName(qrecord.field(1).value().toString());
        result.setCategary(qrecord.field(2).value().toInt());
        result.setNumber(qrecord.field(3).value().toInt());
        result.setPurchasePrice(qrecord.field(4).value().toDouble());
        result.setSellingPrice(qrecord.field(5).value().toDouble());
    }
    return result;
}

QList<QMap<QString, QString>> KProductDAO::selectProductListByCategory(int category)
{
    m_query_model->clear();
    QList<QMap<QString, QString>> result;
    QString sql = "SELECT * FROM product WHERE category = " + QString::number(category);
    m_query_model->setQuery(sql);
    for(int i = 0; i < m_query_model->rowCount(); i++)
    {
        QSqlRecord qrecord = m_query_model->record(i);
        // 注意顺序！
        QMap<QString, QString> temp;
        temp.insert("id", qrecord.field(0).value().toString());
        temp.insert("name", qrecord.field(1).value().toString());
        temp.insert("category", qrecord.field(2).value().toString());
        temp.insert("number", qrecord.field(3).value().toString());
        temp.insert("m_purchase_price", qrecord.field(4).value().toString());
        temp.insert("m_selling_price", qrecord.field(5).value().toString());
        result.append(temp);
    }
    m_query_model->submit();
    return result;
}
