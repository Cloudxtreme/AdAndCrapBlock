#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit,SIGNAL (triggered()), this, SLOT(close()));

    ui->label_2->setStyleSheet("QLabel { color : red; }");
    ui->label_2->setVisible(false);
    ui->progressBar_2->setVisible(false);

    m_downloader = new downloader(this);
    m_parserThread = new parserThread(this);
    m_processSimThread = new processsimthread(this);
    m_pathhelper = new pathhelper(this);

    m_pathhelper->getTmpDir(m_workingDir);
    m_pathhelper->getConfigDir(m_configDir);

    m_sourcesPath = m_configDir.canonicalPath() + m_configDir.separator() + "sources";
    m_origPath = m_configDir.canonicalPath() + m_configDir.separator() + "orig";

    QFile file(m_sourcesPath);
    if (!file.exists())
    {
        //create Sources File
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream( &file );
            stream << "http://adaway.org/hosts.txt,1" << endl;
            stream << "http://winhelp2002.mvps.org/hosts.txt,1" << endl;
            stream << "http://hosts-file.net/ad_servers.asp,1" << endl;
            stream << "http://pgl.yoyo.org/adservers/serverlist.php?hostformat=hosts&showintro=0&mimetype=plaintext,1" << endl;
            stream << "http://sysctl.org/cameleon/hosts,1" << endl;
            stream << "http://someonewhocares.org/hosts/hosts,1" << endl;
            stream << "http://www.malwaredomainlist.com/hostslist/hosts.txt,1" << endl;
            stream << "http://securemecca.com/Downloads/hosts.txt,1" << endl;
            stream << "http://www.hostsfile.org/Downloads/hosts.txt,1" << endl;
            stream << "http://adblock.gjtech.net/?format=hostfile,1" << endl;
            stream << "http://pastebay.net/pastebay.php?dl=1346107,0" << endl;
            stream << "http://sites.google.com/site/logroid/files/hosts.txt,1" << endl;
            stream << "https://veryhost.googlecode.com/files/windwos.txt,1" << endl;
        }
        file.flush();
        file.close();

        //create Original List .. for restoring old data
        this->runCommand("cp " + m_sourcesPath + " " + m_origPath);
    }
    this->readSourcesFile();

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

    this->runCommand("gksu \"mv " + pathToHostsFile + " /etc/hosts\"");
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
    this->storeSourcesFile();
    m_origPath = QString();
    m_sourcesPath = QString();
    m_processSimThread->Stop = true;
    m_processSimThread->exit(0);
    m_parserThread->exit(0);

    delete ui;
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

//Backup your current hosts file [Backup]
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

//default File Button [Backup]
void MainWindow::on_pushButton_5_clicked()
{
    QString defaulthostsfile = "127.0.0.1 localhost";
    QFile file(m_workingDir.canonicalPath() + m_workingDir.separator() + "default");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "127.0.0.1 localhost";
    file.flush();
    file.close();

    this->runCommand("gksu \"mv " + m_workingDir.canonicalPath() + m_workingDir.separator() + "default" + " /etc/hosts\"");

    m_pathhelper->cleanTmpDir(m_workingDir);

    defaulthostsfile = QString();
}

// delete item Button
void MainWindow::on_pushButton_3_clicked()
{
    QString text = ui->listWidget->currentItem()->text();

    if (ui->listWidget->currentItem()->isSelected())
    {
        text  += ",1";
    }
    else
    {
         text +=  ",0";
    }

    QStringList templist;

    QFile ufile(m_sourcesPath);
    if (ufile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&ufile);
        while ( !in.atEnd() )
        {
            templist << in.readLine();
        }
    }
    ufile.flush();
    ufile.close();

    templist.removeAll(text);

    QFile fOut(m_sourcesPath);
      if (fOut.open(QFile::WriteOnly | QFile::Text))
      {
        QTextStream s(&fOut);
        for (int i = 0; i < templist.size(); ++i)
            s << templist[i] << '\n';
      }
      fOut.flush();
      fOut.close();

    QListWidgetItem* item = ui->listWidget->currentItem();
    delete item;

    templist = QStringList();
}

//reset sources list from orig file
void MainWindow::on_pushButton_6_clicked()
{
    this->runCommand("cp " + m_origPath + " " + m_sourcesPath);
    this->readSourcesFile();
}


void MainWindow::readSourcesFile()
{
    m_urllist.clear();
    ui->listWidget->clear();
    QStringList splittlist;
    QString line;
    QFile ufile(m_sourcesPath);
    if (ufile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&ufile);
        while ( !in.atEnd() )
        {
            line = in.readLine();
            splittlist = line.split(",");
            if (splittlist.length() == 2)
            {
                QListWidgetItem *item = new QListWidgetItem(splittlist[0]);
                item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                if (splittlist[1] == "1")
                {
                    item->setCheckState(Qt::Checked);
                }
                else
                {
                    item->setCheckState(Qt::Unchecked);
                }
                ui->listWidget->addItem(item);
                m_urllist << splittlist[0];
            }
        }
    }
    ufile.flush();
    ufile.close();
    line = QString();
    splittlist = QStringList();
}

void MainWindow::runCommand(QString command)
{
    QProcess copyProcess;
    copyProcess.start(command);
    while( copyProcess.waitForFinished());
    copyProcess.close();
}

void MainWindow::storeSourcesFile()
{
    QStringList templist;
    QString url;
    int count = ui->listWidget->count();
    for(int index = 0;
        index < count;
        index++)
    {
        QListWidgetItem * item = ui->listWidget->item(index);
        url = item->text();
        if (item->checkState() == Qt::Checked)
        {
            url += ",1";
        }
        else
        {
            url += ",0";
        }
        templist << url;

    }
    QFile fOut(m_sourcesPath);
      if (fOut.open(QFile::WriteOnly | QFile::Text))
      {
        QTextStream s(&fOut);
        for (int i = 0; i < templist.size(); ++i)
            s << templist[i] << '\n';
      }
      fOut.flush();
      fOut.close();

      templist = QStringList();
      url = QString();
}

//add url Button
void MainWindow::on_pushButton_2_clicked()
{
    m_addurldialog = new addurl(this);
    connect(m_addurldialog, SIGNAL(urlAdded(QString)), this, SLOT(urlAddedToList(QString)));
    m_addurldialog->show();
    m_addurldialog->raise();
    m_addurldialog->activateWindow();
}

void MainWindow::urlAddedToList(QString url)
{
    QFile file(m_sourcesPath);
    if(file.open(QFile::Append | QFile::Text))
    {
       file.seek(file.size());
       QTextStream out(&file);
       out << url << ",1" <<  '\n';
       file.flush();
       file.close();
    }
    this->readSourcesFile();
}
