#include "downloader.h"

//Constructor
downloader::downloader(QObject *parent) :
    QObject(parent)
{
    m_NetworkManager = new QNetworkAccessManager( this );
}


//DeConstructor
downloader::~downloader()
{
    delete m_NetworkManager;
}

//Methods
void downloader::Download(QUrl url, int filetype)
{

    m_filetype = filetype;
    QNetworkRequest request;
    request.setUrl(url);

    m_reply = m_NetworkManager->get( request );

    connect( m_reply, SIGNAL(error(QNetworkReply::NetworkError)),
             this, SLOT(error(QNetworkReply::NetworkError)));
    connect( m_reply, SIGNAL(downloadProgress(qint64,qint64)),
             this, SLOT(downloadProgress(qint64,qint64)) );
    connect( m_reply, SIGNAL(finished()),
             this, SLOT(downloadFinish()));

}



//Slots
void downloader::downloadProgress ( qint64 bytesReceived, qint64 bytesTotal )
{
    int percent = 0;
    if (bytesReceived) {
        percent = (qint64)((bytesReceived * 100) / bytesTotal);
        if (percent < 0)
            percent = 0;

        qDebug() << percent;
    }
    emit downloadProgressChanged( percent );
}

void downloader::error (QNetworkReply::NetworkError code )
{
    //emit errorNow(m_reply->errorString());
    qDebug() << m_reply->errorString();
    emit downloadCompleted("", m_filetype);
}

void downloader::downloadFinish()
{
    QByteArray fileData;
    fileData = m_reply->readAll();
    QString datastring;
    datastring = (QString::fromUtf8(fileData));

    if (m_filetype == 1) {
        if (datastring.length() == 0) {
            emit errorNow("You have no Internet Connection?!"); // no Internet Connection
            return;
        }
    }
    emit downloadCompleted(datastring, m_filetype);
}


