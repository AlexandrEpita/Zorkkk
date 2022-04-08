#include "mainwindow.h"

#include <QApplication>

#include "ZorkUL.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ZorkUL temp;
    temp.play();
    //eeturn 0;
    return a.exec();
}
