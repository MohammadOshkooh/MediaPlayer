#include "controller.h"
#include "ui_controller.h"
#include<QBrush>
#include<QPixmap>
#include<iostream>
#include "choosetoplay.h"
#include "playlistclass.h"
#include "setting.h"

Controller::Controller(QWidget *parent) :
    QWidget(parent),
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
    playlist = new QMediaPlaylist();

    chooseToPlay = new ChooseToPlay(this,player,playlist);
    playlist_class = new PlayListClass(player, playlist);
    setting = new Setting();


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
