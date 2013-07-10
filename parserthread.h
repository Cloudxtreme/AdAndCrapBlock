#ifndef PARSERTHREAD_H
#define PARSERTHREAD_H

#include <QThread>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QRegExp>
#include <QDebug>
#include <QMutex>
class parserThread : public QThread
{
    Q_OBJECT
public:
    explicit parserThread(QObject *parent = 0);
    ~parserThread();
    void run();
    bool Running;
    void SetStringToParse(QString,int);

signals:
    void parserfinished(QString,int);

public slots:

private:
    QString m_sourceString;
    int m_filetype;
};

#endif // PARSERTHREAD_H
