#ifndef PLAYLISTCLASS_H
#define PLAYLISTCLASS_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QTableView>
#include <QWidget>
#include <QTableWidget>

namespace Ui {
class PlayListClass;
}

class PlayListClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayListClass(QMediaPlayer *qmp = nullptr, QMediaPlaylist *qmpl = nullptr);

    QTableWidget *table;
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QStandardItemModel * model;
    void showPlaylist();
    void addToPlaylist(QString fileName);
    void tableDoubleClicked();

    ~PlayListClass();

private:
    Ui::PlayListClass *ui;
};

#endif // PLAYLISTCLASS_H
