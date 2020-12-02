#include "provider.h"
#include "ui_provider.h"
#include "bank.h"
#include <QMessageBox>
#include <QtSql>
#include "global.h"

QString provider1;


provider::provider(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::provider)
{
    ui->setupUi(this);
    ui->name->setText(provider1);
}

provider::~provider()
{
    delete ui;
}

void provider::on_pushButton_clicked()
{
    QString inn = ui->inn->text();
    bank1 = ui->bankn->text();
    QString n_account = ui->n_account->text();
    QString index = ui->index->text();
    QString city = ui->city->text();
    QString street = ui->street->text();
    QString building = ui->building->text();

    QSqlQuery query;

    query.exec("select count(id_address) from providers_address "
               "where index = '" + index + "' and city = '" + city + "' and street = '" + street + "' and building = '" + building + "'");
    qDebug() << query.lastError().text();
    query.next();
    int address = query.value(0).toInt();

    //assert(query.next());
    if(address == 0){
        query.exec("insert into providers_address (index, city, street, building) values ('" + index + "', '" + city + "', '" + street + "', '" + building + "')");
    }

    query.exec("select count(distinct id_bank) from banks where name = '" + bank1 +"'");
    //assert(query.next());
    qDebug() << query.lastError().text();
    query.next();
    int cbank = query.value(0).toInt();
    qDebug() << query.lastError().text();

    if(cbank == 0){
        bank window2;
        window2.setModal(true);
        window2.exec();
        return void();
    }

    query.next();
    query.exec("insert into providers (name, inn, id_address, id_bank, n_account) "
               "values ('" + provider1 + "', '" + inn + "', "
                       "(select id_address from providers_address where index = '" + index + "' and city = '" + city + "' and street = '" + street + "' and building = '" + building + "'), "
                       "(select id_bank from banks where name = '" + bank1 + "'), "
                       "'" + n_account + "') ");
    qDebug() << query.lastError().text();
    //assert(query.next());
    this->close();
}

void provider::onTextChanged(){
    if(ui->index->text().isEmpty() || ui->city->text().isEmpty() || ui->street->text().isEmpty() || ui->building->text().isEmpty() ||
            ui->inn->text().isEmpty() || ui->bankn->text().isEmpty() || ui->n_account->text().isEmpty()){
        ui->pushButton->setEnabled(false);
    }else{
        ui->pushButton->setEnabled(true);
    }
}

void provider::on_inn_textChanged()
{
    provider::onTextChanged();
}

void provider::on_bankn_textChanged()
{
    provider::onTextChanged();
}

void provider::on_n_account_textChanged()
{
    provider::onTextChanged();
}

void provider::on_index_textChanged()
{
    provider::onTextChanged();
}

void provider::on_city_textChanged()
{
    provider::onTextChanged();
}

void provider::on_street_textChanged()
{
    provider::onTextChanged();
}

void provider::on_building_textChanged()
{
    provider::onTextChanged();
}
