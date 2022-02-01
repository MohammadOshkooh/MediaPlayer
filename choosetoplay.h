#ifndef CHOOSETOPLAY_H
#define CHOOSETOPLAY_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QSlider>
#include <QLabel>
#include "playlistclass.h"
#include "setting.h"
#include"setsize.h"

namespace Ui {
class ChooseToPlay;
}

class ChooseToPlay : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseToPlay(QWidget *parent = nullptr, QMediaPlayer *qmp = nullptr);
    ChooseToPlay(QMediaPlayer *qmp);
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    Setting *setting ;
    QSlider *slider;
    QLabel *volume_label;
    SetSize *s;
    PlayListClass *playlistClass;
    void set_playlist(PlayListClass &playlist);
    void set_setting(Setting &setting);
    void playByGetFileName(QString fileName);
    void playNextVideoAtEndThisVideo();
    void setSize(int h, int w);
    QString fileNameBeingPlayed();
    ~ChooseToPlay();    

public slots:
    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionaAtFirst_triggered();

    void on_actionJump_back_triggered();

    void on_actionJump_forward_triggered();

    void on_actionmute_triggered();

    void on_actionvolume_increase_triggered();

    void on_actionvolume_dencrease_triggered();

    void on_actionopen_triggered();



private slots:
    void on_actionnext_video_triggered();

    void on_actionprevious_video_triggered();

    void on_actionBack_triggered();

    void on_actionclose_triggered();

    void on_actionmax_triggered();

    void on_actionmin_triggered();

    void on_actionFull_triggered();

    void on_actionRate0_25_triggered();

    void on_actionRate1_5_triggered();

    void on_actionRate0_75_triggered();

    void on_actionRate1_0_triggered();

    void on_actionRate2_triggered();

    void on_actionRate2_5_triggered();

    void on_actionRate0_5_triggered();

    void on_actionclick_for_resizing_triggered();

private:
    Ui::ChooseToPlay *ui;


};

#endif // CHOOSETOPLAY_H
