#include "choosetoplay.h"
#include "ui_choosetoplay.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <iostream>
#include <QMediaPlaylist>
#include "playlistclass.h"
#include "controller.h"
#include<QMessageBox>
#include<setsize.h>

using namespace std;

ChooseToPlay::ChooseToPlay(QMediaPlayer *qmp) :
      //  QMainWindow(parent),
        ui(new Ui::ChooseToPlay) {
    ui->setupUi(this);

    player = qmp;
    videoWidget = new QVideoWidget(this);

    playlistClass = new PlayListClass(player);
    setting = new Setting;

    player->setVideoOutput(videoWidget);
    this->setCentralWidget(videoWidget);


    //  create slider
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    ui->toolBar->addWidget(slider);

    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);

    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);


// پس از اتمام پخش یک فایل، در صورت وجود فایل بعدی، آن فایل پخش شود
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);


//  show volum
    QLabel *l = new QLabel;
    l->setText("  volume:");
    ui->toolBar->addWidget(l);

    volume_label = new QLabel;
    QString volume = QString::number(player->volume());
    volume_label->setText(volume);
    ui->toolBar->addWidget(volume_label);


//  read init volume in file
    player->setVolume(setting->read("volume"));

    videoWidget->show();

    player->play();
}

ChooseToPlay::~ChooseToPlay() {
    delete ui;
}

void ChooseToPlay::on_actionPlay_triggered() {

    player->play();
}

void ChooseToPlay::on_actionPause_triggered() {
    player->pause();
}

void ChooseToPlay::on_actionaAtFirst_triggered() {
    player->setPosition(0);
}

void ChooseToPlay::on_actionJump_back_triggered() {
    int pos = player->position();
    player->setPosition(pos - setting->read("jumpTime") * 1000);
}

void ChooseToPlay::on_actionJump_forward_triggered() {
    int pos = player->position();
    player->setPosition(pos + setting->read("jumpTime") * 1000);
}

void ChooseToPlay::on_actionmute_triggered() {
    player->setVolume(0);
    volume_label->setText("0");
}

void ChooseToPlay::on_actionvolume_increase_triggered() {
    int volum = player->volume();
    player->setVolume(volum + 10);
    volume_label->setText(QString::number(player->volume()));

}

void ChooseToPlay::on_actionvolume_dencrease_triggered() {

    int volum = player->volume();
    player->setVolume(volum - 10);
    volume_label->setText(QString::number(player->volume()));

}

void ChooseToPlay::on_actionopen_triggered() {
    player->stop();
    QString fileName = QFileDialog::getOpenFileName
            (this, "", "", "video or music(*.mp4 , *.wmv , *.mkv , *.AVI , *.mp3)");

// an example in doc..
//    QString fileName = QFileDialog::getOpenFileName
//            (this,"Select one or more files to open", "/home", "Images (*.png *.xpm *.jpg)");


    player->setMedia(QUrl::fromLocalFile(fileName));
    player->setVideoOutput(videoWidget);
    this->setCentralWidget(videoWidget);

    playlistClass->addToPlaylist(fileName, 1);

    on_actionPlay_triggered();
}

void ChooseToPlay::playByGetFileName(QString fileName) {
    player->setMedia(QUrl::fromLocalFile(fileName));
    on_actionPlay_triggered();
}


void ChooseToPlay::on_actionnext_video_triggered() {

    QString fileName = player->currentMedia().canonicalUrl().toString();
    fileName.remove(0, 8); // for example : "file:///C:/Users/admin/Videos/s.mp4" => "C:/Users/admin/Videos/s.mp4"

    QString newFileName = playlistClass->nextVideo(fileName);

    player->setMedia(QUrl::fromLocalFile(newFileName));
    player->play();
}

void ChooseToPlay::on_actionprevious_video_triggered() {
    QString newFileName = playlistClass->previousVideo(fileNameBeingPlayed());

    player->setMedia(QUrl::fromLocalFile(newFileName));
    player->play();
}


void ChooseToPlay::playNextVideoAtEndThisVideo() {
    if (player->position() == player->duration() && player->duration() != 0)
        on_actionnext_video_triggered();
}

QString ChooseToPlay::fileNameBeingPlayed() {
    QString fileName = player->currentMedia().canonicalUrl().toString();
    fileName.remove(0, 8); // for example : "file:///C:/Users/admin/Videos/s.mp4"
    return fileName;
}

void ChooseToPlay::on_actionBack_triggered() {
    player->stop();
    this->close();
    Controller *c = new Controller();
    c->setWindowFlag(Qt::FramelessWindowHint);
    c->show();
}

void ChooseToPlay::on_actionclose_triggered() {
    player->stop();
    this->close();
}

void ChooseToPlay::on_actionmax_triggered() {
    this->showMaximized();
}

void ChooseToPlay::on_actionmin_triggered() {
    //this->setWindowState(Qt::WindowMinimized);
    this->showMinimized();
}

void ChooseToPlay::on_actionFull_triggered() {
    this->setWindowState(Qt::WindowFullScreen);

}

void ChooseToPlay::on_actionRate0_25_triggered() {
    player->setPlaybackRate(0.25);
}

void ChooseToPlay::on_actionRate1_5_triggered() {
    player->setPlaybackRate(1.5);
}

void ChooseToPlay::on_actionRate0_75_triggered() {
    player->setPlaybackRate(0.75);
}

void ChooseToPlay::on_actionRate1_0_triggered() {
    player->setPlaybackRate(1.0);
}

void ChooseToPlay::on_actionRate2_triggered() {
    player->setPlaybackRate(2);
}

void ChooseToPlay::on_actionRate2_5_triggered() {
    player->setPlaybackRate(2.5);
}

void ChooseToPlay::on_actionRate0_5_triggered() {
    player->setPlaybackRate(0.5);


}

void ChooseToPlay::on_actionclick_for_resizing_triggered() {

//    s = new SetSize;
//    s->show();
}

void ChooseToPlay::setSize(int h, int w) {

//    this->resize(w,h);
//    this->show();
}
