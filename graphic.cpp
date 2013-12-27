#include "graphic.h"

Grafik::Grafik():QFrame(){
}
Grafik::Grafik(QWidget *parent):QFrame(parent){
    painter = new QPainter( this );
    css = new SuperCSS();
    closeBtn = new QPushButton( this );
}
Grafik::~Grafik(){}
void Grafik::openClose(){
    if(isVisible()){
        hide();
        return;
    }
    if(!isVisible()){
        move(0,0);
        closeBtn->move(0,0);
        resize(parentWidget()->width(),parentWidget()->height());
        show();
    }
}
