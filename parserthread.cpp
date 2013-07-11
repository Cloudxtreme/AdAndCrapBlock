#include "parserthread.h"


parserThread::parserThread(QObject *parent) :
    QThread(parent)
{
    this->Running = false;
}

parserThread::~parserThread()
{
    m_sourceString = QString(); // string set to null
}

void parserThread::run()
{
    this->Running = true;
    QMutex mutex;
    mutex.lock();

    if (!m_sourceString.isNull())
    {

        QTextStream in (&m_sourceString);

        QString editeddata;
        QStringList editeddatalist;
        QString line;
        QStringList splittlist;
        QString splittStr;

        int parts = 0;

        switch(m_filetype)
        {
        case 1:  //File Type 1 = Header File
            editeddata = m_sourceString + "\n";
            break;

        case 2:  //File Type 2 = BlackList File
            while ( !in.atEnd() )
            {
                line = in.readLine();
                if (line.startsWith("127.0.0.1"))
                {
                    if (!editeddatalist.contains(line))
                        editeddatalist << line;
                }
            }
            in.flush();
            editeddata = editeddatalist.join("\n");
            editeddatalist.clear();
            break;

        case 3:  //File Type 3 = WhiteList File
            while ( !in.atEnd() )
            {
                line = in.readLine();
                //IP Check
                splittlist = line.split(QRegExp("\\s"));
                if (splittlist.length() > 0)
                {
                    splittStr = splittlist[0];
                    qDebug() << splittStr;
                    splittlist.clear();
                    splittlist = splittStr.split(".");
                    parts = splittlist.length();
                    qDebug() << parts;
                    if (parts == 4)
                    {
                        if (!editeddatalist.contains(line))
                            editeddatalist << line;
                    }
                }
            }
            in.flush();
            editeddata = editeddatalist.join("\n");
            editeddatalist.clear();
            break;

        }
        //push out!
        emit parserfinished(editeddata, m_filetype);

        //Cleaning Memory!!
        editeddata = QString();
        editeddatalist = QStringList();
        line  = QString();
        splittlist = QStringList();
        splittStr = QString();
    }
    mutex.unlock();
    this->Running = false;
}

void parserThread::SetStringToParse(QString StringToParse, int type)
{
    m_sourceString = StringToParse;
    m_filetype = type;
}
