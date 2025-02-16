#include <QAction>
#include <QApplication>
#include <qcontainerfwd.h>
#include <qnamespace.h>
#include <qsize.h>
#include <QResource>


#include "RadialMenuExample.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RadialMenuExample::initRes();
    a.setStyleSheet("file:///:/stylesheet.qss");
    RadialMenuExample radial;
    return a.exec();
}
