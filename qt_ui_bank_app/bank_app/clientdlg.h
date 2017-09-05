#ifndef CLIENTDLG_H
#define CLIENTDLG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QMessageBox>

class QMovie;
namespace Ui {
class ClientDlg;
}

class ClientDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDlg(QWidget *parent = 0);
    ~ClientDlg();

private slots:
    void on_logout_clicked();

private:
    Ui::ClientDlg *ui;
    QMovie* mygif;
    QStandardItemModel *student_model;
};

#endif // CLIENTDLG_H
