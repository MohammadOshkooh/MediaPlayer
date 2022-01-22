#include "controller.h"
#include "ui_controller.h"
#include<QBrush>
#include<QPixmap>

#include "choosetoplay.h"
#include "playlist.h"
#include "setting.h"

Controller::Controller(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controller)
{
    ui->setupUi(this);

    // set background
    QPixmap bkgnd("C:/Users/admin/Desktop/my_project/images_file/main.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Controller::~Controller()
{
    delete ui;
}

void Controller::on_pushButton_chooseToPlay_clicked()
{
    player = new ChooseToPlay;
    player->show();
}

void Controller::on_pushButton_setting_clicked()
{
    setting = new Setting;
    setting->show();
}

void Controller::on_pushButton_playlist_clicked()
{
    playlist = new Playlist;
    playlist->show();
}
