#include "dialog4.h"
#include "ui_dialog4.h"
#include <QMessageBox>
#include <QtSql>

Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);
}

Dialog4::~Dialog4()
{
    delete ui;
}

void Dialog4::onTextChanged(){
    if(ui->index->text().isEmpty() || ui->city->text().isEmpty() || ui->street->text().isEmpty() || ui->build->text().isEmpty()){
        ui->pushButton->setEnabled(false);
    }else{
        ui->pushButton->setEnabled(true);
    }
}

void Dialog4::on_pushButton_clicked()
{
    QString index = ui->index->text();
    QString city = ui->city->text();
    QString street = ui->street->text();
    QString build = ui->build->text();

    QSqlQuery query;
    query.exec("SELECT count(distinct providers.id_provider) AS Количество_поставщиков FROM providers "
               "WHERE providers.id_bank = "
               "(SELECT banks.id_bank From banks WHERE (index = '" + index + "' AND city = '" + city + "' AND street = '" + street + "' AND building = '" + build + "'));");
    assert(query.next());
    QString jija = query.value(0).toString();
    ui->count->setText(jija);

}

void Dialog4::on_build_textChanged()
{
    Dialog4::onTextChanged();
}

void Dialog4::on_index_textChanged()
{
    Dialog4::onTextChanged();
}

void Dialog4::on_city_textChanged()
{
    Dialog4::onTextChanged();
}

void Dialog4::on_street_textChanged()
{
    Dialog4::onTextChanged();
}
