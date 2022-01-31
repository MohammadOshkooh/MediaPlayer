#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    Setting *setting;
    int read(QString name);
    void write(QString name, QString action);
    void showView();
    ~Setting();

private slots:
    void on_pushButton_clicked();

    void on_volumeDown_clicked();

    void on_volumeUp_clicked();

    void on_jumpTimeDown_clicked();

    void on_jumpTimeUp_clicked();

private:
    Ui::Setting *ui;
};

#endif // SETTING_H
