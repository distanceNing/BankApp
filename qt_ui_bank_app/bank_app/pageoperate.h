#ifndef PAGEOPERATE_H
#define PAGEOPERATE_H

#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class PageOperate;
}

class PageOperate : public QDialog
{
    Q_OBJECT

public:
    explicit PageOperate(QWidget *parent = 0);
    ~PageOperate();

private:
    Ui::PageOperate *ui;
    QStandardItemModel* itemModel_;
};

#endif // PAGEOPERATE_H
