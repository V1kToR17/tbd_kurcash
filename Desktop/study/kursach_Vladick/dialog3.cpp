#include "dialog3.h"
#include "ui_dialog3.h"
#include <QMessageBox>
#include <QtSql>

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_pushButton_clicked()
{
    QString material = ui->material->text();

    model = std::make_unique<QSqlQueryModel>(this);
    model->setQuery("SELECT distinct providers.name AS Название, providers.inn AS ИНН, providers_address.index AS Индекс, providers_address.city AS Город, providers_address.street AS Улица, "
                    "providers_address.building AS Дом, banks.name AS Банк, providers.n_account AS Номер_счёта "
                    "FROM providers "
                    "RIGHT JOIN postavki ON providers.id_provider = postavki.id_provider "
                    "JOIN providers_address ON providers.id_address = providers_address.id_address "
                    "JOIN banks ON providers.id_bank = banks.id_bank "
                    "WHERE postavki.id_material = (SELECT materials.id_material FROM materials where materials.name = '" + material + "')");
    ui->providers->setModel(model.get());
}
