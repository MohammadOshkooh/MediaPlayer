#ifndef CHOOSETOPLAY_H
#define CHOOSETOPLAY_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QSlider>
#include <QLabel>
#include <QMediaPlaylist>

namespace Ui {
class ChooseToPlay;
}

class ChooseToPlay : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseToPlay(QWidget *parent = nullptr);
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QSlider *slider;
    QLabel *volume_label;
    QMediaPlaylist *playlist;
    ~ChooseToPlay();

private slots:
    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionaAtFirst_triggered();

    void on_actionJump_back_triggered();

    void on_actionJump_forward_triggered();

    void on_actionmute_triggered();

    void on_actionvolume_increase_triggered();

    void on_actionvolume_dencrease_triggered();

    void on_actionopen_triggered();

private:
    Ui::ChooseToPlay *ui;
};

#endif // CHOOSETOPLAY_H
