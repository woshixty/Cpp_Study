#ifndef KROOMSEARCH_H
#define KROOMSEARCH_H

#include <QWidget>

namespace Ui {
class KRoomSearch;
}

class KRoomSearch : public QWidget
{
    Q_OBJECT

public:
    explicit KRoomSearch(QWidget *parent = nullptr);
    ~KRoomSearch();

private:
    Ui::KRoomSearch *ui;
};

#endif // KROOMSEARCH_H
