#include "sulte.h"
#include "ui_sulte.h"
#include <math.h>

QString n2s(int n){
    return QString::number(n);
}

Sulte::Sulte(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sulteForm)
{
    N = 0;
    nextVal = 0;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->exitButton,SIGNAL(clicked()),SLOT(close()));
    connect(ui->startButton,SIGNAL(clicked()),SLOT(start()));
}
Sulte::~Sulte()
{
    delete ui;
}
void Sulte::huyak(){
    int frameW = ui->ebaniyWidget->width();
    int frameH = ui->ebaniyWidget->height();
    ui->plainTextEdit->appendPlainText("Width: " + QString().setNum(frameW) + " \n Height: " + QString().setNum(frameH));

    int tableSize = frameH - frameH*0.1;
    ui->tableWidget->resize(tableSize,tableSize);
    ui->tableWidget->move( (frameW-tableSize)/2, (frameH-tableSize)/2);

    ui->controls->move( frameW - (frameW-tableSize)/3 -  ui->controls->width()/2, (frameH - ui->controls->height())/2 );
    ui->exitButton->move(frameH*0.05, frameH*0.05);
}
void Sulte::log(QString msg){
    ui->plainTextEdit->appendPlainText(msg);
}
void Sulte::start(){
    loadCells();
    nextVal = 1;
    ui->nextLabel->setText("Next: 1");
}
void Sulte::stop(){
    for (int i= 0; i< N; i++)
        for(int j= 0; j< N; j++)
            //delete cells[i][j];
            cells[i][j]->setText(":)");
}



TableCell::TableCell(QWidget *parent):QPushButton(parent){
    setStyleSheet( "border-color:gray; margin: 3px; background-color:#f5f5f5; text-align:center;" );
}

void TableCell::setSize(int width){
    resize(width,width);
}

void Sulte::loadCells(){
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            delete cells[i][j];

    int tableWidth = ui->tableWidget->width();
    N = ui->spinBox->value();
    log ("N = "+n2s(N));
    int cellWidth = tableWidth / N;
    log("cellWidth: " + n2s(cellWidth));

    bool cellValTrue=false;
    for(int i=0; i< N*N; i++){
        cellValTrue = false;
        while(!cellValTrue){
            cellVals[i] = rand() % (N*N)+1;
            cellValTrue = true;
            for (int j= 0; j< i; j++){
                if (cellVals[i] == cellVals[j] )
                    cellValTrue = false;
            }
        }
        log("cellval = " + n2s(cellVals[i]));
    }

    int cellFont=cellWidth/3;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cells[i][j] = new TableCell(ui->tableWidget);
            cells[i][j]->setSize( cellWidth );
            cells[i][j]->move(i*cellWidth, j*cellWidth);
            cells[i][j]->setText(n2s(cellVals[i*N+j]));
            cells[i][j]->setStyleSheet(cells[i][j]->styleSheet()+"font-size: "+n2s(cellFont) + "px;");
            cells[i][j]->value = cellVals[i*N+j];
            cells[i][j]->show();
            connect(cells[i][j],SIGNAL(clicked()),SLOT(cellClicked()));
        }
    }

}

void Sulte::cellClicked(){
    TableCell* cell = (TableCell*)sender();
    log("senderVal " + n2s(cell->value));
    int val = cell->value;
    if ( val != nextVal ){
        log("!= " + n2s(nextVal));
        return;
    }
    if (val == N*N){
        stop();
    }


    for(int i= 0; i< N*N; i++){
        if(nextVal == cellVals[i]){
            cellVals[i] = 0;
        }
    }

    int min = N*N;
    for(int i= 0; i< N*N; i++){
        if(min > cellVals[i] && cellVals[i] != 0){
            min = cellVals[i];
        }
    }
    nextVal = min;
    ui->nextLabel->setText("Next: " + n2s(nextVal));
}


