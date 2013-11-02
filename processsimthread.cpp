#include "processsimthread.h"


processsimthread::processsimthread(QObject *parent) :
    QThread(parent)
{

}

processsimthread::~processsimthread()
{
    this->Stop = true;
}

void processsimthread::run()
{
    QMutex mutex;
    int counter = 0;
    this->Stop = false;
    while(!this->Stop)
    {
       mutex.lock();
       counter++;
       if (counter == 100) {
           counter = 0;
       }
       emit processValueChanged(counter);
       mutex.unlock();
       QThread::msleep(100);

    }
}
