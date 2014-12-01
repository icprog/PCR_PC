/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 27. Jan 19:21:28 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_16;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *tab_2;
    QFrame *frame;
    QGroupBox *groupBox;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinBoxKI;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBoxKP;
    QLabel *label_5;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEditTemp0Samples;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEditTemp1Samples;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEditTemp2Samples;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEditTemp3Samples;
    QLabel *label_9;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEditADC0;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEditADC1;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *lineEditADC2;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_15;
    QLineEdit *lineEditADC3;
    QLabel *label_24;
    QGroupBox *groupBoxGraphSel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxTemp0;
    QCheckBox *checkBoxTemp1;
    QCheckBox *checkBoxTemp2;
    QCheckBox *checkBoxTemp3;
    QCheckBox *checkBoxAvTemp;
    QCheckBox *checkBoxHide;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxSetTemp;
    QLabel *label;
    QComboBox *comboBoxFreq;
    QCheckBox *checkBoxNominalTemp;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditOffset;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QFrame *frame_2;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_12;
    QLineEdit *lineEditProgramState;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_13;
    QTimeEdit *timeEdit_current;
    QPushButton *exitButton;
    QFrame *frame_3;
    QCustomPlot *plot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(931, 597);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 941, 601));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 20, 777, 99));
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(38);
        font.setBold(true);
        font.setWeight(75);
        label_15->setFont(font);

        horizontalLayout_12->addWidget(label_15);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout_12);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_16->setFont(font1);

        verticalLayout_8->addWidget(label_16);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 160, 826, 332));
        verticalLayout_9 = new QVBoxLayout(layoutWidget1);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Calibri"));
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setWeight(75);
        label_14->setFont(font2);

        verticalLayout_9->addWidget(label_14);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font2);

        verticalLayout_9->addWidget(label_17);

        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);

        verticalLayout_9->addWidget(label_19);

        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);

        verticalLayout_9->addWidget(label_18);

        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Calibri"));
        font3.setPointSize(26);
        font3.setBold(false);
        font3.setWeight(50);
        label_20->setFont(font3);

        verticalLayout_9->addWidget(label_20);

        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font3);

        verticalLayout_9->addWidget(label_21);

        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Calibri"));
        font4.setPointSize(21);
        font4.setBold(false);
        font4.setWeight(50);
        label_22->setFont(font4);

        verticalLayout_9->addWidget(label_22);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        frame = new QFrame(tab_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(680, 10, 241, 501));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        frame->setMidLineWidth(1);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 290, 101, 81));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 68, 52));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        spinBoxKI = new QSpinBox(layoutWidget2);
        spinBoxKI->setObjectName(QString::fromUtf8("spinBoxKI"));

        horizontalLayout_5->addWidget(spinBoxKI);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        spinBoxKP = new QSpinBox(layoutWidget2);
        spinBoxKP->setObjectName(QString::fromUtf8("spinBoxKP"));

        horizontalLayout_4->addWidget(spinBoxKP);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);


        verticalLayout_4->addLayout(horizontalLayout_4);

        layoutWidget3 = new QWidget(frame);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 380, 101, 108));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEditTemp0Samples = new QLineEdit(layoutWidget3);
        lineEditTemp0Samples->setObjectName(QString::fromUtf8("lineEditTemp0Samples"));
        lineEditTemp0Samples->setEnabled(false);

        horizontalLayout_6->addWidget(lineEditTemp0Samples);

        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lineEditTemp1Samples = new QLineEdit(layoutWidget3);
        lineEditTemp1Samples->setObjectName(QString::fromUtf8("lineEditTemp1Samples"));
        lineEditTemp1Samples->setEnabled(false);

        horizontalLayout_7->addWidget(lineEditTemp1Samples);

        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEditTemp2Samples = new QLineEdit(layoutWidget3);
        lineEditTemp2Samples->setObjectName(QString::fromUtf8("lineEditTemp2Samples"));
        lineEditTemp2Samples->setEnabled(false);

        horizontalLayout_8->addWidget(lineEditTemp2Samples);

        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lineEditTemp3Samples = new QLineEdit(layoutWidget3);
        lineEditTemp3Samples->setObjectName(QString::fromUtf8("lineEditTemp3Samples"));
        lineEditTemp3Samples->setEnabled(false);

        horizontalLayout_9->addWidget(lineEditTemp3Samples);

        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);


        verticalLayout_5->addLayout(horizontalLayout_9);

        layoutWidget4 = new QWidget(frame);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(120, 380, 101, 108));
        verticalLayout_10 = new QVBoxLayout(layoutWidget4);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lineEditADC0 = new QLineEdit(layoutWidget4);
        lineEditADC0->setObjectName(QString::fromUtf8("lineEditADC0"));
        lineEditADC0->setEnabled(false);

        horizontalLayout_10->addWidget(lineEditADC0);

        label_10 = new QLabel(layoutWidget4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);


        verticalLayout_10->addLayout(horizontalLayout_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lineEditADC1 = new QLineEdit(layoutWidget4);
        lineEditADC1->setObjectName(QString::fromUtf8("lineEditADC1"));
        lineEditADC1->setEnabled(false);

        horizontalLayout_13->addWidget(lineEditADC1);

        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_13->addWidget(label_11);


        verticalLayout_10->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        lineEditADC2 = new QLineEdit(layoutWidget4);
        lineEditADC2->setObjectName(QString::fromUtf8("lineEditADC2"));
        lineEditADC2->setEnabled(false);

        horizontalLayout_14->addWidget(lineEditADC2);

        label_23 = new QLabel(layoutWidget4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_14->addWidget(label_23);


        verticalLayout_10->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        lineEditADC3 = new QLineEdit(layoutWidget4);
        lineEditADC3->setObjectName(QString::fromUtf8("lineEditADC3"));
        lineEditADC3->setEnabled(false);

        horizontalLayout_15->addWidget(lineEditADC3);

        label_24 = new QLabel(layoutWidget4);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_15->addWidget(label_24);


        verticalLayout_10->addLayout(horizontalLayout_15);

        groupBoxGraphSel = new QGroupBox(frame);
        groupBoxGraphSel->setObjectName(QString::fromUtf8("groupBoxGraphSel"));
        groupBoxGraphSel->setGeometry(QRect(10, 60, 94, 171));
        verticalLayoutWidget = new QWidget(groupBoxGraphSel);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 73, 140));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxTemp0 = new QCheckBox(verticalLayoutWidget);
        checkBoxTemp0->setObjectName(QString::fromUtf8("checkBoxTemp0"));
        checkBoxTemp0->setAutoFillBackground(false);
        checkBoxTemp0->setChecked(true);

        verticalLayout->addWidget(checkBoxTemp0);

        checkBoxTemp1 = new QCheckBox(verticalLayoutWidget);
        checkBoxTemp1->setObjectName(QString::fromUtf8("checkBoxTemp1"));
        checkBoxTemp1->setChecked(true);

        verticalLayout->addWidget(checkBoxTemp1);

        checkBoxTemp2 = new QCheckBox(verticalLayoutWidget);
        checkBoxTemp2->setObjectName(QString::fromUtf8("checkBoxTemp2"));
        checkBoxTemp2->setChecked(true);

        verticalLayout->addWidget(checkBoxTemp2);

        checkBoxTemp3 = new QCheckBox(verticalLayoutWidget);
        checkBoxTemp3->setObjectName(QString::fromUtf8("checkBoxTemp3"));
        checkBoxTemp3->setChecked(true);

        verticalLayout->addWidget(checkBoxTemp3);

        checkBoxAvTemp = new QCheckBox(verticalLayoutWidget);
        checkBoxAvTemp->setObjectName(QString::fromUtf8("checkBoxAvTemp"));
        checkBoxAvTemp->setChecked(true);

        verticalLayout->addWidget(checkBoxAvTemp);

        checkBoxHide = new QCheckBox(verticalLayoutWidget);
        checkBoxHide->setObjectName(QString::fromUtf8("checkBoxHide"));
        checkBoxHide->setChecked(true);

        verticalLayout->addWidget(checkBoxHide);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 60, 121, 141));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        doubleSpinBoxSetTemp = new QDoubleSpinBox(widget);
        doubleSpinBoxSetTemp->setObjectName(QString::fromUtf8("doubleSpinBoxSetTemp"));
        doubleSpinBoxSetTemp->setMaximum(100);
        doubleSpinBoxSetTemp->setSingleStep(0.1);

        verticalLayout_2->addWidget(doubleSpinBoxSetTemp);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        comboBoxFreq = new QComboBox(widget);
        comboBoxFreq->setObjectName(QString::fromUtf8("comboBoxFreq"));

        verticalLayout_2->addWidget(comboBoxFreq);

        checkBoxNominalTemp = new QCheckBox(widget);
        checkBoxNominalTemp->setObjectName(QString::fromUtf8("checkBoxNominalTemp"));

        verticalLayout_2->addWidget(checkBoxNominalTemp);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEditOffset = new QLineEdit(widget);
        lineEditOffset->setObjectName(QString::fromUtf8("lineEditOffset"));
        lineEditOffset->setEnabled(false);

        horizontalLayout_2->addWidget(lineEditOffset);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget1 = new QWidget(frame);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 30, 221, 25));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(widget1);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(widget1);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout->addWidget(stopButton);

        frame_2 = new QFrame(tab_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 520, 661, 51));
        frame_2->setFrameShape(QFrame::WinPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        frame_2->setMidLineWidth(1);
        layoutWidget5 = new QWidget(frame_2);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 0, 151, 43));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_12 = new QLabel(layoutWidget5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_6->addWidget(label_12);

        lineEditProgramState = new QLineEdit(layoutWidget5);
        lineEditProgramState->setObjectName(QString::fromUtf8("lineEditProgramState"));
        lineEditProgramState->setEnabled(false);

        verticalLayout_6->addWidget(lineEditProgramState);


        horizontalLayout_11->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_13 = new QLabel(layoutWidget5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_7->addWidget(label_13);

        timeEdit_current = new QTimeEdit(layoutWidget5);
        timeEdit_current->setObjectName(QString::fromUtf8("timeEdit_current"));
        timeEdit_current->setEnabled(false);

        verticalLayout_7->addWidget(timeEdit_current);


        horizontalLayout_11->addLayout(verticalLayout_7);

        exitButton = new QPushButton(tab_2);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(680, 520, 241, 51));
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 10, 661, 501));
        frame_3->setFrameShape(QFrame::WinPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(1);
        plot = new QCustomPlot(frame_3);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(10, 10, 641, 481));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "PRACA IN\305\273YNIERSKA", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Budowa prototypu urz\304\205dzenia do przeprowadzania procesu \305\202a\305\204cuchowej polimerazy DNA", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "POLITECHNIKA WARSZAWSKA", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Wydzia\305\202: Elektryczny", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Kierunek: Elektrotechnika", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Specjalno\305\233\304\207 : Automatyka i In\305\274ynieria Komputerowa", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Instytut Elektrotechniki Teoretycznej i System\303\263w ", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Informacyjno Pomiarowych", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Autor: Micha\305\202 Szczeci\305\204ski                                                    nr Albumu: 218900", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Regulator Options ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "KI", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "KP", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Temp 0      ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Temp1       ", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Temp2       ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Temp3       ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "ADC0", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "ADC1", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "ADC2", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "ADC3", 0, QApplication::UnicodeUTF8));
        groupBoxGraphSel->setTitle(QApplication::translate("MainWindow", "Graph Selection", 0, QApplication::UnicodeUTF8));
        checkBoxTemp0->setText(QApplication::translate("MainWindow", "Temp0", 0, QApplication::UnicodeUTF8));
        checkBoxTemp1->setText(QApplication::translate("MainWindow", "Temp1", 0, QApplication::UnicodeUTF8));
        checkBoxTemp2->setText(QApplication::translate("MainWindow", "Temp2", 0, QApplication::UnicodeUTF8));
        checkBoxTemp3->setText(QApplication::translate("MainWindow", "Temp3", 0, QApplication::UnicodeUTF8));
        checkBoxAvTemp->setText(QApplication::translate("MainWindow", "Av Temp", 0, QApplication::UnicodeUTF8));
        checkBoxHide->setText(QApplication::translate("MainWindow", "Hide", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Nominal Temperature", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Measurement Frequency", 0, QApplication::UnicodeUTF8));
        checkBoxNominalTemp->setText(QApplication::translate("MainWindow", "Show Nominal Temp", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Offset", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Connection", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Uptime", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
