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

/* Базовый класс для css-свойств */
class _BasicVal{
private:
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
    void setVal (QString str);
    void setVal (int val);
    void setVal (int r, int g, int b);
    void setVal (int r, int g, int b, int a);
};


class Color: _BasicVal{

};

class SuperCSS
{
public:
    Color color;

    SuperCSS();
};

#endif // SUPERCSS_H
