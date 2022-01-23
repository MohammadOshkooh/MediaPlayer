#include "choosetoplay.h"
#include "ui_choosetoplay.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>

ChooseToPlay::ChooseToPlay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseToPlay)
{
    ui->setupUi(this);

    // open a file
    QString Filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.mp4, *.wmv)");

    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    player->setMedia(QUrl::fromLocalFile(Filename));
    player->setVideoOutput(videoWidget);
    this->setCentralWidget(videoWidget);


    // create a slider
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);

//    slider->setSi

    ui->toolBar->addWidget(slider);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);

    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);



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
