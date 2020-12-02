#include "material.h"
#include "ui_material.h"
#include <QMessageBox>
#include <QtSql>
#include "global.h"
QString material1;

material::material(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::material)
{
    ui->setupUi(this);
    ui->name->setText(material1);
}

material::~material()
{
    delete ui;
}

void material::on_pushButton_clicked()
{
    QString id_class = ui->id_class->text();
    QString id_group = ui->id_group->text();
    QString measure = ui->measure->text();

    QSqlQuery query;
    query.exec("insert into materials (name, id_class, id_group, measure) "
               "values ('" + material1 + "', '" + id_class + "', '" + id_group + "', '" + measure + "')");
    this->close();
}

void material::onTextChanged(){
    if(ui->id_class->text().isEmpty() || ui->id_group->text().isEmpty() || ui->measure->text().isEmpty()){
        ui->pushButton->setEnabled(false);
    }else{
        ui->pushButton->setEnabled(true);
    }
}

void material::on_id_class_textChanged()
{
    material::onTextChanged();
}

void material::on_id_group_textChanged()
{
    material::onTextChanged();
}

void material::on_measure_textChanged()
{
    material::onTextChanged();
}
