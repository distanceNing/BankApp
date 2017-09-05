#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mygif=new QMovie(":/images/images/mygif.gif");
    ui->view ->setMovie(mygif);
    mygif->start();
    connect(ui->ok, &QPushButton::clicked,
                this, &MainWindow::showClientDlg);
    connect(ui->cancel, &QPushButton::clicked,
                this, &MainWindow::hideDlg);

}

void MainWindow::showClientDlg()
{
    QString id,passwd;
    id=ui->user_id->text();
    passwd=ui->user_passwd->text();
    if(id==""||passwd=="")
    {
        QMessageBox msgBox(QMessageBox::Information,"温馨提示","请输入账号和密码！");
        msgBox.addButton(tr("确认"), QMessageBox::AcceptRole);
        msgBox.exec();
        return ;
    }
    if(!id.compare("114001")&&!passwd.compare("123"))
    {
        ClientDlg *dialog = new ClientDlg(this);
        dialog->show();
        this->hide();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Information,"温馨提示","输入的账号密码不匹配！");
        msgBox.addButton(tr("确认"), QMessageBox::AcceptRole);
        msgBox.exec();
    }
}

void MainWindow::hideDlg()
{
    QMessageBox msgBox(QMessageBox::Information,"温馨提示","您确认退出吗？");
    QPushButton *acceptButton = msgBox.addButton(tr("确认"), QMessageBox::AcceptRole);
    msgBox.addButton(QMessageBox::Cancel);
    msgBox.exec();
    if (msgBox.clickedButton() == acceptButton)
    {
       this->hide();
    }

}
MainWindow::~MainWindow()
{
    delete mygif;
    delete ui;
}


