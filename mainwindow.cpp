#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDebug>
#include "cmath"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    driver = new Driver();  // klasa realizujaca komunikacje
    parser = new Parser(); //  klasa realizuja parsowanie danych
    driver->PortInit("COM4",115200);

    if(driver->Check() == true)
    {
        ui->lineEditProgramState->setText("Connected");
    }
    else
    {
        ui->lineEditProgramState->setText("Connection Problems!");
        ui->startButton->setEnabled(true);
    }
    graphTimer = new QTimer();
    sendTimer = new QTimer();
    updateTimer = new QTimer();
    upTime = new QTime();

    updateTimer->start(1000);

    PlotConf(); //konfiguracja wykresu
    UiConfig(); //konfiguracja widgetów na ekranie glownym apliokacji

    connect(graphTimer,SIGNAL(timeout()),this,SLOT(PortRead()));
    connect(sendTimer,SIGNAL(timeout()),this,SLOT(SendTemp()));

    //Obliczenia temperatury
    a1 = (double)(15.0/316.0);
    b1 = 505.0/158.0;

    //jak odpala siê program to uruchamiamy timer
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpTime()));
    upTime->start();
}

MainWindow::~MainWindow()
{
    driver->PortClose();
    delete ui;
}

void MainWindow::on_exitButton_clicked() //Wyjscie z aplikacji
{
    driver->PortClose();
    qApp->exit();
}

void MainWindow::on_startButton_clicked()//Rozpoczenie komunikacji
{
    graphTimer->start(1); //co sekunde jest odczyt
    //zlapac czas aktualny
}

void MainWindow::on_stopButton_clicked() //Zatrzymanie komunikacji
{
    graphTimer->stop();
}

void MainWindow::on_checkBoxTemp0_stateChanged(int arg1) //Rysowanie Temp0
{
    if(ui->checkBoxTemp0->isChecked())
    {
        ui->plot->graph(0)->setVisible(true);
        ui->plot->graph(0)->addToLegend();
    }
    else
    {
        ui->plot->graph(0)->setVisible(false);
        ui->plot->graph(0)->removeFromLegend();
    }
}

void MainWindow::on_checkBoxTemp1_stateChanged(int arg1) //Rysowanie Temp1
{
    if(ui->checkBoxTemp1->isChecked())
    {
        ui->plot->graph(1)->setVisible(true);
        ui->plot->graph(1)->addToLegend();
    }
    else
    {
        ui->plot->graph(1)->setVisible(false);
        ui->plot->graph(1)->removeFromLegend();
    }
}

void MainWindow::on_checkBoxTemp2_stateChanged(int arg1) //Rysowanie Temp2
{

    if(ui->checkBoxTemp2->isChecked())
    {
        ui->plot->graph(2)->setVisible(true);
        ui->plot->graph(2)->addToLegend();
    }
    else
    {
        ui->plot->graph(2)->setVisible(false);
        ui->plot->graph(2)->removeFromLegend();
    }
}

void MainWindow::on_checkBoxTemp3_stateChanged(int arg1) //Rysowanie Temp3
{

    if(ui->checkBoxTemp3->isChecked())
    {
        ui->plot->graph(3)->setVisible(true);
        ui->plot->graph(3)->addToLegend();
    }
    else
    {
        ui->plot->graph(3)->setVisible(false);
        ui->plot->graph(3)->removeFromLegend();
    }
}

void MainWindow::on_comboBoxFreq_currentIndexChanged(int index) //Czestotliwosc rysowania
{
    switch(index)
    {
    case 0:
        graphTimer->setInterval(20);
        break;
    case 1:
        graphTimer->setInterval(200);
        break;
    case 2:
        graphTimer->setInterval(500);
        break;
    case 3:
        graphTimer->setInterval(1000);
        break;
    case 4:
        graphTimer->setInterval(10000);
        break;
    case -1:
        graphTimer->setInterval(20);
        break;
    default:
        break;
    }
    ui->startButton->setEnabled(true);
}

void MainWindow::on_checkBoxAvTemp_stateChanged(int arg1) //Temperatura srednia
{

    if(ui->checkBoxAvTemp->isChecked())
    {
        ui->plot->graph(4)->setVisible(true);
        ui->plot->graph(4)->addToLegend();
    }
    else
    {
        ui->plot->graph(4)->setVisible(false);
        ui->plot->graph(4)->removeFromLegend();
    }
}

