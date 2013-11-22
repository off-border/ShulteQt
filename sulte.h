#ifndef SULTE_H
#define SULTE_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>

namespace Ui {
class sulteForm;
}

class TableCell: public QPushButton{
    Q_OBJECT
public:
    int value;
    TableCell(QWidget *parent = 0);
    void setSize(int width);
};

class Sulte : public QMainWindow
    {
        Q_OBJECT

    public:
        int N;
        TableCell* cells[50][50];
        int cellVals[50*50];
        int nextVal;

        explicit Sulte(QWidget *parent = 0);
        ~Sulte();
        void huyak();
        void loadCells();
        void log(QString msg);
    public slots:
        void start();
        void stop();
        void cellClicked();

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
