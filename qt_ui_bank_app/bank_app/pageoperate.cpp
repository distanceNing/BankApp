#include "pageoperate.h"
#include "ui_pageoperate.h"

PageOperate::PageOperate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PageOperate)
{
    ui->setupUi(this);
    itemModel_ = new QStandardItemModel();
    itemModel_->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Name")));
    itemModel_->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("NO")));
    itemModel_->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Sex")));
    itemModel_->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Age")));
    itemModel_->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("College")));
     //利用setModel()方法将数据模型与QTableView绑定
    ui->tableView->setModel(itemModel_);
}

PageOperate::~PageOperate()
{
    delete ui;
}
