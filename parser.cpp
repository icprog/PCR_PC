#include "parser.h"
#include <iostream>
#include <QDebug>
#include <QStringList>
#include <QTime>

Parser::Parser(QObject *parent) :
    QObject(parent)
{
    timeAndSensorTable = new QStringList;
    measureTime = new QTime;
    measureTime->start();

    dataTable = new QList<QStringList >;
    row = 0;
}

unsigned int Parser::GetData(char * data) // dane z RSa
{
    if(sizeof(data) > 0)
    {
        buff = data;
        return sizeof(buff);
    }
}

void Parser::Parse() //dzieli dane
{

    if(sizeof(buff) > 0)
    {
    QString str = buff;
    QStringList list1 = str.split("\n");
    QStringList *strList;
    strList = new QStringList;
    QString strTime;
    unsigned long int time = measureTime->elapsed();
    QString tmp1 = list1[0];
    tmp1.replace(QRegExp("<\\w+>"),"");
    QString comp = "Sensors";
    if(tmp1.compare(comp) > 0)
    {
        strTime = strTime.setNum(time);
        strList->append(strTime);

        for (int i = 0; i < list1.size()-2; i++)
            {
               QString str1 = list1[i+1];
               str1.remove(QRegExp("<\\w+>"));
               strList->append(str1);
            }

        dataTable->append(*strList);
    }
    delete strList;
    }
    emit finished();
}

/*! Potem trzeba przerobic ta funckje zeby zwracala QList<QStringList> !! ta tablice w mainwindow bedzie sie trzymalo
*/

/*! Dodaj cos w wstylu funkcji append zeby zwracalo tylko QStringList to do glownej tablicy sie bedzie wklejalo tylko jeden wiersz
  */


void Parser::ReturnDataTable() //wyrzuca na konsole zawartosc dataTable
{
    if(dataTable->size() > 0)
    {
        for(int i = 0 ; i < dataTable->size();i++)
        {
            for(int n = 0; n < dataTable->at(i).size();n++)
                {
                    qDebug() <<"i: "<< i << "n: " << n <<dataTable->at(i).at(n);

                }
        }

    }
}

QList<QStringList> Parser::ReturnAllData() //do skopiowania danych z tablicy
{
    return *dataTable;
}

QStringList Parser::ReturnRow()
{
    //if(dataTable->size()>0)
        return dataTable->at(dataTable->size()-1);
    //else
}



