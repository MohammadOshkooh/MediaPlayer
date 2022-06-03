#ifndef SETTING_H
#define SETTING_H

#include <QMainWindow>

namespace Ui {
class Setting;
}

class Setting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Setting(QMainWindow *parent = nullptr);
    Setting *setting;
    int read(QString name);
    void write(QString name, QString action);
    void showView();
    ~Setting();

private slots:

    void on_volumeDown_clicked();

    void on_volumeUp_clicked();

    void on_jumpTimeDown_clicked();

    void on_jumpTimeUp_clicked();

    void on_clearPlaylist_clicked();

    void on_actionBack_triggered();

private:
    Ui::Setting *ui;
};

#endif // SETTING_H
