#ifndef DEATHS_BY_REG_H
#define DEATHS_BY_REG_H

#include <QWidget>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class deaths_by_reg;
}

class deaths_by_reg : public QWidget
{
    Q_OBJECT

public:
    explicit deaths_by_reg(QWidget *parent = nullptr);
    ~deaths_by_reg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deaths_by_reg *ui;
    QSqlQueryModel *model;
};

#endif // DEATHS_BY_REG_H
