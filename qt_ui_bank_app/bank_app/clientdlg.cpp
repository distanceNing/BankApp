#include "clientdlg.h"
#include "ui_clientdlg.h"

ClientDlg::ClientDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDlg)
{
    ui->setupUi(this);
}

ClientDlg::~ClientDlg()
{
    delete ui;
}
