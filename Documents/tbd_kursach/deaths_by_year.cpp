#include "deaths_by_year.h"
#include "ui_deaths_by_year.h"

deaths_by_year::deaths_by_year(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deaths_by_year)
{
    ui->setupUi(this);
}

deaths_by_year::~deaths_by_year()
{
    delete ui;
}

void deaths_by_year::on_pushButton_clicked()
{
    model = new QSqlQueryModel(this);
    model->setQuery("select Year, sum(Drac0 + Drac1 + Drac5 + Drac10 + Drac15 + Drac20 + Drac25 + Drac30 + Drac35 + Drac40 + Drac45 + Drac50 + Drac55 + Drac60 + Drac65 + Drac70 + Drac75"
                    "+ Drac80 + Drac85) as deaths from dr where Cause > 0 and Group = 'T' and Reg != 1100  group by Year;");
    ui->tableView->setModel(model);
}
