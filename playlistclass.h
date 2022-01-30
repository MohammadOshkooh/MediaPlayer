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
    void remove_file();
    void addToPlaylist(QString fileName);
    void tableDoubleClicked();
    bool fileIsExist(QString fileName);
    ~PlayListClass();

private slots:
    void on_actionadd_triggered();

    void on_actionremove_to_playlist_triggered();

private:
    Ui::PlayListClass *ui;
};

#endif // PLAYLISTCLASS_H
