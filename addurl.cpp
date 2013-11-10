#include "addurl.h"
#include "ui_addurl.h"

addurl::addurl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addurl)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus(Qt::OtherFocusReason);
}

addurl::~addurl()
{
    delete ui;
}

//add button
void addurl::on_pushButton_2_clicked()
{
    this->urlAdded(ui->lineEdit->text());
    this->close();
}

//cancel button
void addurl::on_pushButton_clicked()
{
    this->close();
}
