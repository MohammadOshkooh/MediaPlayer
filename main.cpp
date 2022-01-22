#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller controller_window;
//    controller_window.setStyleSheet("QWidget {background-image:url(:/new/prefix2/—Pngtree—beautiful technology website business poster_1107136.jpg)}");
    controller_window.show();

    return a.exec();
}
