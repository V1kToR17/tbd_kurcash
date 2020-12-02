#ifndef BANK_H
#define BANK_H

#include <QDialog>

namespace Ui {
class bank;
}

class bank : public QDialog
{
    Q_OBJECT

public:
    explicit bank(QWidget *parent = nullptr);
    ~bank();

private slots:
    void on_pushButton_clicked();

    void on_index_textChanged();

    void on_city_textChanged();

    void on_street_textChanged();

    void on_building_textChanged();
    void onTextChanged();

private:
    Ui::bank *ui;
};

#endif // BANK_H
