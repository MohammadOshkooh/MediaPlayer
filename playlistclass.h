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
    PlayListClass(int n);
    bool removeMode=false;

    QTableWidget *table;
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QStandardItemModel * model;

    void updatePlayListView();
    void showPlaylist();
    void remove_file(QString fileName);
    void removeClickedMethod();
    void addToPlaylist(QString fileName);
    void tableDoubleClicked();
    void clearPlaylist();

    QString nextVideo(QString fileName);
    QString previousVideo(QString fileName);
    QString getFileNameNumberI(int i);

    bool fileIsExist(QString fileName);

    int getLineCount();
    int getNumberFile(QString fileName);

    ~PlayListClass();

private slots:
    void on_actionadd_triggered();

    void on_actionremove_to_playlist_triggered();

    void on_actionBack_triggered();

private:
    Ui::PlayListClass *ui;
};

#endif // PLAYLISTCLASS_H
