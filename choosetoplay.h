#ifndef CHOOSETOPLAY_H
#define CHOOSETOPLAY_H

#include <QWidget>

namespace Ui {
class ChooseToPlay;
}

class ChooseToPlay : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseToPlay(QWidget *parent = nullptr);
    ~ChooseToPlay();

private:
    Ui::ChooseToPlay *ui;
};

#endif // CHOOSETOPLAY_H
