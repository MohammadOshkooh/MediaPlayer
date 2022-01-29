#include "choosetoplay.h"
#include "ui_choosetoplay.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <iostream>
#include <QMediaPlaylist>
#include "playlistclass.h"

using namespace std;


ChooseToPlay::ChooseToPlay(QMediaPlayer *qmp, QMediaPlaylist *qmpl) :
   // QMainWindow(parent),
    ui(new Ui::ChooseToPlay)
{
    ui->setupUi(this);

    player = qmp;
    videoWidget = new QVideoWidget(this);
    playlist = qmpl;
    player->setPlaylist(playlist);

    player->setVideoOutput(videoWidget);
    this->setCentralWidget(videoWidget);


    //  create a slider
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    ui->toolBar->addWidget(slider);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);

    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

//  show volum
    QLabel *l = new QLabel;
    l->setText("  volume:");
    ui->toolBar->addWidget(l);

    volume_label = new QLabel;
    QString volume = QString::number( player->volume());
    volume_label->setText(volume);
    ui->toolBar->addWidget(volume_label);

    videoWidget->show();

    player->play();
}



ChooseToPlay::ChooseToPlay(QWidget *parent, QMediaPlayer *qmp, QMediaPlaylist *qmpl) :
    QMainWindow(parent),
    ui(new Ui::ChooseToPlay)
{
    ui->setupUi(this);

    player = qmp;
    videoWidget = new QVideoWidget(this);
    playlist = qmpl;
    playlistClass = new PlayListClass(player, playlist);

    player->setPlaylist(playlist);

    player->setVideoOutput(videoWidget);
    this->setCentralWidget(videoWidget);


    //  create a slider
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    ui->toolBar->addWidget(slider);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);

    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

///////////////////////////////////////////////////////////////////////////////////////////////////////
  //  connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &Player::playlistPositionChanged);

//  show volum
    QLabel *l = new QLabel;
    l->setText("  volume:");
    ui->toolBar->addWidget(l);

    volume_label = new QLabel;
    QString volume = QString::number( player->volume());
    volume_label->setText(volume);
    ui->toolBar->addWidget(volume_label);

    videoWidget->show();

    player->play();
}

ChooseToPlay::~ChooseToPlay()
{
    delete ui;
}

void ChooseToPlay::on_actionPlay_triggered()
{
    player->play();
}

void ChooseToPlay::on_actionPause_triggered()
{
    player->pause();
}

void ChooseToPlay::on_actionaAtFirst_triggered()
{
    player->setPosition(0);
}

void ChooseToPlay::on_actionJump_back_triggered()
{
    int pos = player->position();
    player->setPosition(pos-2000);
}

void ChooseToPlay::on_actionJump_forward_triggered()
{
    int pos = player->position();
    player->setPosition(pos+2000);
}

void ChooseToPlay::on_actionmute_triggered()
{
    player->setVolume(0);
    volume_label->setText("0");
}

void ChooseToPlay::on_actionvolume_increase_triggered()
{
    int volum = player->volume();
    player->setVolume(volum+10);
    volume_label->setText(QString::number( player->volume()));

}

void ChooseToPlay::on_actionvolume_dencrease_triggered()
{
    int volum = player->volume();
    player->setVolume(volum-10);
    volume_label->setText(QString::number( player->volume()));

}

void ChooseToPlay::on_actionopen_triggered()
{
    player->stop();
    QString Filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.mp4 , *.wmv)");
    playlist->addMedia(QMediaContent(QUrl::fromLocalFile(Filename)));
    player->setMedia(QUrl::fromLocalFile(Filename));
    player->setVideoOutput(videoWidget);
    this->setCentralWidget(videoWidget);


    playlist->save(QUrl::fromLocalFile("C:/Users/admin/Desktop/write/playlist.m3u"),"m3u");

    playlistClass->addToPlaylist(Filename);

    on_actionPlay_triggered();
}

void ChooseToPlay::playByGetFileName(QString fileName){
    player->setMedia(QUrl::fromLocalFile(fileName));
    on_actionPlay_triggered();
}

