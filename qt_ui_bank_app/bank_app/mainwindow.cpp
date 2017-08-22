#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mygif=new QMovie("mygif.gif");
    ui->view ->setMovie(mygif);
    mygif->start();
    connect(ui->ok, &QPushButton::clicked,
                this, &MainWindow::showClientDlg);


}

void MainWindow::showClientDlg()
{
    QString id,passwd;

    id=ui->user_id->text();
    passwd=ui->user_passwd->text();
    if(!id.compare("114001")&&!passwd.compare("123"))
    {
        ClientDlg *dialog = new ClientDlg(this);
        dialog->show();
        this->hide();
    }
    else
    {
        QMessageBox(QMessageBox::Information,"温馨提示","输入的账号密码不匹配！");
    }
}

MainWindow::~MainWindow()
{
    delete mygif;
    delete ui;
}
