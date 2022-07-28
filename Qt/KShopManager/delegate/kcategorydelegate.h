#ifndef KCATEGORYDELEGATE_H
#define KCATEGORYDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QLineEdit>

class KCategoryDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit KCategoryDelegate(QObject *parent = nullptr);
    QString getProductCatogory(int category);
    // 需要实现以下四个函数
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const Q_DECL_OVERRIDE;

    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const Q_DECL_OVERRIDE;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
    bool m_is_edit = false;
};

#endif // KCATEGORYDELEGATE_H
