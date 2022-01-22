#include "choosetoplay.h"
#include "ui_choosetoplay.h"

ChooseToPlay::ChooseToPlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseToPlay)
{
    ui->setupUi(this);
}

ChooseToPlay::~ChooseToPlay()
{
    delete ui;
}
