#include "controller.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller controller_window;

     QMainWindow window;

  //  window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  //  window.show();

    controller_window.setWindowFlag(Qt::FramelessWindowHint);

    controller_window.show();

//    WoodPuppet window;

//     window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    return a.exec();
}
