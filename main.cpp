#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w("Matrix Caluclator",5);
    w.show();

    return a.exec();
}
