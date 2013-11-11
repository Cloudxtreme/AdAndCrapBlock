#include "parserthread.h"

parserThread::parserThread(QObject *parent) :
    QThread(parent)
{
    this->running = false;
}

parserThread::~parserThread()
{
    m_saveToFileName = QString();
    m_path = QDir();
}

void parserThread::setSavePath(QDir path, QString saveToFileName)
{
    m_saveToFileName = saveToFileName;
    m_path = path;
}

void parserThread::run()
{
    this->running = true;
    QMutex mutex;
    mutex.lock();

    QStringList txtFiles = m_path.entryList();
    QString editeddata;
    QStringList editeddatalist;
    QString line;
    QStringList splittlist;
    QString splittStr;
    QString subStr;
    QString IP;
    QString HostName;

    bool isNumber = false;

    int parts = 0;
    int value = 0;

    //the first is localhost
    editeddatalist << "127.0.0.1 localhost";

    for (int i =0; i < txtFiles.length(); i++)
    {
        qDebug() << m_path.canonicalPath() + m_path.separator() + txtFiles[i];
        QFile inputFile(m_path.canonicalPath() + m_path.separator() + txtFiles[i]);
        if (inputFile.open(QIODevice::ReadOnly))
        {
            QTextStream in(&inputFile);
            while ( !in.atEnd() )
            {
                IP = "";
                line = in.readLine();
                line = line.trimmed(); //trim whitespaces!

                // Checks if first char is a number
                subStr = ((line.constData())[0]).toAscii();
                value = subStr.toInt(&isNumber);
                if (isNumber)
                {
                    subStr = line.mid(0,5);
                    //ok it'S a IP
                    if (subStr.contains('.'))
                    {
                        splittlist = line.split(QRegExp("\\s"));
                        if (splittlist.length() > 1)
                        {
                            splittStr = splittlist[0];
                            //qDebug() << splittStr;
                            // save the rest of the String for Later!

                            //Jump over all Whitespaces
                            for (int x = 1; x < splittlist.length(); x++)
                            {
                                if (splittlist[x] != "")
                                {
                                    parts = x;
                                    break;
                                }
                            }
                            subStr = splittlist[parts].trimmed();
                            qDebug() << subStr;
                            parts = 0;


                            splittlist.clear();
                            splittlist = splittStr.split(".");
                            parts = splittlist.length();
                            //qDebug() << parts;
                            // IP Check
                            if (parts == 4)
                            {
                                // Build the clean IP String
                                IP = splittlist.join(".");
                                //qDebug() << IP;
                            }
                            splittlist.clear();

                            //cut out commants crap
                            value = subStr.indexOf("#");
                            if (value > 0)
                            {
                                subStr = subStr.mid(0, value - 1);
                                qDebug() << subStr;

                            }

                            splittlist = subStr.split(".");
                            parts = splittlist.length();
                            if (parts >= 2)
                            {
                                // OK! is a vailed HostName
                                HostName = subStr;
                                if (IP.length() != 0)
                                {
                                   // Yeah! all work is Done .. for this Line !!
                                   line = IP + " " + HostName;
                                   if (!editeddatalist.contains(line))
                                        editeddatalist << line;
                                }
                             }
                             splittlist.clear();

                        }
                    }
                }
            }
            in.flush();
        }
        inputFile.close();
    }
    editeddata = editeddatalist.join("\n");
    editeddatalist.clear();
    QByteArray data = editeddata.toUtf8();

    QFile file(m_saveToFileName);
    file.open( QIODevice::WriteOnly );
    file.write(data);
    file.flush();
    file.close();

    emit finished(m_saveToFileName);

    //Cleaning Memory!!
    data = QByteArray();
    editeddata = QString();
    editeddatalist = QStringList();
    txtFiles = QStringList();
    line  = QString();
    splittlist = QStringList();
    splittStr = QString();
    IP = QString();
    HostName = QString();
    subStr = QString();

    mutex.unlock();
    this->running = false;
}
