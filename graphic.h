#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include "supercss.h"

class Grafik: public QFrame{
   Q_OBJECT
public:
    QPainter *painter;
    SuperCSS *css;

    explicit Grafik();
    explicit Grafik(QWidget *parent=0);
    ~Grafik();
};



#endif // GRAPHIC_H
