#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmovie.h>
#include <QString>
#include <QMessageBox>



#include "clientdlg.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void showClientDlg();
    void hideDlg();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QMovie* mygif;
};

#endif // MAINWINDOW_H
