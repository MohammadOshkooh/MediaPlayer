#include "playlistclass.h"
#include "ui_playlist.h"
#include "choosetoplay.h"
#include <QStringListModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QDir>
#include<QMediaPlayer>
#include <fstream>

PlaylistClass::PlaylistClass(QMediaPlayer *qmp, QMediaPlaylist *qmpl) :
//    QWidget(parent),
    ui(new Ui::Playlist)
{
    ui->setupUi(this);

    player = qmp;
    playlist = qmpl;

    model = new QStandardItemModel();
    loadPlayList();

    ui->tableView->setModel(model);


  // ui->tableView->SelectRows;

    connect(ui->tableView,&QTableView::selectRow(1),player,&QMediaPlayer::play);

//    table = new QTableView();

//    table->setModel(model);



}

PlaylistClass::~PlaylistClass()
{
    delete ui;
}

//void PlaylistClass::setMediaPlayer(QMediaPlayer *qmp){
//    player = qmp;
//}

//void PlaylistClass::loadPlayList() {

//    playlist->load(QUrl::fromLocalFile("C:/Users/admin/Desktop/write/playlist.m3u"),"m3u");
//    //m_playlistModel->index(m_playlist->currentIndex(), 0)
    

//    model->setColumnCount(4);


//            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
//            model->setHeaderData(1,Qt::Horizontal,QObject::tr("Size(MB)"));
//            model->setHeaderData(2,Qt::Horizontal,QObject::tr("Time"));
//            model->setHeaderData(3,Qt::Horizontal,QObject::tr("Format "));
            
//            model->insertRow(0);
             
//            model->setData(model->index(0, 0),playlist->metaObject());


//}


void PlaylistClass::loadPlayList() {

    QString Filename = "C:/Users/admin/Desktop/write/a.txt";
    QFile MyFile(Filename);

    model->setColumnCount(4);

    if(MyFile.open(QIODevice::ReadWrite))
    {
        QTextStream input(&MyFile);
        while (!input.atEnd()) {
             QString line = input.readLine();

             QFile f(line);
             QFileInfo fileInfo(f.fileName());

             model->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
             model->setHeaderData(1,Qt::Horizontal,QObject::tr("Size(MB)"));
             model->setHeaderData(2,Qt::Horizontal,QObject::tr("Time"));
             model->setHeaderData(3,Qt::Horizontal,QObject::tr("Format "));

             model->insertRow(0);
             model->setData(model->index(0, 0), fileInfo.fileName());
             model->setData(model->index(0, 1), f.size()/(1024*1024.0));
             model->setData(model->index(0, 2), player->duration());
             model->setData(model->index(0, 3), fileInfo.completeSuffix());

        }
    }

    MyFile.close();
}

void PlaylistClass::addToPlaylist(QString filename){

        QString Filename = "C:/Users/admin/Desktop/write/a.txt";
        QFile MyFile(Filename);

        if(MyFile.open(QIODevice::Append)){

        QTextStream write(&MyFile);
        write <<filename;
        write <<"\n";
        MyFile.flush();
        MyFile.close();
    }

}


