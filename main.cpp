#include <QtGui/QApplication>
#include "sulte.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Sulte w;
    //w.show();
    w.showMaximized();
    w.huyak();

    w.loadCells();


    return app.exec();
}
