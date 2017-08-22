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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClientDlg
{
public:
    QPushButton *logout;

    void setupUi(QDialog *ClientDlg)
    {
        if (ClientDlg->objectName().isEmpty())
            ClientDlg->setObjectName(QStringLiteral("ClientDlg"));
        ClientDlg->resize(751, 426);
        logout = new QPushButton(ClientDlg);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(580, 390, 75, 23));

        retranslateUi(ClientDlg);

        QMetaObject::connectSlotsByName(ClientDlg);
    } // setupUi

    void retranslateUi(QDialog *ClientDlg)
    {
        ClientDlg->setWindowTitle(QApplication::translate("ClientDlg", "Dialog", 0));
        logout->setText(QApplication::translate("ClientDlg", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientDlg: public Ui_ClientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDLG_H
