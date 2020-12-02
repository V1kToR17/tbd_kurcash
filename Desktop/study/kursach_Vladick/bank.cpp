#include "bank.h"
#include "ui_bank.h"
#include <QMessageBox>
#include <QtSql>
#include "global.h"

QString bank1;

bank::bank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bank)
{
    ui->setupUi(this);
    ui->name->setText(bank1);
}

bank::~bank()
{
    delete ui;
}

void bank::on_pushButton_clicked()
{
    QString index = ui->index->text();
    QString city = ui->city->text();
    QString street = ui->street->text();
    QString building = ui->building->text();

    QSqlQuery query;

    query.exec("insert into banks (name, index, city, street, building) values ('" + bank1 + "', '" + index + "', '" + city + "', '" + street + "', '" + building + "')");
    qDebug() << query.lastError().text();
    query.next();
    this->close();
}

void bank::onTextChanged(){
    if(ui->index->text().isEmpty() || ui->city->text().isEmpty() || ui->street->text().isEmpty() || ui->building->text().isEmpty()){
        ui->pushButton->setEnabled(false);
    }else{
        ui->pushButton->setEnabled(true);
    }
}


void bank::on_index_textChanged()
{
    bank::onTextChanged();
}

void bank::on_city_textChanged()
{
    bank::onTextChanged();
}

void bank::on_street_textChanged()
{
    bank::onTextChanged();
}

void bank::on_building_textChanged()
{
    bank::onTextChanged();
}