void MainWindow::on_doubleSpinBoxSetTemp_valueChanged(double arg1) //Wysylanie tempratury zadanej
{
    graphTimer->stop();
    char znak[] = "t\r";

    if(driver->Check() == 1)
    {
        qDebug() << "Weszlo" << endl;
        driver->WriteData(znak,sizeof(znak));
        sendTimer->start(5);
    }
    else
    {
        qDebug() << "Problemy z polaczeniem " << endl;
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1) //Wyswietlanie temperatury zadanej
{
    if(ui->checkBoxNominalTemp->isChecked())
    {
        ui->plot->graph(5)->setVisible(true);
        ui->plot->graph(5)->addToLegend();
    }
    else
    {
        ui->plot->graph(5)->setVisible(false);
        ui->plot->graph(5)->removeFromLegend();
    }
}

void MainWindow::on_spinBoxKI_valueChanged(int arg1)
{
    graphTimer->stop();
    //wyslanie znaku c zeby wszedl do GetPID
    char znak[] = "c\r\n";
    driver->WriteData(znak,sizeof(znak));

    //tutaj trzeba zegarek i tak dalej odpalic
    int P_PID = ui->spinBoxKI->value();
    driver->SendVal(&P_PID);
}

void MainWindow::on_spinBoxKP_valueChanged(int arg1)
{
    //wyslanie znaku c zeby wszedl do GetPID
    char znak[] = "c\r\n";
    driver->WriteData(znak,sizeof(znak));

    int P_PID = ui->spinBoxKP->value();
    driver->SendVal(&P_PID);
}

void MainWindow::on_checkBoxNominalTemp_stateChanged(int arg1)
{
    if(ui->checkBoxNominalTemp->isChecked())
    {
        ui->plot->graph(5)->addToLegend();
    }
    else
    {
        ui->plot->graph(5)->removeFromLegend();
    }
}

void MainWindow::PortRead()
{

    char znak[] = "b\r";
    char *data;

    if(driver->Check() == 1)
    {
        driver->WriteData(znak,sizeof(znak));
        data = new char[driver->BytesAvailable()];

        if(driver->BytesAvailable() > 1)
        {
            //qDebug() << "Ilosc bitow przed: " << driver->BytesAvailable();
            driver->ReadData(data,driver->BytesAvailable());
            //qDebug() << "Ilosc bitow po: " << driver->BytesAvailable();
            parser->GetData(data);
            parser->Parse();

            QStringList check = parser->ReturnRow();
            if(check.size() == 5)
            {
                sensorArray.append(parser->ReturnRow());
            }
        }
    }

    AppendData();
    delete[] data;
}

void MainWindow::AppendData()
{
    if(sensorArray.size() >= 1 )
    {
      double i_y0,i_y1,i_y2,i_y3;
      i_y0 = sensorArray.back().at(1).toDouble();
      i_y1 = sensorArray.back().at(2).toDouble();
      i_y2 = sensorArray.back().at(3).toDouble();
      i_y3 = sensorArray.back().at(4).toDouble();

      //tutaj trzeba przekonwertowac wartoœci !


      QString ADC0,ADC1,ADC2,ADC3;
      ADC0.setNum(i_y0,'g',4);
      ADC1.setNum(i_y1,'g',4);
      ADC2.setNum(i_y2,'g',4);
      ADC3.setNum(i_y3,'g',4);

      ui->lineEditADC0->setText(ADC0);
      ui->lineEditADC1->setText(ADC1);
      ui->lineEditADC2->setText(ADC2);
      ui->lineEditADC3->setText(ADC3);

      i_y0 = a1 * i_y0 + b1;
      i_y1 = a1 * i_y1 + b1;
      i_y2 = a1 * i_y2 + b1;
      i_y3 = a1 * i_y3 + b1;


      QString temp0,temp1,temp2,temp3;
      temp0.setNum(i_y0,'g',4);
      temp1.setNum(i_y1,'g',4);
      temp2.setNum(i_y2,'g',4);
      temp3.setNum(i_y3,'g',4);

      ui->lineEditTemp0Samples->setText(temp0);
      ui->lineEditTemp1Samples->setText(temp1);
      ui->lineEditTemp2Samples->setText(temp2);
      ui->lineEditTemp3Samples->setText(temp3);


      x.append(sensorArray.back().at(0).toDouble()/1000);
      y0.append(i_y0);
      y1.append(i_y1);
      y2.append(i_y2);
      y3.append(i_y3);
      tempRef.append(ui->doubleSpinBoxSetTemp->value());
      tempAverage.append((i_y0+i_y1+i_y2+i_y3)/4);
    }

    Plot();
    ComputeOffset();
    //int myint = currentTime.elapsed();
}

void MainWindow::Plot()
{
    int range = 100;
    if(y0.size() > 0)
    {

        double now = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
        time.append(now);
        ui->plot->graph(0)->addData(now,y0.back());
        ui->plot->graph(0)->removeDataBefore(now-range);
        ui->plot->graph(1)->addData(now,y1.back());
        ui->plot->graph(1)->removeDataBefore(now-range);
        ui->plot->graph(2)->addData(now,y2.back());
        ui->plot->graph(2)->removeDataBefore(now-range);
        ui->plot->graph(3)->addData(now,y3.back());
        ui->plot->graph(3)->removeDataBefore(now-range);
        ui->plot->graph(4)->addData(now,tempAverage.back());
        ui->plot->graph(4)->removeDataBefore(now-range);

        ui->plot->graph(5)->addData(now,tempRef.back());
        ui->plot->graph(5)->removeDataBefore(now-range);

        if(ui->checkBoxNominalTemp->isChecked())
        {
            ui->plot->graph(5)->rescaleValueAxis();
        }
        else
            ui->plot->graph(0)->rescaleValueAxis();


        ui->plot->xAxis->setRange(now+0.25,25,Qt::AlignRight);
        //ui->plot->yAxis->setRange(0.0,100.0);
    }
    ui->plot->replot();
}

void MainWindow::ComputeOffset()
{
    if(tempRef.size() > 0 && tempAverage.size() >0)
    {
        double offsetVal = abs(tempRef.back()-tempAverage.back());
        QString str = QString::number(offsetVal);
        ui->lineEditOffset->setText(str);
    }
}

void MainWindow::SendTemp()
{
    double setTemp = ui->doubleSpinBoxSetTemp->value();
    int sendTemp;

    sendTemp = setTemp/a1 - b1/a1;

    QString temp;
    temp.setNum(sendTemp);
    QByteArray ba = temp.toLocal8Bit();
    ba.append("\r\n");

    const char *str = ba.data();

    driver->WriteData(str,sizeof(str));
    sendTimer->stop();
    graphTimer->start();
}

void MainWindow::UpTime()
{
    unsigned long msecs = upTime->elapsed();
    QTime time;
    time = time.addMSecs(msecs);
    ui->timeEdit_current->setTime(time);
}

void MainWindow::PlotConf()
{
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->graph(1)->setPen(QPen(Qt::green));
    ui->plot->graph(2)->setPen(QPen(Qt::red));
    ui->plot->graph(3)->setPen(QPen(Qt::cyan));
    ui->plot->graph(4)->setPen(QPen(Qt::darkMagenta));
    ui->plot->graph(5)->setPen(QPen(Qt::darkRed));

    ui->plot->graph(0)->setName("Temp0");
    ui->plot->graph(1)->setName("Temp1");
    ui->plot->graph(2)->setName("Temp2");
    ui->plot->graph(3)->setName("Temp3");
    ui->plot->graph(4)->setName("Average Temp");
    ui->plot->graph(5)->setName("Nominal Temperature");

    ui->plot->xAxis->setLabel("Time");
    ui->plot->yAxis->setLabel("Temp");
    ui->plot->graph(0)->setAntialiased(false);
    ui->plot->graph(1)->setAntialiased(false);
    ui->plot->graph(2)->setAntialiased(false);
    ui->plot->graph(3)->setAntialiased(false);
    ui->plot->graph(4)->setAntialiased(false);
    ui->plot->graph(5)->setAntialiased(false);
    ui->plot->graph(5)->setVisible(true); //domyslnie nie wyswietlamy temperatury zadanej

    ui->plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->plot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->plot->xAxis->setAutoTickStep(false);
    ui->plot->xAxis->setTickStep(2);
    ui->plot->setupFullAxesBox();

    connect(ui->plot->xAxis,SIGNAL(rangeChanged(QCPRange)),ui->plot->xAxis2,SLOT(setRange(QCPRange)));
    connect(ui->plot->yAxis,SIGNAL(rangeChanged(QCPRange)),ui->plot->yAxis2,SLOT(setRange(QCPRange)));

    ui->plot->legend->setVisible(true);
    ui->plot->legend->setPositionStyle(QCPLegend::psTopLeft);
    ui->plot->graph(5)->removeFromLegend();
}

void MainWindow::UiConfig()
{
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(true);

    ui->comboBoxFreq->addItem("20ms");
    ui->comboBoxFreq->addItem("100ms");
    ui->comboBoxFreq->addItem("500ms");
    ui->comboBoxFreq->addItem("1s");
    ui->comboBoxFreq->addItem("10s");

    ui->comboBoxFreq->setCurrentIndex(-1);
}


void MainWindow::on_checkBoxHide_stateChanged(int arg1) //chowanie legendy
{
    if(ui->checkBoxHide->isChecked())
    {
        ui->plot->legend->setVisible(true);
    }
    else
        ui->plot->legend->setVisible(false);
}
