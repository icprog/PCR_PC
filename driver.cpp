#include <QDebug>
#include <QFile>
#include <QtGlobal>

#include "driver.h"
#include "unistd.h"
#include "errno.h"
#include "fcntl.h"
#include <iostream>

#ifdef Q_WS_X11
    #include <sys/ioctl.h>
    #include "termios.h"
#endif

#ifdef Q_WS_WIN
    #include "windows.h"
#endif

Driver::Driver(QObject *parent) :
    QObject(parent)
{
   file = new QFile;
}

Driver::~Driver()
{
    file->close();
    delete file;
}

unsigned short Driver::PortInit(QString name, unsigned long int Baud) //otwieranie pliku odpowiedzialnego za port szeregowy
{
#ifdef Q_WS_X11
    port_file = open(name, O_RDWR | O_NOCTTY | O_NDELAY);
#endif

#ifdef Q_WS_WIN
    const wchar_t *portNameArray = (const wchar_t*)name.utf16();
    hCommDev = CreateFile(portNameArray,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
#endif

#ifdef Q_WS_X11
    if(port_file < 0) // b³¹d otwarcia portu
    {
        qDebug() << "Nie mozna otworzyc portu, port_file = " << port_file;
        return 0;
    }    
    else //konfiguracja portu
    {
        file->open(port_file,QIODevice::ReadWrite|QIODevice::Unbuffered);
        struct termios options; //utworzenie struktury konfiguracyjnej portu com

        tcgetattr(port_file,&options);

        //ustawienie predkosci wysy³ania

        //tutaj zeby odczytywac predkosc z Baud trzeba by zrobic jakiegos cesa...

        cfsetispeed(&options,B115200);
        cfsetospeed(&options,B115200);

        //ustawienie ramki danych
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8;
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;

        options.c_cflag &= ~CRTSCTS;
        options.c_iflag &= ~(IXON|IXOFF|IXANY);

        options.c_cc[VTIME] = 1; //w milisekundach

        options.c_cflag|=CREAD|CLOCAL;
        options.c_lflag&=(~(ICANON|ECHO|ECHOE|ECHOK|ECHONL|ISIG));
        options.c_iflag&=(~(INPCK|IGNPAR|PARMRK|ISTRIP|ICRNL|IXANY));
        options.c_oflag&=(~OPOST);
        options.c_cc[VMIN]=1;

        options.c_cc[VINTR] = _POSIX_VDISABLE;
        options.c_cc[VQUIT] = _POSIX_VDISABLE;
        options.c_cc[VSTART] = _POSIX_VDISABLE;
        options.c_cc[VSTOP] = _POSIX_VDISABLE;
        options.c_cc[VSUSP] = _POSIX_VDISABLE;

        fcntl(port_file,F_SETFL,FNDELAY);
        tcsetattr(port_file,TCSANOW,&options); //natychmiastowe zaakceptowanie ustawien
    }
#endif
#ifdef Q_WS_WIN
    DCB dcb = {0}; //struktura z konfiguracja
    GetCommState(hCommDev,&dcb); //przekopiowanie wartoœci do tej struktury

    if(hCommDev != INVALID_HANDLE_VALUE)
    {
        dcb.DCBlength = sizeof(dcb);
        if(!GetCommState(hCommDev,&dcb))
            return false;
        dcb.BaudRate = Baud;
        dcb.Parity = NOPARITY;
        dcb.StopBits = ONESTOPBIT;
        dcb.ByteSize = 8;

        dcb.fParity = FALSE;
        dcb.fDtrControl = DTR_CONTROL_DISABLE;
        dcb.fRtsControl = RTS_CONTROL_DISABLE;

        dcb.fOutxCtsFlow = FALSE;
        dcb.fOutxDsrFlow = FALSE;
        dcb.fDsrSensitivity = FALSE;
        dcb.fAbortOnError = FALSE;
        dcb.fAbortOnError = FALSE;
        dcb.fOutX = FALSE;
        dcb.fInX = FALSE;
        dcb.fErrorChar = FALSE;
        dcb.fNull = FALSE;

        if(!SetCommState(hCommDev,&dcb))
            return false;
        //if(!SetupComm())
    }
    SetCommState(hCommDev,&dcb);
#endif
    return 1;
}

unsigned short Driver::Check() //sprawdza czy port szeregowy jest otwarty
{
#ifdef Q_WS_X11
    if(port_file <= 0 )
    {
        qDebug()<< "Port szeregowy zamkniety" << port_file;
        return 0;
    }
    else
    {
        qDebug() << "Port szeregowy otwarty" << port_file;
        return 1;
    }
#endif
#ifdef Q_WS_WIN
    if(hCommDev == INVALID_HANDLE_VALUE)
    {
        return 0;
    }
    else
    {
        return 1;
    }
#endif
}

void Driver::PortClose() //zamykanie portu szeregowego
{
#ifdef Q_WS_X11
        file->close();
        close(port_file);
        //qDebug() << "Port zamkniety";
#endif
#ifdef Q_WS_WIN
        CloseHandle(hCommDev);
#endif
}

unsigned long Driver::WriteData(const char *data,long int maxSize) //wysylanie danych
{
#ifdef Q_WS_X11
    long bytes;
    bytes = file->write(data,maxSize);
    file->flush();
    return bytes;
#endif
#ifdef Q_WS_WIN
    DWORD bytesWritten = 0;
    bool state;
    state = WriteFile(hCommDev,(void *)data,(DWORD) maxSize,&bytesWritten,NULL);
    if(state == true)
    {
        return bytesWritten;
    }
    else
    {
        return -1;
    }
#endif

}

unsigned long Driver::ReadData(char *data,long maxSize) //odczyt danych
{
#ifdef Q_WS_X11
    int bytes;
    bytes = file->read(data,maxSize);
    return bytes;
#endif
#ifdef Q_WS_WIN
    DWORD bytesRead =0;
    bool state;
    state = ReadFile(hCommDev,(void *)data,(DWORD)maxSize,&bytesRead,NULL);

    return bytesRead;
#endif

}

void Driver::Flush() //czyszczenie bufora
{
#ifdef Q_WS_X11
    file->flush();
#endif
#ifdef Q_WS_WIN
    FlushFileBuffers(hCommDev);
#endif
}

long Driver::BytesAvailable() //ilosc bajtow do odebrania z bufora
{
#ifdef Q_WS_X11
    int nbytes;
    if(ioctl(file->handle(),FIONREAD,&nbytes)<0)
        nbytes = 0;
    return (long int)nbytes;
#endif
#ifdef Q_WS_WIN
    DWORD erros;
    COMSTAT status;
    if(ClearCommError(hCommDev,&erros,&status))
    {
        return status.cbInQue;
    }
    else
        return -1;
#endif
}

unsigned int Driver::SendVal(int *val_to_send)
{
#ifdef Q_WS_X11
    QByteArray *array = new QByteArray;
    array->setNum(*val_to_send);
    file->write(*array);
    delete array;
    return 0;
#endif
#ifdef Q_WS_WIN
    QByteArray *array = new QByteArray;
    array->setNum(*val_to_send);
    int maxSize = sizeof(array);
    DWORD bytesWritten = 0;
    bool state;
    state = WriteFile(hCommDev,(void *)array,(DWORD) maxSize,&bytesWritten,NULL);
    return 0;
#endif
}
