#include "mainwindow.h"
#include <QDesktopWidget>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget *desktop = QApplication::desktop();
    MainWindow window;

    int WIDTH = 742;
    int HEIGHT = 428;

    int screenWidth;
    int screenHeight;

    int x, y;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    window.resize(WIDTH, HEIGHT);
    window.setFixedSize(WIDTH, HEIGHT);
    window.move( x, y );
    window.setWindowTitle("Ad and Crap Block");
    window.show();

    return a.exec();
}
