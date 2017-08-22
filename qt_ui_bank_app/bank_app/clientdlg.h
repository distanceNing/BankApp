#ifndef CLIENTDLG_H
#define CLIENTDLG_H

#include <QDialog>

namespace Ui {
class ClientDlg;
}

class ClientDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDlg(QWidget *parent = 0);
    ~ClientDlg();

private:
    Ui::ClientDlg *ui;
};

#endif // CLIENTDLG_H
