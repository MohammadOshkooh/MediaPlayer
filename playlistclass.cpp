#include "playlistclass.h"
#include "ui_playlistclass.h"

#include "choosetoplay.h"
#include <QStringListModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QDir>
#include <QMediaPlayer>
#include <iostream>
#include<QHBoxLayout>
#include <QLabel>
#include<QMessageBox>
#include<QPushButton>

using namespace std;

PlayListClass::PlayListClass(QMediaPlayer *qmp , QMediaPlaylist *qmpl ) :
 //   QMainWindow(parent),
    ui(new Ui::PlayListClass)
{
    ui->setupUi(this);

    player = qmp;
    playlist = qmpl;
    table = new QTableWidget();
    model = new QStandardItemModel();

    table->setColumnCount(5);
    table->setColumnWidth(0,180);
    table->setColumnWidth(1,60);
    table->setColumnWidth(2,60);
    table->setColumnWidth(3,60);
    table->setColumnWidth(4,260);

    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Size(MB)"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Time"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Format"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Address"));
//    ChooseToPlay *s = new ChooseToPlay(this,player,playlist);
    QLabel *label = new QLabel();
    label->setText("label");

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // connect for play a file to playlist
    connect(table,&QTableWidget::cellDoubleClicked,table,&QTableWidget::selectRow);
    connect(table,&QTableWidget::cellDoubleClicked,this,&PlayListClass::tableDoubleClicked);


   // connect(muteButton, &QAbstractButton::clicked, this, &MainWindow::muteClicked);


    showPlaylist();
    ui->verticalLayout->addWidget(table);

}

PlayListClass::~PlayListClass()
{
    std::cout<<"delete\n";
    delete ui;
}


void PlayListClass::tableDoubleClicked(){
    for(int i=0; i<table->rowCount(); i++){
        if(table->item(i,0)->isSelected()){
            QString fileName = table->item(i,4)->data(0).toString();

            QFile f(fileName);

            if (f.exists()){
                ChooseToPlay *c = new ChooseToPlay(player,playlist);
                c->playByGetFileName(fileName);
                c->show();
            }

            else {
                QMessageBox msg;
                msg.setText("not found this media\nDo you want to remove it from the playlist? ");
                QPushButton button;
                msg.setWindowTitle("error");

                msg.addButton(QMessageBox::Yes);
                msg.addButton(QMessageBox::No);

                int result = msg.exec();

                if(result == QMessageBox::Yes){
                    table->removeRow(i);
                }

            }
        }
    }
}


void PlayListClass::remove_file(){

}

void PlayListClass::showPlaylist() {
    QString fileAddress = "C:/Users/admin/Desktop/write/a.txt";
    QFile MyFile(fileAddress);


    if(MyFile.open(QIODevice::ReadWrite))
    {
        QTextStream input(&MyFile);
        while (!input.atEnd()) {
             QString line = input.readLine();

             QFile f(line);
             QFileInfo fileInfo(f.fileName());

             table->insertRow ( table->rowCount());

             QTableWidgetItem* tableItem0 = new QTableWidgetItem();
             QTableWidgetItem* tableItem1 = new QTableWidgetItem();
             QTableWidgetItem* tableItem2 = new QTableWidgetItem();
             QTableWidgetItem* tableItem3 = new QTableWidgetItem();
             QTableWidgetItem* tableItem4 = new QTableWidgetItem();

             tableItem0->setData(0,fileInfo.fileName());
             table->setItem   ( table->rowCount() -1,0,tableItem0);

             tableItem1->setData(0,f.size()/(1024*1024.0));
             table->setItem   ( table->rowCount() -1,1,tableItem1);

             tableItem2->setData(0,player->duration());
             table->setItem   ( table->rowCount() -1,2,tableItem2);

             tableItem3->setData(0,fileInfo.completeSuffix());
             table->setItem   ( table->rowCount() -1,3,tableItem3);

             tableItem4->setData(0,line);
             table->setItem   ( table->rowCount() -1,4,tableItem4);

             if(f.exists() == 0){
                table->item(table->rowCount()-1, 0)->setBackground(Qt::red);
                table->item(table->rowCount()-1, 1)->setBackground(Qt::red);
                table->item(table->rowCount()-1, 2)->setBackground(Qt::red);
                table->item(table->rowCount()-1, 3)->setBackground(Qt::red);
                table->item(table->rowCount()-1, 4)->setBackground(Qt::red);
              //  table->item(table->rowCount()-1, 4)->setTextColor(Qt::red);
             }

        }
    }

    MyFile.close();
}


bool PlayListClass::fileIsExist(QString fileName){
    QString fileAddress = "C:/Users/admin/Desktop/write/a.txt";
    QFile MyFile(fileAddress);

    if(MyFile.open(QIODevice::ReadWrite)){
        QTextStream input(&MyFile);
        while (!input.atEnd()) {
            QString line = input.readLine();
            if(line == fileName)
                return 1;
        }
    }
    return 0;
}

void PlayListClass::addToPlaylist(QString filename){

    if(!fileIsExist(filename)){
        QString fileAddress = "C:/Users/admin/Desktop/write/a.txt";
        QFile MyFile(fileAddress);

        if(MyFile.open(QIODevice::Append)){

        QTextStream write(&MyFile);
        write <<filename;
        write <<"\n";
        MyFile.flush();
        MyFile.close();
        }
    }
    else{
        QMessageBox msg;
        msg.setText("The file already exists in the list ");
        msg.exec();
    }
}

void PlayListClass::on_actionadd_triggered()
{
    QString Filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.mp4 , *.wmv)");

    addToPlaylist(Filename);

    showPlaylist();
}



void PlayListClass::on_actionremove_to_playlist_triggered()
{

    ui->statusBar->showMessage("Please select a file to remove from the playlist");

    connect(table,&QTableWidget::cellClicked,table,&QTableWidget::selectRow);
    connect(table,&QTableWidget::cellClicked,this,&PlayListClass::tableDoubleClicked);

}

//             model->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
//             model->setHeaderData(1,Qt::Horizontal,QObject::tr("Size(MB)"));
//             model->setHeaderData(2,Qt::Horizontal,QObject::tr("Time"));
//             model->setHeaderData(3,Qt::Horizontal,QObject::tr("Format "));

//             model->insertRow(0);
//             model->setData(model->index(0, 0), fileInfo.fileName());
//             model->setData(model->index(0, 1), f.size()/(1024*1024.0));
//             model->setData(model->index(0, 2), player->duration());
//             model->setData(model->index(0, 3), fileInfo.completeSuffix());




//    ui->toolBar->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
