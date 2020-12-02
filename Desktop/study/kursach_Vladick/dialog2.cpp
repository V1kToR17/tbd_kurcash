#include "dialog2.h"
#include "ui_dialog2.h"
#include <QMessageBox>
#include <QtSql>
#include "provider.h"
#include "bank.h"
#include "material.h"
#include "global.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::onTextChanged(){
    if(ui->provider->text().isEmpty() || ui->balance->text().isEmpty() || ui->c_material->text().isEmpty() || ui->id_doc->text().isEmpty() ||
            ui->n_doc->text().isEmpty() || ui->material->text().isEmpty() || ui->received->text().isEmpty() || ui->unit_price->text().isEmpty()){
        ui->pushButton->setEnabled(false);
    }else{
        ui->pushButton->setEnabled(true);
    }
}

void Dialog2::on_pushButton_clicked()
{
    provider1 = ui->provider->text();
    QString balance = ui->balance->text();
    QString c_material = ui->c_material->text();
    QString id_doc = ui->id_doc->text();
    QString n_doc = ui->n_doc->text();
    material1 = ui->material->text();
    QString received = ui->received->text();
    QString unit_price = ui->unit_price->text();

    QSqlQuery query;

    query.exec("select count(distinct id_provider) from providers where name = '" + provider1 +"'");
    qDebug() << query.lastError().text();
    query.next();
    int cproviders = query.value(0).toInt();
    if (cproviders == 0){
        provider window;
        window.setModal(true);
        window.exec();
        return void();
    }

    query.exec("select count (id_material) from materials where name = '" + material1 +"'");
    qDebug() << query.lastError().text();
    query.next();
    int cmat = query.value(0).toInt();
    if (cmat == 0){
        material window3;
        window3.setModal(true);
        window3.exec();
        return void();
    }

    query.exec("insert into postavki (date, id_provider, balance, id_doc, n_doc, id_material, count_material, received_material, price_unit) "
               "values (now()::date, "
                       "(select id_provider from providers where name = '" + provider1 + "') "
                       ", '" + balance + "', " + id_doc + ", '" + n_doc + "', "
                       "(select id_material from materials where name = '" + material1 + "') "
                       ", " + c_material + ", " + received + ", " + unit_price + ")");
    //assert(query.next());
    QMessageBox::information(this, "Сообщение", "Информация успешно добавлена");
    this->close();
}


void Dialog2::on_unit_price_textChanged()
{
    Dialog2::onTextChanged();
}

void Dialog2::on_provider_textChanged()
{
    Dialog2::onTextChanged();
}

void Dialog2::on_balance_textChanged()
{
    Dialog2::onTextChanged();
}

void Dialog2::on_id_doc_textChanged()
{
    Dialog2::onTextChanged();
}

void Dialog2::on_n_doc_textChanged()
{
    Dialog2::onTextChanged();
}

void Dialog2::on_material_textChanged()
{
    Dialog2::onTextChanged();
}

void Dialog2::on_c_material_textChanged()
{
    Dialog2::onTextChanged();
}

void Dialog2::on_received_textChanged()
{
    Dialog2::onTextChanged();
}
