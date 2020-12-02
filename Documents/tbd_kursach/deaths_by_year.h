#ifndef DEATHS_BY_YEAR_H
#define DEATHS_BY_YEAR_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class deaths_by_year;
}

class deaths_by_year : public QWidget
{
    Q_OBJECT

public:
    explicit deaths_by_year(QWidget *parent = nullptr);
    ~deaths_by_year();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deaths_by_year *ui;
    QSqlQueryModel *model;
};

#endif // DEATHS_BY_YEAR_H
