#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <Qtimer>
#include <QTime>
#include "driver.h"
#include "parser.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void PlotConf();
    void UiConfig();
    ~MainWindow();
    double a1;
    double b1;
    
private slots:

    void PortRead();
    void AppendData();
    void Plot();
    void ComputeOffset();
    void SendTemp();
    void UpTime();

    void on_exitButton_clicked();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_checkBoxTemp0_stateChanged(int arg1);
    void on_checkBoxTemp1_stateChanged(int arg1);
    void on_checkBoxTemp2_stateChanged(int arg1);
    void on_checkBoxTemp3_stateChanged(int arg1);
    void on_comboBoxFreq_currentIndexChanged(int index);
    void on_checkBoxAvTemp_stateChanged(int arg1);
    void on_doubleSpinBoxSetTemp_valueChanged(double arg1);
    void on_checkBox_stateChanged(int arg1);
    void on_spinBoxKI_valueChanged(int arg1);
    void on_spinBoxKP_valueChanged(int arg1);
    void on_checkBoxNominalTemp_stateChanged(int arg1);

    void on_checkBoxHide_stateChanged(int arg1);

signals:


private:
    Ui::MainWindow *ui;
    Driver *driver;

    QTimer *graphTimer;
    QTimer *sendTimer;
    QTime *upTime;
    QTimer *updateTimer;

    Parser *parser;

    QList<QStringList> sensorArray;

    QVector<double> x;
    QVector<double> y0;
    QVector<double> y1;
    QVector<double> y2;
    QVector<double> y3;
    QVector<double> tempRef;
    QVector<double> tempAverage;

    QVector<double> time;

    //QThread *driverThread;
};

#endif // MAINWINDOW_H
