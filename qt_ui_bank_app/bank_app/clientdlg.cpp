#include "clientdlg.h"
#include "ui_clientdlg.h"
#include "mainwindow.h"
#include "pageoperate.h"

ClientDlg::ClientDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDlg)
{
    ui->setupUi(this);


    ui->client->tr("Client");
    ui->account->tr("Account");
    ui->tabWidget->addTab(new PageOperate(), tr("General"));
    ui->tabWidget->addTab(new  MainWindow(), tr("Permissions"));
    ui->tabWidget->addTab(new  MainWindow(), tr("Applications"));

    mygif=new QMovie(":/images/images/main.gif");
    ui->label ->setMovie(mygif);
    mygif->start();

}

ClientDlg::~ClientDlg()
{
    delete mygif;
    delete ui;
}

void ClientDlg::on_logout_clicked()
{
    QMessageBox msgBox(QMessageBox::Information,"温馨提示","您确认退出吗？");
    QPushButton *acceptButton = msgBox.addButton( "确定",QMessageBox::AcceptRole);
    msgBox.addButton("取消",QMessageBox::RejectRole);
    msgBox.setBaseSize(100,100);
    msgBox.exec();
    if (msgBox.clickedButton() == acceptButton)
    {
       //this->hide();

       this->reject();
    }

}
