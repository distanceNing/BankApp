/********************************************************************************
** Form generated from reading UI file 'clientdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDLG_H
#define UI_CLIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientDlg
{
public:
    QTabWidget *tabWidget;
    QWidget *account;
    QWidget *client;
    QPushButton *logout;
    QLabel *label;

    void setupUi(QDialog *ClientDlg)
    {
        if (ClientDlg->objectName().isEmpty())
            ClientDlg->setObjectName(QStringLiteral("ClientDlg"));
        ClientDlg->resize(751, 524);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        ClientDlg->setFont(font);
        ClientDlg->setContextMenuPolicy(Qt::CustomContextMenu);
        ClientDlg->setAutoFillBackground(false);
        tabWidget = new QTabWidget(ClientDlg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 160, 741, 271));
        tabWidget->setMouseTracking(false);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        account = new QWidget();
        account->setObjectName(QStringLiteral("account"));
        tabWidget->addTab(account, QString());
        client = new QWidget();
        client->setObjectName(QStringLiteral("client"));
        client->setEnabled(true);
        client->setAutoFillBackground(true);
        tabWidget->addTab(client, QString());
        logout = new QPushButton(ClientDlg);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(514, 480, 121, 23));
        label = new QLabel(ClientDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 681, 121));

        retranslateUi(ClientDlg);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientDlg);
    } // setupUi

    void retranslateUi(QDialog *ClientDlg)
    {
        ClientDlg->setWindowTitle(QApplication::translate("ClientDlg", "Client", 0));
        tabWidget->setTabText(tabWidget->indexOf(account), QApplication::translate("ClientDlg", "Account", 0));
        tabWidget->setTabText(tabWidget->indexOf(client), QApplication::translate("ClientDlg", "Client", 0));
        logout->setText(QApplication::translate("ClientDlg", "\351\200\200\345\207\272", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClientDlg: public Ui_ClientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDLG_H
