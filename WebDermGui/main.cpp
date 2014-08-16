#include "mainwindow.h"
#include <QApplication>
#include "mousecolorgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    MouseColorGui m;
    m.show();
    return a.exec();
}
