#include "controller.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller controller_window;

    controller_window.setWindowFlag(Qt::FramelessWindowHint );

    controller_window.show();


    return a.exec();
}
