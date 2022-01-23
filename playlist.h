#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QMainWindow>

namespace Ui {
class Playlist;
}

class Playlist : public QWidget
{
    Q_OBJECT

public:
    explicit Playlist(QWidget *parent = nullptr);
    Playlist *playlist;
    ~Playlist();

private:
    Ui::Playlist *ui;
};

#endif // PLAYLIST_H
