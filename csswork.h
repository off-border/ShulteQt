#ifndef CSSWORK_H
#define CSSWORK_H
#include <QString>
#include <stdio.h>
class CSSColor{
public:
    int r;
    int g;
    int b;
    int a;

    CSSColor(){
        r = 0;
        g = 0;
        b = 0;
        a = 255;
    }
    CSSColor(int R, int G, int B){
        r = R;
        g = G;
        b = B;
        a = 255;
    }
    CSSColor(int R, int G, int B, int A){
        CSSColor(R,G,B);
        a = A;
    }

    void fromHtml(QString code){
        sscanf(code.toAscii(),"#%2d%2d%2d",&r,&g,&b);
        a = 255;
    }
    void fromInt(int R,int G, int B){
        r = R;
        g = G;
        b = B;
        a = 255;
    }
    void fromCssColor(CSSColor _color){
        r = _color.r;
        g = _color.g;
        b = _color.b;
        a = _color.a;
    }
    void fromCssColor(CSSColor* _color){
        r = _color->r;
        g = _color->g;
        b = _color->b;
        a = _color->a;
    }

    QString toHtmlH(){
        char htmlString[20];
        sprintf(htmlString,"%2x%2x%2x",r,g,b);
        return QString(htmlString);
    }
    QString toHtmlRGBa(){
        char htmlString[20];
        sprintf(htmlString,"rgba(%d,%d,%d,%d)",r,g,b,a);
        return QString(htmlString);
    }
};

class CSSColorProp{
public:
    CSSColor value;
    QString  attrName;
    CSSColorProp(QString _attrname, CSSColor _color){
        value = _color;
        attrName = _attrname;
    }
    QString toString(){
        return QString(attrName + ":" + value.toHtmlRGBa() + "; ");
    }
};

class CSSIntProp{
public:
    int value;
    QString measure;
    QString attrName;
    CSSIntProp(QString _attrname, int _value, QString _measure){
        attrName = _attrname;
        value = _value;
        measure = _measure;
    }
    QString toString(){
        return QString(attrName + ":" + QString::number(value) + measure + "; ");
    }
};

class CSSStringProp{
public:
    QString value;
    QString attrName;
    CSSStringProp(QString _attrname, QString _value){
        attrName = _attrname;
        value = _value;
    }
    QString toString(){
        return QString(attrName + ":" + value + "; ");
    }
};

class CSStyle{
public:
   //параметры
    QString selector;
    CSSColorProp*  backgroundColor;
    CSSColorProp*  borderColor;
    CSSColorProp*  color;
    CSSIntProp*    margin;
    CSSStringProp* textAlign;
    CSSIntProp*    fontSize;
  //конструктор
    CSStyle(){
        selector = "";
        backgroundColor = new CSSColorProp ("background-color",CSSColor());
        borderColor     = new CSSColorProp("border-color",CSSColor());
        color           = new CSSColorProp("color",CSSColor());
        margin          = new CSSIntProp("margin",0,"px");
        textAlign       = new CSSStringProp("text-align","center");
        fontSize        = new CSSIntProp("font-size",10,"px");
    }
  //в строку
    QString toString(){
        QString str;
        str = "";

        if (selector.length() > 0 )
            str += selector + "{";
        str += backgroundColor->toString();
        str += borderColor->toString();
        str += color->toString();
        str += margin->toString();
        str += textAlign->toString();
        str += fontSize->toString();
        if (selector.length() > 0 )
            str += "}";
        return str;
    }
};

#endif // CSSWORK_H
