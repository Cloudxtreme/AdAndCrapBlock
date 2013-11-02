#include "pathhelper.h"

pathhelper::pathhelper(QObject *parent) :
    QObject(parent)
{
}

void pathhelper::getTmpDir(QDir &dir)
{
    dir = QDir::tempPath();
    this->checkTmpDir(dir);
}

void pathhelper::checkTmpDir(QDir &dir)
{
    bool exist = dir.exists("aacblock");
    //check subdir
    if (!exist)
    {
         dir.mkdir("aacblock");
         dir.cd("aacblock");
    }
    else
    {
        //cleanup
        dir.cd("aacblock");
        this->cleanTmpDir(dir);
    }
}

void pathhelper::cleanTmpDir(QDir dir)
{
    dir.setNameFilters(QStringList() << "*");
    dir.setFilter(QDir::Files);
    foreach(QString dirFile, dir.entryList())
    {
       dir.remove(dirFile);
    }
}

void pathhelper::getCompletePath(QDir dir, QString &path)
{
    path  = dir.canonicalPath() + dir.separator() +  QString(QUuid::createUuid().toString()).append(".txt");
}

void pathhelper::getCompleteHostsFileTmpPath(QDir dir, QString &path)
{
    path  = dir.canonicalPath() + dir.separator() +  "hosts";
}
