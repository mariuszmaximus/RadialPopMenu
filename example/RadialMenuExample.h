#pragma once

#include "radialmenu.h"
#include <qaction.h>
#include <qapplication.h>
#include <qcontainerfwd.h>
#include <qnamespace.h>
#include <qsize.h>
#include <qtresource.h>

class RadialMenuExample: public RadialMenu
{
public:
    RadialMenuExample():RadialMenu(){
        RadialMenu * menu= this;//new RadialMenu();
        menu->setMenuIcon(QIcon(":/res/geren.svg"), QSize(24, 24));
        menu->resize(400, 400);
        menu->show();
        menu->setAnimationDuration(300);
        menu->setActionAnimationDelay(50);
        menu->setRadialAngle( -3.1415926 / 2,  -1 * 3.1415926);
        menu->setRadialDistance(100);
        menu->setAlignment(Qt::AlignCenter);
        menu->setContentsMargins(10, 10, 10, 10);
    
    
        QVector<QString> icons = {":/res/daochu.svg",":/res/shezhi2.svg", ":/res/sousuo.svg", ":/res/tuichu.svg", ":/res/xiangqing.svg"};
        for(const QString & path : icons)
        {
            QAction * action = new QAction(menu);
            action->setIcon(QIcon(path));
            menu->addAction(action);
        }
        menu->resize(menu->idealSize());
       
    }

    static void initRes()
    {
        Q_INIT_RESOURCE(res);
        qApp->setStyleSheet("file:///:/stylesheet.qss");
    }
};