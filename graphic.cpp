#include "graphic.h"

Grafik::Grafik():QFrame(){
}
Grafik::Grafik(QWidget *parent):QFrame(parent){
    painter = new QPainter( this );
    css = new SuperCSS();
    css->color.setVal(123,12,234);
}
Grafik::~Grafik(){}
