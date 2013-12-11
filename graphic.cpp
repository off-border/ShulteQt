#include "graphic.h"

Grafik::Grafik():QFrame(){
}
Grafik::Grafik(QWidget *parent):QFrame(parent){
    painter = new QPainter( this );
    css = new SuperCSS();
}
Grafik::~Grafik(){}
