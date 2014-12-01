#ifndef DRIVERLINUX_H
#define DRIVERLINUX_H

#include <QObject>


class QFile;

class Driver : public QObject
{
    Q_OBJECT
public:
    explicit Driver(QObject *parent = 0);
    ~Driver();


    unsigned short int PortInit(QString , unsigned long int); //konfiguracja portu
    void PortClose();
    unsigned short int Check(); //sprawdzenie po³¹czenia
    long int BytesAvailable(); //iloœæ bajtów do odczytu
    unsigned int SendVal(int *);
    void Flush();
public slots:
    unsigned long int ReadData(char *, long);
    unsigned long int WriteData(const char*, long int);

private:
#ifdef Q_WS_X11
    int port_file;
#endif
#ifdef Q_WS_WIN
    void *hCommDev;

#endif
    QFile *file;
    
};

#endif // DRIVERLINUX_H
