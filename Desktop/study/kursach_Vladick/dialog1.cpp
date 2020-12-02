#include "dialog1.h"
#include "ui_dialog1.h"
#include <QMessageBox>
#include <QtSql>

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()
{
    QString name = ui->name1->text();

    QSqlQuery query;
    QRegExp re("\\d*");
    if (re.exactMatch(name)){
        query.exec("SELECT count(distinct id_provider) AS Количество_поставщиков FROM postavki WHERE id_material = " + name);
        assert(query.next());
        QString jija = query.value(0).toString();
        ui->count->setText(jija);
    } else {
        if(!query.exec("SELECT count(distinct id_provider) AS Количество_поставщиков "
                       "FROM postavki "
                       "JOIN materials ON postavki.id_material = materials.id_material " //right
                       "WHERE materials.name = '" + name + "';"))
            qDebug() << query.lastError().text();
        assert(query.next());
        QString jija = query.value(0).toString();
        ui->count->setText(jija);
    }
}

void Dialog1::on_name1_textChanged()
{
    if(ui->name1->text().isEmpty()){
        ui->pushButton->setEnabled(false);
    }else{
        ui->pushButton->setEnabled(true);
    }
}
