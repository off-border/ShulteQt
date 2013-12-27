#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <QPushButton>
#include "supercss.h"

class Grafik: public QFrame{
   Q_OBJECT
public:
    QPainter *painter;
    SuperCSS *css;
    QPushButton *closeBtn;

    explicit Grafik();
    explicit Grafik(QWidget *parent=0);
    ~Grafik();
public slots:
    void openClose();

};



#endif // GRAPHIC_H
