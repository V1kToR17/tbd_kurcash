#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include "provider.h"
#include "bank.h"
#include "material.h"



namespace Ui {
class Dialog2;
}

//extern QString provider1;

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private slots:
    void on_pushButton_clicked();
    void onTextChanged();

    void on_unit_price_textChanged();

    void on_provider_textChanged();

    void on_balance_textChanged();

    void on_id_doc_textChanged();

    void on_n_doc_textChanged();

    void on_material_textChanged();

    void on_c_material_textChanged();

    void on_received_textChanged();

private:
    Ui::Dialog2 *ui;
    provider *windowp;
};

#endif // DIALOG2_H
