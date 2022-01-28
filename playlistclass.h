#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QTableView>

namespace Ui {
class Playlist;
}

class PlaylistClass : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistClass(QMediaPlayer *qmp = nullptr, QMediaPlaylist *qmpl = nullptr);
    QMediaPlaylist *playlist;
    QMediaPlayer *player;

    QStandardItemModel * model;
    QTableView *table;  
    void loadPlayList();
    void addToPlaylist(QString fileName);
    void setMediaPlayer(QMediaPlayer *qmp);
    ~PlaylistClass();

private:
    Ui::Playlist *ui;
};

#endif // PLAYLIST_H
