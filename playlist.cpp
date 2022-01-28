#include "playlist.h"
#include "ui_playlist.h"
#include "choosetoplay.h"
#include <QStringListModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QDir>
#include<QMediaPlayer>


Playlist::Playlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Playlist)
{
    ui->setupUi(this);
    model = new QStandardItemModel();
//    loadPlayList();

//    ui->tableView->setModel(model);

    table = new QTableView();

    table->setModel(model);

}

Playlist::~Playlist()
{
    delete ui;
}


void Playlist::loadPlayList(QMediaPlayer &player) {

    QString Filename = "C:/Users/admin/Desktop/write/a.txt";
    QFile MyFile(Filename);

    model->setColumnCount(4);

    if(MyFile.open(QFile::ReadOnly | QFile::Text))
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
             model->setData(model->index(0, 2), player.duration());
             model->setData(model->index(0, 3), fileInfo.completeSuffix());

        }
    }

    MyFile.close();
}

