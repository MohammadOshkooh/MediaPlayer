#include "setsize.h"
#include "ui_setsize.h"
#include"choosetoplay.h"
#include<QMediaPlayer>

SetSize::SetSize(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetSize)
{
    ui->setupUi(this);
}

SetSize::~SetSize()
{
    delete ui;
}

void SetSize::on_pushButton_clicked()
{
    int h = ui->h->text().toInt();
    int w = ui->w->text().toInt();
    QMediaPlayer *p = new QMediaPlayer;
    ChooseToPlay *c = new ChooseToPlay(p);
    c->setSize(h,w);
    this->close();
}
