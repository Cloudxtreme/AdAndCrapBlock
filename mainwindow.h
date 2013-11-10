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
#include <QCheckBox>
#include "addurl.h"

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
    void urlAddedToList(QString);
    void workingProcessBar(int);
    void downloadFinish(bool);
    void parserReady(QString);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

private:
    void runCommand(QString);
    void readSourcesFile();
    void downloadNextFile(int);
    void storeSourcesFile();

    Ui::MainWindow *ui;
    QStringList m_urllist;
    parserThread* m_parserThread;
    downloader* m_downloader;
    processsimthread* m_processSimThread;
    addurl* m_addurldialog;
    pathhelper* m_pathhelper;
    QDir m_workingDir;
    QDir m_configDir;
    QString m_sourcesPath;
    QString m_origPath;
    int m_lastfileindex;
};

#endif // MAINWINDOW_H
