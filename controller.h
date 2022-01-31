#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include "choosetoplay.h"
#include "playlistclass.h"
#include "setting.h"

namespace Ui {
class Controller;
}

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller(QMainWindow *parent = nullptr);
    ChooseToPlay *chooseToPlay;
    Setting *setting;
    PlayListClass *playlist_class;

    QMediaPlayer *player;

    ~Controller();

private slots:
    void on_pushButton_chooseToPlay_clicked();

    void on_pushButton_setting_clicked();

    void on_pushButton_playlist_clicked();

private:
    Ui::Controller *ui;
};

#endif // CONTROLLER_H
