#ifndef MATERIAL_H
#define MATERIAL_H

#include <QDialog>

namespace Ui {
class material;
}

class material : public QDialog
{
    Q_OBJECT

public:
    explicit material(QWidget *parent = nullptr);
    ~material();

private slots:
    void on_id_class_textChanged();

    void on_id_group_textChanged();

    void on_measure_textChanged();

    void on_pushButton_clicked();
    void onTextChanged();

private:
    Ui::material *ui;
};

#endif // MATERIAL_H
