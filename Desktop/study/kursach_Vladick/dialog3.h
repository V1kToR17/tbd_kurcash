#ifndef DIALOG3_H
#define DIALOG3_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDialog>
#include <memory>
#include "ui_dialog3.h"

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog3 *ui;
    std::unique_ptr<QSqlQueryModel> model;
};

#endif // DIALOG3_H
