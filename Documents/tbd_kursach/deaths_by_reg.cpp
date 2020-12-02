#include "deaths_by_reg.h"
#include "ui_deaths_by_reg.h"

deaths_by_reg::deaths_by_reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deaths_by_reg)
{
    ui->setupUi(this);
}

deaths_by_reg::~deaths_by_reg()
{
    delete ui;
}

void deaths_by_reg::on_pushButton_clicked()
{
    model = new QSqlQueryModel(this);
    model->setQuery("select Year, Reg, sum(Drac0 + Drac1 + Drac5 + Drac10 + Drac15 + Drac20 + Drac25 + Drac30 + Drac35 + Drac40 + Drac45 + Drac50 + Drac55 + Drac60 + Drac65 + Drac70 + Drac75"
                    "+ Drac80 + Drac85) as deaths from dr where Cause > 0 and Group = 'T' and Reg != 1100  group by Year, Reg;");
    ui->tableView->setModel(model);
}
