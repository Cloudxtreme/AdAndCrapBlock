#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "downloader.h"
#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QUuid>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QProcess>
#include "ui_mainwindow.h"
#include "processsimthread.h"
#include "parserthread.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void ProcessValueChanged(int);
    void DownloadFinish(QString, int);
    void ParserReady(QString,int);
    void Error(QString);
    void workingProcessBar(int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    downloader* cdown;
    QStringList blacklist;
    QString hostfileheader;
    QStringList whitelist;
    QString hostfile;
    int blacklistcounter;
    int whitelistcounter;
    parserThread* m_thread;
    bool error;
    processsimthread* processSimThread;
};



#endif // MAINWINDOW_H
