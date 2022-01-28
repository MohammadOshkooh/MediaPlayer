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

class Playlist : public QWidget
{
    Q_OBJECT

public:
    explicit Playlist(QWidget *parent = nullptr);
    QMediaPlaylist *playlist;
    QStandardItemModel * model;
    QTableView *table;
    void loadPlayList(QMediaPlayer &player);
    ~Playlist();

private:
    Ui::Playlist *ui;
};

#endif // PLAYLIST_H
