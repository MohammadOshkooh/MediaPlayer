#ifndef CHOOSETOPLAY_H
#define CHOOSETOPLAY_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QSlider>

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
    ~ChooseToPlay();

private slots:
    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionaAtFirst_triggered();

private:
    Ui::ChooseToPlay *ui;
};

#endif // CHOOSETOPLAY_H
