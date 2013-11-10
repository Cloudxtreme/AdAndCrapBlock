#ifndef ADDURL_H
#define ADDURL_H

#include <QDialog>

namespace Ui {
class addurl;
}

class addurl : public QDialog
{
    Q_OBJECT
    
public:
    explicit addurl(QWidget *parent = 0);
    ~addurl();

signals:
    void urlAdded(QString);
    
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::addurl *ui;
};

#endif // ADDURL_H
