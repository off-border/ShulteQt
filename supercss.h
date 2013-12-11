#ifndef SUPERCSS_H
#define SUPERCSS_H

#include <QString>
#include <stdio.h>

#define CSS_MODE_DEFAULT    "default"
#define CSS_MODE_INHERITED  "inherited"
#define CSS_VAL_PX          "px"
#define CSS_VAL_PT          "pt"
#define CSS_VAL_PERC        "%"

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
    QString toString();
};

class _BasicVal{
private:
    QString measure;
    QString mode;
    int     valInt;
    QString valStr;
    _RGB    valGRB;
public:
    _BasicVal();
    _BasicVal(QString mo_mea_val);

    void set(QString str);
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
