#ifndef SUPERCSS_H
#define SUPERCSS_H

#include <QString>
#include <stdio.h>

#define CSS_MODE_DEFAULT    0
#define CSS_MODE_INHERITED  1
#define CSS_MODE_CUSTOM     2
#define CSS_VAL_PX          "px"
#define CSS_VAL_PT          "pt"
#define CSS_VAL_PERC        "%"

/* класс для хранения значений в rgb(rgba) */
class _RGB{
public:
    int r;
    int g;
    int b;
    int a;
    _RGB();
    _RGB(int r, int g, int b);
    _RGB(int r, int g, int b, int a);
    _RGB(QString html_color);
    void setVal (QString html_color);
    void setVal (int _r, int _g, int _b);
    void setVal (int _r, int _g, int _b, int _a);
    bool fromString (QString html_color);
    QString toString();
};

/* Базовый класс для комплексных свойств */
class _SSComplexVal{
protected:
    _SSComplexVal *parent;
    QString name;
    short   mode;
public:
    _SSComplexVal();
    void setParent(_SSComplexVal *_parent);
    void setMode(short   _mode);
    void setName(QString _name);
};

/* Базовый класс для простых css-свойств */
class _BasicVal{
protected:
    _SSComplexVal *parent;
    QString name;
    QString measure;
    short   mode;
    int     valInt;
    QString valStr;
    _RGB    valRGB;
public:
    _BasicVal   ();
    _BasicVal   (QString mo_mea_val);
    _BasicVal   (int val);                     //Default measure is pixels in that case
    _BasicVal   (int r, int g, int b);
    _BasicVal   (int r, int g, int b, int a);
    void setParent(_SSComplexVal *_parent);
    void setMode  (short _mode);
    void setVal (QString str);
    void setVal (int val);
    void setVal (int r, int g, int b);
    void setVal (int r, int g, int b, int a);
    void setName(QString str);
    void setMeasure(QString str);
    void setNameMeasParent(QString name, QString meas, _SSComplexVal *parent);
    QString toString();
    QString _toString(QString prefix);
};

/* Цвет текста */
class SSColor: public _BasicVal{
public:
    SSColor();
};

/* Границы */
/* любая сторона */
class _SSBorderSide: public _SSComplexVal{
public:
    _BasicVal width;
    _BasicVal color;
    _BasicVal style;
    _SSBorderSide();
    QString toString();
};
/* все стороны */
class SSBorder: _SSComplexVal{
public:
    _SSBorderSide top;
    _SSBorderSide left;
    _SSBorderSide bottom;
    _SSBorderSide right;
    SSBorder();
    QString toString();
};

/* бэкграунд */
/* имейдж */
class _SSBGImage: _SSComplexVal{
public:
    QString url;
    _SSBGImage();
};

class SSBackground: public _SSComplexVal{
public:
    _BasicVal color;
    SSBackground();
    QString toString();
};

class SuperCSS
{
public:
    SSColor         color;
    SSBorder        border;
    SSBackground    background;
    SuperCSS();
    QString toString();
};

#endif // SUPERCSS_H
