#include "home.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Home w;
    w.setVisible(true);
    //MainWindow w;
    //w.show();
    
    return a.exec();
}
