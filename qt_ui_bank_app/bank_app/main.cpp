#include "mainwindow.h"
#include "clientdlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    ClientDlg w;
    w.show();

    return a.exec();
}
