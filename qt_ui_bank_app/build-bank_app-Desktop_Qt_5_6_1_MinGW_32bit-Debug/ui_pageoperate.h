/********************************************************************************
** Form generated from reading UI file 'pageoperate.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEOPERATE_H
#define UI_PAGEOPERATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_PageOperate
{
public:
    QTableView *tableView;

    void setupUi(QDialog *PageOperate)
    {
        if (PageOperate->objectName().isEmpty())
            PageOperate->setObjectName(QStringLiteral("PageOperate"));
        PageOperate->resize(790, 343);
        PageOperate->setMinimumSize(QSize(790, 343));
        PageOperate->setMaximumSize(QSize(790, 343));
        tableView = new QTableView(PageOperate);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 41, 761, 211));

        retranslateUi(PageOperate);

        QMetaObject::connectSlotsByName(PageOperate);
    } // setupUi

    void retranslateUi(QDialog *PageOperate)
    {
        PageOperate->setWindowTitle(QApplication::translate("PageOperate", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PageOperate: public Ui_PageOperate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEOPERATE_H
