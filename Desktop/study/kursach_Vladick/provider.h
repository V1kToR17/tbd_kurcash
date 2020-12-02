#ifndef PROVIDER_H
#define PROVIDER_H

#include <QDialog>
#include "bank.h"

namespace Ui {
class provider;
}



class provider : public QDialog
{
    Q_OBJECT

public:
    explicit provider(QWidget *parent = nullptr);
    ~provider();

private slots:
    void on_pushButton_clicked();

    void on_inn_textChanged();

    void on_bankn_textChanged();

    void on_n_account_textChanged();

    void on_index_textChanged();

    void on_city_textChanged();

    void on_street_textChanged();

    void on_building_textChanged();
    void onTextChanged();

private:
    Ui::provider *ui;
    bank *windowb;
};

#endif // PROVIDER_H
