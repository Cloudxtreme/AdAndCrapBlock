#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QStringList>
#include <QFile>

class downloader : public QObject
{
    Q_OBJECT
public:
    explicit downloader(QObject *parent = 0);
    ~downloader();
    void Download(QUrl, QString);

signals:
    void downloadProgressChanged(int);
    void downloadCompleted(bool);

public slots:
    void downloadProgress ( qint64, qint64 );
    void error (QNetworkReply::NetworkError );
    void downloadFinish();

private:
    QNetworkAccessManager* m_NetworkManager;
    QNetworkReply* m_reply;
    QString m_saveToFileName;
};

#endif // DOWNLOADER_H
