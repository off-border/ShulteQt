#include "graphic.h"
#include <QDebug>

Grafik::Grafik():QFrame(){
}

Grafik::Grafik(QWidget *parent):QFrame(parent){
    painter = new QPainter( this );
    css = new SuperCSS();
    css->background.color.setVal(123,23,200);
    setStyleSheet(css->toString());

    qDebug() << css->toString();


    closeBtn = new QPushButton( this );

}
void Grafik::mouseReleaseEvent(QMouseEvent *event){
    hide();
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
