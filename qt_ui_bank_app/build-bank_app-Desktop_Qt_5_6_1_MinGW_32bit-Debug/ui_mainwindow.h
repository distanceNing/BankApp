/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *view;
    QLabel *id;
    QLabel *passwd;
    QPushButton *ok;
    QPushButton *cancel;
    QLineEdit *user_id;
    QLineEdit *user_passwd;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(492, 400);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        view = new QLabel(centralWidget);
        view->setObjectName(QStringLiteral("view"));
        view->setGeometry(QRect(50, 20, 371, 111));
        id = new QLabel(centralWidget);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(90, 170, 51, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        id->setFont(font1);
        passwd = new QLabel(centralWidget);
        passwd->setObjectName(QStringLiteral("passwd"));
        passwd->setGeometry(QRect(90, 230, 51, 20));
        passwd->setFont(font1);
        ok = new QPushButton(centralWidget);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(110, 300, 75, 21));
        ok->setFont(font1);
        cancel = new QPushButton(centralWidget);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(290, 300, 75, 23));
        cancel->setFont(font1);
        user_id = new QLineEdit(centralWidget);
        user_id->setObjectName(QStringLiteral("user_id"));
        user_id->setGeometry(QRect(170, 170, 201, 31));
        user_passwd = new QLineEdit(centralWidget);
        user_passwd->setObjectName(QStringLiteral("user_passwd"));
        user_passwd->setGeometry(QRect(170, 220, 201, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 492, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(ok, cancel);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        view->setText(QString());
        id->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267\357\274\232", 0));
        passwd->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0));
        ok->setText(QApplication::translate("MainWindow", "\347\231\273\351\231\206", 0));
        cancel->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
