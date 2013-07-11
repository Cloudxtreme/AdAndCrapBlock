#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit,SIGNAL (triggered()), this, SLOT(close()));

    blacklist << "http://winhelp2002.mvps.org/hosts.txt"
              << "http://pgl.yoyo.org/adservers/serverlist.php?hostformat=hosts&showintro=0&mimetype=plaintext"
              << "http://someonewhocares.org/hosts/hosts"
              << "http://www.malwaredomainlist.com/hostslist/hosts.txt"
              << "http://securemecca.com/Downloads/hosts.txt"
              << "http://www.hostsfile.org/Downloads/hosts.txt"
              << "http://adblock.gjtech.net/?format=hostfile"
              << "http://sites.google.com/site/logroid/files/hosts.txt"
              << "http://hosts-file.net/ad_servers.asp"
              << "http://sysctl.org/cameleon/hosts";

    hostfileheader= "http://hastebin.com/raw/pamiyalafa";

    whitelist << "https://smarthosts.googlecode.com/svn/trunk/hosts"
              << "https://veryhost.googlecode.com/files/windwos.txt"
              << "http://hostsx.googlecode.com/svn/trunk/hosts";

    ui->label_2->setStyleSheet("QLabel { color : red; }");
    ui->label_2->setVisible(false);
    ui->progressBar_2->setVisible(false);

    cdown = new downloader(this);
    m_thread = new parserThread(this);
    processSimThread = new processsimthread(this);

    error = false;
    isSaved = false;

    connect(processSimThread, SIGNAL(ProcessValueChanged(int)), this, SLOT(workingProcessBar(int)));
    connect(m_thread, SIGNAL(parserfinished(QString,int)), this, SLOT(ParserReady(QString,int)));
    connect(cdown, SIGNAL(downloadProgressChanged(int)), this, SLOT(ProcessValueChanged(int)));
    connect(cdown, SIGNAL(downloadCompleted(QString,int)), this, SLOT(DownloadFinish(QString,int)));
    connect(cdown, SIGNAL(errorNow(QString)),this, SLOT(Error(QString)));

}

MainWindow::~MainWindow()
{
    processSimThread->Stop = true;
    m_thread->exit(0);
    delete ui;
}

void MainWindow::Error(QString errormessage)
{
    error = true;
    QMessageBox::critical(
        this,
        tr("error occurred!"),
        errormessage );

    ui->pushButton->setEnabled(true);
    ui->plainTextEdit->setPlainText("");
}


void MainWindow::workingProcessBar(int value)
{
    ui->progressBar_2->setValue(value);
}


void MainWindow::ParserReady(QString result, int type)
{
    if (!error)
    {
        hostfile += result;
        switch(type) {
            case 1:
            case 2:
            if (blacklistcounter < blacklist.length())
            {
                //Start the Blacklist
                ui->plainTextEdit->appendPlainText("downloading and analysis the File \n" + blacklist[blacklistcounter] + "\n");
                cdown->Download(blacklist[blacklistcounter], 2);
            }
            else
            {
                // Start the Whitelist
                ui->plainTextEdit->appendPlainText("downloading and analysis the File \n" + whitelist[whitelistcounter] + "\n");
                cdown->Download(whitelist[whitelistcounter], 3);
                whitelistcounter++;
            }
            blacklistcounter ++;
            break;

            case 3:
                if (whitelistcounter < whitelist.length()) {
                    ui->plainTextEdit->appendPlainText("downloading and analysis the File \n" + whitelist[whitelistcounter] + "\n");
                    cdown->Download(whitelist[whitelistcounter], 3);
                }
                else {
                    //Finish Processing Lists
                    if (!isSaved)
                    {
                        QString filename =  QDir::tempPath () +
                                            (QString)QDir::separator() +
                                            QUuid::createUuid().toString() + ".txt";
                        qDebug() << filename;
                        QFile file(filename);
                        file.open(QIODevice::WriteOnly | QIODevice::Text);
                        QTextStream out(&file);
                        out << hostfile << endl;
                        file.close();

                        processSimThread->Stop = true;

                        QProcess copyProcess;
                        copyProcess.start("gksu \"mv " + filename + " /etc/hosts\"");
                        while( copyProcess.waitForFinished());
                        copyProcess.close();
                    }
                    isSaved = true;

                    ui->pushButton->setEnabled(true);
                    ui->label_2->setStyleSheet("QLabel { color : green; }");
                    ui->label_2->setText("Process finished!");
                    ui->progressBar_2->setValue(0);
                    ui->progressBar_2->setVisible(false);


                }
                whitelistcounter++;
                break;

            default:
                break;
        }
        ui->progressBar->setValue(100);
    }
}

void MainWindow::ProcessValueChanged(int Percent)
{
    ui->progressBar->setValue(Percent);
}

void MainWindow::DownloadFinish(QString FileData,int type)
{
    if (!error) {
        if (!m_thread->Running) {
            m_thread->SetStringToParse(FileData, type);
            m_thread->start();
        }
        ui->progressBar->setValue(0);
    }
    qDebug() << "error = " << error;
}


void MainWindow::on_pushButton_clicked()
{
    error = false;
    isSaved = false;
    blacklistcounter = 0;
    whitelistcounter = 0;
    ui->pushButton->setEnabled(false);
    ui->progressBar_2->setVisible(true);
    ui->label_2->setVisible(true);
    ui->plainTextEdit->setPlainText("downloading and analysis the File \n" + hostfileheader + "\n");
    cdown->Download(hostfileheader, 1);
    processSimThread->start();
}
