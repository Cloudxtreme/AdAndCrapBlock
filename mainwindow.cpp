#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit,SIGNAL (triggered()), this, SLOT(close()));
    m_urllist << "http://adaway.org/hosts.txt"
              << "http://winhelp2002.mvps.org/hosts.txt"
              << "http://hosts-file.net/ad_servers.asp"
              << "http://pgl.yoyo.org/adservers/serverlist.php?hostformat=hosts&showintro=0&mimetype=plaintext"
              << "http://sysctl.org/cameleon/hosts"
              << "http://someonewhocares.org/hosts/hosts"
              << "http://www.malwaredomainlist.com/hostslist/hosts.txt"
              << "http://securemecca.com/Downloads/hosts.txt"
              << "http://www.hostsfile.org/Downloads/hosts.txt"
              << "http://adblock.gjtech.net/?format=hostfile"
              << "http://pastebay.net/pastebay.php?dl=1346107"
              << "http://sites.google.com/site/logroid/files/hosts.txt"
              << "https://veryhost.googlecode.com/files/windwos.txt";

    ui->label_2->setStyleSheet("QLabel { color : red; }");
    ui->label_2->setVisible(false);
    ui->progressBar_2->setVisible(false);

    m_downloader = new downloader(this);
    m_parserThread = new parserThread(this);
    m_processSimThread = new processsimthread(this);
    m_pathhelper = new pathhelper(this);
    m_pathhelper->getTmpDir(m_workingDir);

    connect(m_processSimThread, SIGNAL(processValueChanged(int)), this, SLOT(workingProcessBar(int)));
    connect(m_downloader, SIGNAL(downloadCompleted(bool)), this, SLOT(downloadFinish(bool)));
    connect(m_parserThread, SIGNAL(finished(QString)), this, SLOT(parserReady(QString)));
}

void MainWindow::parserReady(QString pathToHostsFile)
{
    ui->pushButton->setEnabled(true);
    ui->label_2->setStyleSheet("QLabel { color : green; }");
    ui->label_2->setText("Process finished!");
    ui->progressBar_2->setValue(0);
    ui->progressBar_2->setVisible(false);

    QProcess copyProcess;
    copyProcess.start("gksu \"mv " + pathToHostsFile + " /etc/hosts\"");
    while( copyProcess.waitForFinished());
    copyProcess.close();

    m_processSimThread->Stop = true;
}

void MainWindow::downloadFinish(bool success)
{
    m_lastfileindex++;

    if(!success){
        qDebug() << "download failed";
    }

     qDebug() << m_lastfileindex + " " + (m_urllist.length() -1);
    if (m_lastfileindex == (m_urllist.length() -1))
    {
        // finish
        qDebug() << "all files are downloaded!";

        // setup Parser Thread
        QString workingDirStr;
        m_pathhelper->getCompleteHostsFileTmpPath(m_workingDir,workingDirStr);
        m_parserThread->setSavePath(m_workingDir, workingDirStr);
        //start...
        m_parserThread->start();

    }
    else
    {
        downloadNextFile(m_lastfileindex);
    }
}


void MainWindow::workingProcessBar(int value)
{
    ui->progressBar_2->setValue(value);
}

void MainWindow::on_pushButton_clicked()
{
    m_processSimThread->start();
    ui->pushButton->setEnabled(false);
    ui->progressBar_2->setVisible(true);
    ui->label_2->setVisible(true);

    m_lastfileindex = 0;
    this->downloadNextFile(m_lastfileindex);
}


MainWindow::~MainWindow()
{
    delete ui;

    m_processSimThread->Stop = true;
    m_processSimThread->exit(0);
    m_parserThread->exit(0);
}

void MainWindow::downloadNextFile(int index)
{
    if (index <= (m_urllist.length() -1))
    {
        QString workingDirStr;
        m_pathhelper->getCompletePath(m_workingDir,workingDirStr);
        qDebug() << "working Dir: " + workingDirStr;

        QUrl freshURL(m_urllist[index]);
        m_downloader->Download(freshURL,workingDirStr);

       //workingDirStr = QString();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,
    tr("Backup your current hosts file"),
    QDir::homePath(),
    tr("*.*"));
    if( !filename.isNull() )
    {
        QFile::copy("/etc/hosts", filename);
    }

    filename = QString();
}

void MainWindow::on_pushButton_5_clicked()
{
    QString defaulthostsfile = "127.0.0.1 localhost";
    QFile file(m_workingDir.canonicalPath() + m_workingDir.separator() + "default");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "127.0.0.1 localhost";
    file.flush();
    file.close();

    QProcess copyProcess;
    copyProcess.start("gksu \"mv " + m_workingDir.canonicalPath() + m_workingDir.separator() + "default" + " /etc/hosts\"");
    while( copyProcess.waitForFinished());
    copyProcess.close();

    m_pathhelper->cleanTmpDir(m_workingDir);

    defaulthostsfile = QString();
}
