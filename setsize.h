#ifndef SETSIZE_H
#define SETSIZE_H

#include <QMainWindow>

namespace Ui {
class SetSize;
}

class SetSize : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetSize(QWidget *parent = nullptr);
    ~SetSize();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SetSize *ui;
};

#endif // SETSIZE_H
