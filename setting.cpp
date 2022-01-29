#include "setting.h"
#include "ui_setting.h"
#include <iostream>

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    std::cout<<"run setting\n";
    ui->setupUi(this);
}

Setting::~Setting()
{
    delete ui;
}
