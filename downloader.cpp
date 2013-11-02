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
    m_saveToFileName = QString();
}

//Methods
void downloader::Download(QUrl url, QString saveToFileName)
{
    QNetworkRequest request;
    request.setUrl(url);

    m_reply = m_NetworkManager->get( request );
    m_saveToFileName = saveToFileName;
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
    qDebug() << m_reply->errorString();
    emit downloadCompleted(false);
}

void downloader::downloadFinish()
{
    qDebug() << m_saveToFileName;
    QByteArray fileData;
    fileData = m_reply->readAll();

    QFile file(m_saveToFileName);
    file.open( QIODevice::WriteOnly );
    file.write( fileData );
    file.flush();
    file.close();

    m_reply->deleteLater();
    m_reply = NULL;

    emit downloadCompleted(true);
}
