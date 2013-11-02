#ifndef PARSERTHREAD_H
#define PARSERTHREAD_H

#include <QThread>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QRegExp>
#include <QDebug>
#include <QMutex>
#include <QDir>
#include <QByteArray>

class parserThread : public QThread
{
    Q_OBJECT
public:
    explicit parserThread(QObject *parent = 0);
    ~parserThread();
    void run();
    bool running;
    void setSavePath(QDir, QString);

signals:
    void finished(QString);

private:
    QDir m_path;
    QString m_saveToFileName;
};
#endif // PARSERTHREAD_H



