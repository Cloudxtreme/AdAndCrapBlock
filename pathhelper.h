#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QDir>
#include <QUuid>

class pathhelper : public QObject
{
    Q_OBJECT
public:
    explicit pathhelper(QObject *parent = 0);
    void getTmpDir(QDir &dir);
    void getCompletePath(QDir, QString &path);
    void getCompleteHostsFileTmpPath(QDir, QString &path);
    void cleanTmpDir(QDir);
    void getConfigDir(QDir &dir);
private:
    void checkTmpDir(QDir &dir);
    void checkConfigDir(QDir &dir);
};

#endif // SYSTEM_H
