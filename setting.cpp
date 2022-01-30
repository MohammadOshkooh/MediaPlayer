#include "setting.h"
#include "ui_setting.h"
#include <iostream>
#include<QBoxLayout>
#include<QPushButton>

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{

    ui->setupUi(this);
    QBoxLayout *h = new QVBoxLayout;
    QPushButton *g = new QPushButton(tr("bgg"));
    h->addWidget(g);
    setLayout(h);
}

Setting::~Setting()
{
    delete ui;
}
