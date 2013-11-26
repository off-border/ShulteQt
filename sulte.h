#ifndef SULTE_H
#define SULTE_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QSettings>
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
