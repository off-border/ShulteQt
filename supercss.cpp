#include "supercss.h"


/* _RGB realization */
  //конструкторы
    _RGB::_RGB(): r(0),g(0),b(0),a(255){}
    _RGB::_RGB(int r, int g, int b): r(r),g(g),b(b),a(0){}
    _RGB::_RGB(int r, int g, int b, int a): r(r),g(g),b(b),a(a){}
    _RGB::_RGB(QString html_color){ fromString( html_color ); }
  //сеттеры
    void _RGB::setVal (QString html_color){ fromString(html_color); }
    void _RGB::setVal (int _r, int _g, int _b){ r=_r; g=_g; b=_b; a=255; }
    void _RGB::setVal (int _r, int _g, int _b, int _a){ r=_r; g=_g; b=_b; a=_a; }
    bool _RGB::fromString(QString html_color){
    if ( html_color.indexOf("#") == 0 ){
        if (QString(html_color).length() == 7)
            sscanf( html_color.toAscii(), "#%2x%2x%2x", &r, &g, &b );
        if (QString(html_color).length() == 4)
            sscanf( html_color.toAscii(), "#%1x%1x%1x", &r, &g, &b );
        a = 255;
        return true;
    }
    if ( html_color.indexOf("rgba") == 0 ){
            sscanf( html_color.toAscii(), "rgb%d,%d,%d,%d", &r, &g, &b, &a );
        return true;
    }
    if ( html_color.indexOf("rgb") == 0 ){
            sscanf( html_color.toAscii(), "rgb%d,%d,%d", &r, &g, &b );
            a = 255;
        return true;
    }
    return false;
}
  //в строку
    QString _RGB::toString(){
    return QString ( "rgba(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + "," + QString::number(a) );
}


/* _BasicVal realization */
  //конструкторы
    _BasicVal::_BasicVal(): parent(NULL), measure("px"), mode(CSS_MODE_DEFAULT), valInt(0), valStr(""), valRGB(_RGB()){}
    _BasicVal::_BasicVal(QString mo_mea_val)         { parent = NULL;  setVal(mo_mea_val);     }
    _BasicVal::_BasicVal(int val)                    { parent = NULL;  measure = "px";  setVal(val);     }
    _BasicVal::_BasicVal(int r, int g, int b)        { parent = NULL;  measure = "rgb"; setVal(r,g,b);   }
    _BasicVal::_BasicVal(int r, int g, int b, int a) { parent = NULL;  measure = "rgb"; setVal(r,g,b,a); }
  //сеттеры
    void _BasicVal::setParent(_SSComplexVal *_parent) { parent = _parent; }
    void _BasicVal::setMode(short _mode){
        mode = _mode;
        if ( _mode == CSS_MODE_CUSTOM && parent != NULL)
            parent->setMode( _mode );
    }
    void _BasicVal::setVal(QString str){
      //по умолчанию или унаследованный
        if ( str == "default" )   { mode = CSS_MODE_DEFAULT;   return; }
        if ( str == "inherited" ) { mode = CSS_MODE_INHERITED; return; }
        mode = CSS_MODE_CUSTOM;
      //если цвет
        if ( str.indexOf("#") >= 0 )   { valRGB.fromString( str ); measure="rgb"; return; }
        if ( str.indexOf("rgb") >= 0 ) {
            if( valRGB.fromString(str) ) {
                measure="rgb";
                return;
            }
        }
      //если размер
        //в пикселях
        if ( str.indexOf("px") > 0 ){
            measure="px";
            valInt = str.toInt();
            return;
        }
        //в процентах
        if ( str.indexOf("%") > 0 ){
            measure="%";
            valInt = str.toInt();
            return;
        }
      //если незнамо что
        measure = "str";
        valStr  =  str;
        return;
    }
    void _BasicVal::setVal(int val)                   { valInt = val;               setMode( CSS_MODE_CUSTOM ); return; }
    void _BasicVal::setVal(int r, int g, int b)       { valRGB.setVal(r, g, b);     setMode( CSS_MODE_CUSTOM ); return; }
    void _BasicVal::setVal(int r, int g, int b ,int a){ valRGB.setVal(r, g, b, a);  setMode( CSS_MODE_CUSTOM ); return; }
    void _BasicVal::setName(QString str)              { name = str; }
    void _BasicVal::setMeasure(QString str)           { measure = str; }
    void _BasicVal::setNameMeasParent(QString name, QString meas, _SSComplexVal *parent){ setName(name); setMeasure(meas); setParent(parent);}
  //в строку
    QString _BasicVal::_toString(QString prefix){
        if ( mode == CSS_MODE_DEFAULT || mode == CSS_MODE_INHERITED )
            return "";
        QString resStr;
        if ( measure == "px" ) resStr = prefix + QString::number( valInt ) + measure;
        if ( measure == "%"  ) resStr = prefix + QString::number( valInt ) + measure;
        if ( measure == "rgb") resStr = prefix + valRGB.toString();
      //Если мера неизвестна или string
        resStr = prefix + valStr;
      //Если не входит в сложное свойство, добавляем ';'
        if ( parent == NULL )
            resStr += ';';
        return resStr;
    }
    QString _BasicVal::toString(){
        return _toString(name + ": ");
    }

/* _SSComplexVal realization */
  //конструкторы
    _SSComplexVal::_SSComplexVal():parent( NULL ), mode( CSS_MODE_DEFAULT ){}
  //сеттеры
    void _SSComplexVal::setParent(_SSComplexVal *_parent)   { parent = _parent; }
    void _SSComplexVal::setName(QString _name)              { name = _name; }
    void _SSComplexVal::setMode(short _mode)   {
        mode = _mode;
        if ( _mode == CSS_MODE_CUSTOM && parent != NULL )
            parent->setMode( _mode );
   }

/* SSBorderSide realization */
  //конструкторы
    _SSBorderSide::_SSBorderSide():_SSComplexVal(){
        color.setNameMeasParent("color","rgb",this);
        width.setNameMeasParent("width","px", this);
        style.setNameMeasParent("style","str",this);
    }
  //в строку
    QString _SSBorderSide::toString(){
        if ( mode == CSS_MODE_DEFAULT || mode == CSS_MODE_INHERITED )
            return "";
        return name + ": " + color._toString("") + " " + width._toString("") + " " + style._toString("");
    }

/* SSColor realization */
  //конструкторы
    SSColor::SSColor():_BasicVal(){ setName("color"); setMeasure("rgb"); }


/* SSBorder realization */
  //конструкторы
    SSBorder::SSBorder():_SSComplexVal(){
        setName("border");
        top.setParent   ( this );
        left.setParent  ( this );
        bottom.setParent( this );
        right.setParent ( this );
    }
  //в строку
    QString SSBorder::toString(){
        if ( mode == CSS_MODE_DEFAULT || mode == CSS_MODE_INHERITED )
            return "";
        QString borders;
        borders += name + "-" + top.toString()    + ";";
        borders += name + "-" + left.toString()   + ";";
        borders += name + "-" + bottom.toString() + ";";
        borders += name + "-" + right.toString()  + ";";
        return borders;
    }




/* SuperCSS realization */
SuperCSS::SuperCSS()
{

}
