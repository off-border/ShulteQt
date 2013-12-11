#include "supercss.h"


/* _RGB realization */
_RGB::_RGB(): r(0),g(0),b(0),a(255){}
_RGB::_RGB(int r, int g, int b): r(r),g(g),b(b),a(0){}
_RGB::_RGB(int r, int g, int b, int a): r(r),g(g),b(b),a(a){}
_RGB::_RGB(QString html_color){
    if (QString(html_color).length() == 7)
        sscanf( html_color.toAscii(), "#%2x%2x%2x", &r, &g, &b );
    if (QString(html_color).length() == 4)
        sscanf( html_color.toAscii(), "#%1x%1x%1x", &r, &g, &b );
    a = 255;
}
QString _RGB::toString(){
    return QString ( "rgba(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + "," + QString::number(a) );
}

/* _BasicVal realization */
_BasicVal::_BasicVal(): measure("px"), mode("default"), valInt(0), valStr(""), valGRB(_RGB()){}
_BasicVal::_BasicVal(QString mo_mea_val){
        set(mo_mea_val);
}

void _BasicVal::set(QString str){
    if ( str == CSS_MODE_DEFAULT )   { mode = CSS_MODE_DEFAULT;   return; }
    if ( str == CSS_MODE_INHERITED ) { mode = CSS_MODE_INHERITED; return; }

    /*  ....  */
}

/* SuperCSS realization */
SuperCSS::SuperCSS()
{
}
