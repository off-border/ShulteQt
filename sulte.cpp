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
    connect(ui->exitButton,SIGNAL(clicked()),SLOT(exit()));
    connect(ui->startButton,SIGNAL(clicked()),SLOT(start()));
    connect(ui->spinBox, SIGNAL( valueChanged(int) ), SLOT( showAvg_(int)) );
    timer = new QTimer();

    for (int i= 0; i<50; i++)
        for (int j= 0; j< 50; j++){
            cells[i][j] = new TableCell(ui->tableWidget);
            connect(cells[i][j],SIGNAL(clicked()),SLOT(cellClicked()));
        }

    settings = new QSettings("OutOfOrder inc.", "Shulte");
    if ( settings->value("tableSize").toInt() != 0 )
        ui->spinBox->setValue(settings->value("/tableSize").toInt());
    QList<int> lr;
    if ( settings->value("lastResults").toByteArray().size() != 0 ){
        lastResults.fromByteArray( settings->value("lastResults").toByteArray() );
    }
    showAvg();

    startBtStyle = new CSStyle();
    startBtStyle->backgroundColor->value.fromHtml("#55dd55");
    startBtStyle->color->value.fromInt(255,255,255);
    startBtStyle->borderWidth->value = 1;
    startBtStyle->borderColor->value.fromInt(0,0,0);
    startBtStyle->fontSize->value = 20;
    ui->startButton->setStyleSheet( startBtStyle->toString() );

}
Sulte::~Sulte()
{
    delete ui;
}
void Sulte:: exit(){
    settings->setValue("tableSize",ui->spinBox->value());
    settings->setValue("lastResults", lastResults.toByteArray());
    close();
}

void Sulte::huyak(){
    ui->plainTextEdit->hide();

    int frameW = ui->ebaniyWidget->width();
    int frameH = ui->ebaniyWidget->height();
    ui->plainTextEdit->appendPlainText("Width: " + QString().setNum(frameW) + " \n Height: " + QString().setNum(frameH));

    int tableSize = frameH - frameH*0.1;
    ui->tableWidget->resize(tableSize,tableSize);
    ui->tableWidget->move( (frameW-tableSize)/2, (frameH-tableSize)/2);

    ui->controls->move( frameW - (frameW-tableSize)/4 -  ui->controls->width()/2, (frameH - ui->controls->height())/2 );
    ui->exitButton->move(frameH*0.05, frameH*0.05);

    ui->spinBox->setStyleSheet("QToolTip{border-radius:0px; font-weight: bold;}");


}

void Sulte::log(QString msg){
    ui->plainTextEdit->appendPlainText(msg);
}

void Sulte::start(){
    loadCells();
    nextVal = 1;
    success = false;
    ui->nextLabel->setText("Next: 1");
    connect(timer,SIGNAL(timeout()),SLOT(updateTime()));
    startTime = QTime::currentTime();
    timer->setInterval(100);
    timer->start();
    disconnect( ui->startButton, SIGNAL(clicked()), this, SLOT( start() ));
    connect   ( ui->startButton, SIGNAL(clicked()), this, SLOT( stop()  ) );
    ui->startButton->setText("STOP");
    startBtStyle->color->value.fromInt(255,255,0);
    ui->startButton->setStyleSheet( startBtStyle->toString() );
}

void Sulte::stop(){
    qDebug() << "Stopped";
    timer->stop();
    sprintf(displayTime,"%d.%d",totalMsec/1000,totalMsec%1000%100/10);
    ui->lcdNumber->display(displayTime);
    disconnect( ui->startButton, SIGNAL(clicked()), this, SLOT( stop()  ) );
    connect   ( ui->startButton, SIGNAL(clicked()), this, SLOT( start() ) );
    ui->startButton->setText("Start");
    startBtStyle->color->value.fromInt(255,255,255);
    ui->startButton->setStyleSheet( startBtStyle->toString() );
    if ( ! success )
        return;
    for (int i= 0; i< N; i++)
        for(int j= 0; j< N; j++){
            cells[i][j]->setText(":)");
        }
    lastResults.push(ui->spinBox->value(), totalMsec );
    showAvg();
}

void Sulte::updateTime(){
    totalMsec = startTime.msecsTo(QTime::currentTime());
    sprintf(displayTime,"%d",totalMsec/1000);
    ui->lcdNumber->display(displayTime);
}

void Sulte::loadCells(){
    for (int i=0; i<50; i++)
        for (int j=0; j<50; j++)
            cells[i][j]->hide();

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
            cells[i][j]->setSize( cellWidth );
            cells[i][j]->move(i*cellWidth, j*cellWidth);
            cells[i][j]->setText(n2s(cellVals[i*N+j]));
            //cells[i][j]->setStyleSheet(cells[i][j]->styleSheet()+"font-size: "+n2s(cellFont) + "px;");
            cells[i][j]->css->fontSize->value = cellFont;
            cells[i][j]->setStyleSheet(cells[i][j]->css->toString());
            cells[i][j]->value = cellVals[i*N+j];
            cells[i][j]->show();
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
    cell->blink();
    if (val == N*N){
        success = true;
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

void Sulte::showAvg(){
    int avg = lastResults.getAvg(ui->spinBox->value());
    int sec = avg / 1000;
    int dsec = avg % 1000 / 100;
    ui->avgTime->setText( "Avg. time: " + n2s(sec) + "." + n2s(dsec) );
}

void Sulte::showAvg_(int a){
    showAvg();
}

TableCell::TableCell(QWidget *parent):QPushButton(parent){
    setStyleSheet( "border-color:gray; margin: 3px; background-color:#f5f5f5; text-align:center;" );

    currentColor = new CSSColor(245,245,245);
    baseColor = new CSSColor(245,245,245);

    css = new CSStyle();
    css->backgroundColor    ->value.fromCssColor(currentColor);
    css->borderColor        ->value.fromInt(120,120,120);
    css->margin             ->value = 3;
    css->textAlign          ->value = "center";
    css->color              ->value.fromInt(80,80,80);
    setStyleSheet(css->toString());

    downtimer = new QTimer();

}

void TableCell::setSize(int width){
    resize(width,width);
}

void TableCell::blink(){
    currentColor->fromInt(170,255,170);
    setColor();
    downtimer->setInterval(20);
    connect(downtimer, SIGNAL(timeout()),SLOT(animateColor()));
    downtimer->start();

}

void TableCell::animateColor(){
    CSSColor* bc = baseColor;
    CSSColor* cc = currentColor;
    if (cc->r==bc->r&&cc->g==bc->g&&cc->b==bc->b&&cc->a==bc->a){
        downtimer->stop();
        return;
    }
    if (cc->r != bc->r)
        cc->r += (bc->r - cc->r)/abs(bc->r - cc->r);
    if (cc->g != bc->g)
        cc->g += (bc->g - cc->g)/abs(bc->g - cc->g);
    if (cc->b != bc->b)
        cc->b += (bc->b - cc->b)/abs(bc->b - cc->b);
    if (cc->a != bc->a)
        cc->a += (bc->a - cc->a)/abs(bc->a - cc->a);
    setColor();
}

void TableCell::setColor(){
    css->backgroundColor->value.fromCssColor(currentColor);
    setStyleSheet(css->toString());
}

