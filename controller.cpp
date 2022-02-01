#include "controller.h"
#include "ui_controller.h"
#include<QBrush>
#include<QPixmap>
#include<iostream>
#include "choosetoplay.h"
#include "playlistclass.h"
#include "setting.h"

Controller::Controller(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller)
{
    ui->setupUi(this);

    // set background
    QPixmap bkgnd("./../images_file/main.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    player = new QMediaPlayer();

    chooseToPlay = new ChooseToPlay(player);
    playlist_class = new PlayListClass(player);
    setting = new Setting();

    chooseToPlay->setWindowFlag(Qt::FramelessWindowHint);
    playlist_class->setWindowFlag(Qt::FramelessWindowHint);
    setting->setWindowFlag(Qt::FramelessWindowHint);

}

Controller::~Controller()
{
    delete ui;
}

void Controller::on_pushButton_chooseToPlay_clicked()
{
    this->close();
    chooseToPlay->show();
}

void Controller::on_pushButton_setting_clicked()
{
    this->close();
    setting->show();

}

void Controller::on_pushButton_playlist_clicked()
{
    this->close();
    playlist_class->show();
    
}
