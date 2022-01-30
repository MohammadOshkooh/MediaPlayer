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

    QLabel *label = new QLabel();
    label->setText("label");

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // connect for play a file to playlist
    connect(table,&QTableWidget::cellDoubleClicked,table,&QTableWidget::selectRow);
    connect(table,&QTableWidget::cellDoubleClicked,this,&PlayListClass::tableDoubleClicked);


    showPlaylist();
    ui->verticalLayout->addWidget(table);

}

PlayListClass::~PlayListClass()
{
    std::cout<<"delete\n";
    delete ui;
}


void PlayListClass::tableDoubleClicked(){
    qDebug()<<"tableDoubleClicked";
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
                remove_file(table->item(i,4)->data(0).toString());
            }
        }
    }
}


void PlayListClass::remove_file(QString fileName){
     qDebug()<<"remove_file";

    QMessageBox msg;
    msg.setText("Do you want to remove it from the playlist? ");
    QPushButton button;
    msg.setWindowTitle("error");

    msg.addButton(QMessageBox::Yes);
    msg.addButton(QMessageBox::No);

    int result = msg.exec();

    if(result == QMessageBox::Yes){

        QString fileAddress = "C:/Users/admin/Desktop/write/a.txt";
        QString fileAddress2 = "C:/Users/admin/Desktop/write/a2.txt";
        QFile MyFile(fileAddress);
        QFile replaceFile(fileAddress2);

        if(MyFile.open(QIODevice::ReadWrite) && replaceFile.open(QIODevice::ReadWrite)){
            QTextStream input(&MyFile);
            QTextStream write(&replaceFile);
            while (!input.atEnd()) {
                QString line = input.readLine();
                if(line != fileName){
                    write <<line;
                    write <<"\n";
                }
            }
        }
        MyFile.remove();
        replaceFile.copy(fileAddress);
        replaceFile.remove();
        MyFile.close();
        replaceFile.close();
        updatePlayListView();
    }
}

void PlayListClass::removeClickedMethod(){
    qDebug()<<"removeClickedMethod";
     for(int i=0; i<table->rowCount(); i++){
        if(table->item(i,0)->isSelected()){
           QString fileName = table->item(i,4)->data(0).toString();
           remove_file(fileName);
         }
     }
}


void PlayListClass::showPlaylist() {
    qDebug()<<"showPlaylist";
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

             }
        }
    }

    MyFile.close();
}


bool PlayListClass::fileIsExist(QString fileName){
    qDebug()<<"fileIsExist";
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
    qDebug()<<"addToPlaylist";

    if(!fileIsExist(filename) && filename.length()!=0){
        QString fileAddress = "C:/Users/admin/Desktop/write/a.txt";
        QFile MyFile(fileAddress);
        if(MyFile.open(QIODevice::Append)){

        QTextStream write(&MyFile);
        write <<filename;
        write <<"\n";
        MyFile.flush();
        MyFile.close();
        }
         updatePlayListView();
    }
    else if(filename.length()!=0){
        QMessageBox msg;
        msg.setText("The file already exists in the list ");
        msg.exec();
    }

}

void PlayListClass::on_actionadd_triggered()
{
    qDebug()<<"on_actionadd_triggered";
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.mp4 , *.wmv)");
    if(filename.length()!=0)
        addToPlaylist(filename);
}

void PlayListClass::updatePlayListView(){
     qDebug()<<"updatePlayListView"<<endl;
    cout<<"row:"<<table->rowCount()<<endl;
    int count = table->rowCount();
    for(int i=0; i<count; i++)
        table->removeRow(0);
    showPlaylist();
}

void PlayListClass::on_actionremove_to_playlist_triggered()
{
    qDebug()<<"on_actionremove_to_playlist_triggered";
    QMessageBox msg;
    QMessageBox msg2;
    msg.setWindowTitle("Remove mode");

    msg.addButton(QMessageBox::Yes);
    msg.addButton(QMessageBox::No);

    if(removeMode == false){
        msg.setText("Do you want to enable Remove mode?");
        int result = msg.exec();
        if(result == QMessageBox::Yes){
            msg2.setText("Remove mode : on");
            msg2.exec();
            removeMode=true;
            connect(table,&QTableWidget::cellClicked,table,&QTableWidget::selectRow);
            connect(table,&QTableWidget::cellClicked,this,&PlayListClass::removeClickedMethod);
        }
    }
    else{
        msg.setText("Do you want to disable Remove mode?");
        int result = msg.exec();
        if(result == QMessageBox::Yes){
            msg2.setText("Remove mode : off");
            msg2.exec();
            removeMode = false;
            disconnect(table,&QTableWidget::cellClicked,table,&QTableWidget::selectRow);
            disconnect(table,&QTableWidget::cellClicked,this,&PlayListClass::removeClickedMethod);
        }
    }


}
