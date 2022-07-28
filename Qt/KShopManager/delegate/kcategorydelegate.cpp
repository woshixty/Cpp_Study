#include "kcategorydelegate.h"

KCategoryDelegate::KCategoryDelegate(QObject *parent)
    : QItemDelegate{parent}
{

}

QWidget *KCategoryDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    int m_category_id = index.data().toInt();
    qDebug() << "m_category_id" << m_category_id;
    QLineEdit *editor = new QLineEdit(parent);
    editor->setReadOnly(true);
    // 设置值
    QString str;
    switch (m_category_id)
    {
    case 1:
        str = "电脑办公";
    case 2:
        str = "手机";
    case 3:
        str = "食物";
    case 4:
        str = "服饰";
    default :
        str = "其他";
    }
    editor->setText(str);
    return editor;
}

void KCategoryDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int m_category_id = index.data().toInt();
    qDebug() << "m_category_id" << m_category_id;
    // 强制类型转换
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    // 设置值
    QString str;
    switch (m_category_id)
    {
    case 1:
        str = "电脑办公";
    case 2:
        str = "手机";
    case 3:
        str = "食物";
    case 4:
        str = "服饰";
    default :
        str = "其他";
    }

    lineEdit->setText(str);
}

void KCategoryDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    Q_UNUSED(editor);
    Q_UNUSED(model);
    Q_UNUSED(index);
}

void KCategoryDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // 设置组件大小
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
