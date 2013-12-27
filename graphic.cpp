#include "graphic.h"
#include <QDebug>

Grafik::Grafik():QFrame(){
}
Grafik::Grafik(QWidget *parent):QFrame(parent){
    painter = new QPainter( this );
    css = new SuperCSS();

    css->background.color.setVal(123,23,200);
    qDebug() << css->toString();

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
