#ifndef DIALOG4_H
#define DIALOG4_H

#include <QDialog>

namespace Ui {
class Dialog4;
}

class Dialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = nullptr);
    ~Dialog4();

private slots:
    void on_pushButton_clicked();
    void onTextChanged();

    void on_build_textChanged();

    void on_index_textChanged();

    void on_city_textChanged();

    void on_street_textChanged();

private:
    Ui::Dialog4 *ui;
};

#endif // DIALOG4_H
