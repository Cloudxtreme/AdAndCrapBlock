#ifndef PROCESSSIMTHREAD_H
#define PROCESSSIMTHREAD_H

#include <QThread>
#include <QMutex>

class processsimthread : public QThread
{
    Q_OBJECT
public:
    explicit processsimthread(QObject *parent = 0);
    ~processsimthread();
    void run();
    bool Stop;

signals:
    void ProcessValueChanged(int);
};

#endif // PROCESSSIMTHREAD_H
