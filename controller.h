#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include "choosetoplay.h"
#include "playlistclass.h"
#include "setting.h"

namespace Ui {
class Controller;
}

class Controller : public QWidget
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = nullptr);
    ChooseToPlay *chooseToPlay;
    Setting *setting;
    PlaylistClass *plClass;

    QMediaPlayer *player;
    QMediaPlaylist *playlist;

    ~Controller();

private slots:
    void on_pushButton_chooseToPlay_clicked();

    void on_pushButton_setting_clicked();

    void on_pushButton_playlist_clicked();

private:
    Ui::Controller *ui;
};

#endif // CONTROLLER_H
