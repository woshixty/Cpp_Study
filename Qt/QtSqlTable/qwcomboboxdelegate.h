#ifndef QWCOMBOBOXDELEGATE_H
#define QWCOMBOBOXDELEGATE_H

#include    <QStyledItemDelegate>
#include    <QComboBox>

class QWComboBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

private:
    //选择列表
    QStringList m_ItemList;
    //是否可编辑
    bool m_isEdit;

public:
    QWComboBoxDelegate(QObject *parent=0);
    //初始化设置列表内容，是否可编辑
    void setItems(QStringList items, bool isEdit);
    //自定义代理组件必须继承以下4个函数
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
};

#endif // QWCOMBOBOXDELEGATE_H
