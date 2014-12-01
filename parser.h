#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QList>


class QTime;
class QStringList;

class Parser : public QObject //klasa odpowiedzialna za dzielenie otrzymanych danych
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = 0);
    unsigned int GetData(char *);
    //void Parse();
    void ReturnDataTable();
    QList<QStringList > ReturnAllData();
    QStringList ReturnRow();

private:
    char *buff; //tutaj trzymamy dane do parsowania
    QStringList *timeAndSensorTable;
    unsigned long int row;
    QTime *measureTime;
    QList<QStringList > *dataTable;

public slots:
    void Parse();
signals:
    void finished();

};

#endif // PARSER_H
