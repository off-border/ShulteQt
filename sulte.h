#ifndef SULTE_H
#define SULTE_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QSettings>
#include <QList>
#include <QDebug>
#include "csswork.h"

namespace Ui {
class sulteForm;
}

class TableCell: public QPushButton{
    Q_OBJECT
public:
    int value;
    int blinkTime;
    int blinkSteps;
    int blinkDt;
    CSStyle* css;
    CSSColor* baseColor;
    CSSColor* currentColor;
    QTimer* downtimer;

    TableCell(QWidget *parent = 0);
    void setSize(int width);
    void setColor();

public slots:
    void blink();
    void animateColor();
};

class LastResults{
public:
    int results [23][101];
    LastResults(){
        for (int i=0; i< 22; i++)
            for (int j= 0; j< 100; j++)
                results[i][j] = 0;
    }

    QByteArray toByteArray(){
        QByteArray  byteArray;
        QDataStream stream(&byteArray, QIODevice::ReadWrite);
        for (int i=0; i< 21; i++)
            for (int j= 0; j< 100; j++){
                stream << results[i][j];
            }
        return byteArray;
    }
    void fromByteArray(QByteArray byteArray){
        QDataStream stream(&byteArray, QIODevice::ReadWrite);
        for (int i=0; i< 21; i++)
            for (int j= 0; j< 100; j++)
                stream >> results[i][j];
    }
    void push( int tabSize, int msec ){
        for (int i= 0; i< 99; i++){
            results[tabSize][99-i] = results[tabSize][99-i-1];
        }
        results[tabSize][0] = msec;
    }
    int getAvg(int tabSize){
        int sum = 0;
        int k   = 0;
        for (int i= 0; i< 10; i++){
            if ( results[tabSize][i] == 0 )
                break;
            sum += results[tabSize][i];
            k++;
        }
        if (k ==0 )
            return 0;
        return sum / k;
    }
    QString toString(int tabSize){
        QString str="";
        for (int i=0; i<100; i++)
            str += str.number(results[tabSize][i]) + " ";
        return str;
    }
};

class Sulte : public QMainWindow
    {
        Q_OBJECT

    public:
        int     N;
        TableCell* cells[50][50];
        int     cellVals[50*50];
        int     nextVal;
        QTimer* timer;
        QTime   startTime;
        int     totalMsec;
        char    displayTime[30];
        bool    success;
        QSettings* settings;
        LastResults lastResults;

        CSStyle* startBtStyle;

        explicit Sulte(QWidget *parent = 0);
        ~Sulte();
        void huyak();
        void loadCells();
        void log(QString msg);
    public slots:
        void start();
        void stop();
        void cellClicked();
        void updateTime();
        void exit();
        void showAvg();
        void showAvg_(int);

        void resizeEvent(QResizeEvent*);

private:
        Ui::sulteForm *ui;
    };

class ExitLabel: public QLabel{
    Q_OBJECT
    protected:
        void mouseReleaseEvent(QMouseEvent *ev){
            emit clicked();
        }
    public:
        ExitLabel(QWidget *parent = 0):QLabel(parent){
        }

    signals:
        void clicked();
    };


#endif // SULTE_H
