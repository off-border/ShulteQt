/********************************************************************************
** Form generated from reading UI file 'sulte.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SULTE_H
#define UI_SULTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include "graphic.h"
#include "sulte.h"

QT_BEGIN_NAMESPACE

class Ui_sulteForm
{
public:
    QWidget *ebaniyWidget;
    QWidget *tableWidget;
    QFrame *controls;
    QSpinBox *spinBox;
    QLCDNumber *lcdNumber;
    QPushButton *startButton;
    QLabel *nextLabel;
    QLabel *avgTime;
    QPlainTextEdit *plainTextEdit;
    ExitLabel *exitButton;
    Grafik *frame;

    void setupUi(QMainWindow *sulteForm)
    {
        if (sulteForm->objectName().isEmpty())
            sulteForm->setObjectName(QString::fromUtf8("sulteForm"));
        sulteForm->resize(652, 392);
        sulteForm->setStyleSheet(QString::fromUtf8("*{\n"
"	font-size:20px;\n"
"	border: 2px solid black;\n"
"	border-radius: 10px;\n"
"	color: gray;\n"
"}\n"
"QWidget#ebaniyWidget{\n"
"	background-color:#aaa;\n"
"}"));
        ebaniyWidget = new QWidget(sulteForm);
        ebaniyWidget->setObjectName(QString::fromUtf8("ebaniyWidget"));
        ebaniyWidget->setMinimumSize(QSize(0, 0));
        tableWidget = new QWidget(ebaniyWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 30, 321, 231));
        tableWidget->setStyleSheet(QString::fromUtf8("QWidget#tableWidget{background-color:transparent;\n"
"border-color:transparent; }\n"
""));
        controls = new QFrame(ebaniyWidget);
        controls->setObjectName(QString::fromUtf8("controls"));
        controls->setGeometry(QRect(430, 50, 181, 291));
        controls->setStyleSheet(QString::fromUtf8("border-color:gray;"));
        controls->setFrameShape(QFrame::StyledPanel);
        controls->setFrameShadow(QFrame::Raised);
        spinBox = new QSpinBox(controls);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 16, 141, 51));
        QPalette palette;
        QBrush brush(QColor(128, 128, 128, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(245, 245, 245, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        spinBox->setPalette(palette);
        spinBox->setCursor(QCursor(Qt::SizeVerCursor));
        spinBox->setStyleSheet(QString::fromUtf8("background-color: #f5f5f5;\n"
"border-width:1px;"));
        spinBox->setFrame(true);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMinimum(1);
        spinBox->setMaximum(21);
        spinBox->setValue(7);
        lcdNumber = new QLCDNumber(controls);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(30, 76, 111, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush2(QColor(66, 66, 66, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        lcdNumber->setPalette(palette1);
        lcdNumber->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"border-color:transparent;"));
        startButton = new QPushButton(controls);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(20, 136, 141, 51));
        startButton->setCursor(QCursor(Qt::PointingHandCursor));
        startButton->setStyleSheet(QString::fromUtf8("background-color:#55dd55;\n"
"color: white;\n"
"border-width:1px;\n"
"border-color:black;"));
        nextLabel = new QLabel(controls);
        nextLabel->setObjectName(QString::fromUtf8("nextLabel"));
        nextLabel->setGeometry(QRect(20, 204, 141, 31));
        avgTime = new QLabel(controls);
        avgTime->setObjectName(QString::fromUtf8("avgTime"));
        avgTime->setGeometry(QRect(23, 242, 140, 31));
        avgTime->setStyleSheet(QString::fromUtf8("border:none; font-size: 20px;"));
        plainTextEdit = new QPlainTextEdit(ebaniyWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(50, 300, 321, 71));
        plainTextEdit->setStyleSheet(QString::fromUtf8("font-size:20px; border-color:transparent;"));
        exitButton = new ExitLabel(ebaniyWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(570, 10, 71, 41));
        exitButton->setCursor(QCursor(Qt::PointingHandCursor));
        exitButton->setStyleSheet(QString::fromUtf8("border-color:gray;\n"
"\n"
""));
        exitButton->setAlignment(Qt::AlignCenter);
        frame = new Grafik(ebaniyWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(170, 280, 120, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        sulteForm->setCentralWidget(ebaniyWidget);

        retranslateUi(sulteForm);

        QMetaObject::connectSlotsByName(sulteForm);
    } // setupUi

    void retranslateUi(QMainWindow *sulteForm)
    {
        sulteForm->setWindowTitle(QApplication::translate("sulteForm", "Sulte", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox->setToolTip(QApplication::translate("sulteForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">table size</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">rotate the wheel </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">or type</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent"
                        ":0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        spinBox->setSpecialValueText(QString());
        spinBox->setSuffix(QString());
        startButton->setText(QApplication::translate("sulteForm", "Start", 0, QApplication::UnicodeUTF8));
        nextLabel->setText(QApplication::translate("sulteForm", "Next: ", 0, QApplication::UnicodeUTF8));
        avgTime->setText(QApplication::translate("sulteForm", "Avg. time: ", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("sulteForm", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sulteForm: public Ui_sulteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SULTE_H
