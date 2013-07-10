#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class downloader : public QObject
{
    Q_OBJECT
public:
    explicit downloader(QObject *parent = 0);
    ~downloader();
    void Download(QUrl urls, int filetype);

signals:
    void downloadProgressChanged(int);
    void errorNow(QString);
    void downloadCompleted(QString, int);

public slots:
    void downloadProgress ( qint64, qint64 );
    void error (QNetworkReply::NetworkError );
    void downloadFinish();

private:
    QNetworkAccessManager* m_NetworkManager;
    QNetworkReply* m_reply;

    //File Type 1 = Header File
    //File Type 2 = BlackList File
    //File Type 3 = WhiteList File
    int m_filetype;
};

#endif // DOWNLOADER_H
