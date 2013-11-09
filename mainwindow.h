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
#include "parserthread.h"
#include "pathhelper.h"
#include "processsimthread.h"
#include <QUrl>
#include <QFileDialog>

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
    void workingProcessBar(int);
    void downloadFinish(bool);
    void parserReady(QString);

private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QStringList m_urllist;

    parserThread* m_parserThread;
    downloader* m_downloader;
    processsimthread* m_processSimThread;
    pathhelper* m_pathhelper;

    QDir m_workingDir;
    void downloadNextFile(int index);
    int m_lastfileindex;

};

#endif // MAINWINDOW_H
