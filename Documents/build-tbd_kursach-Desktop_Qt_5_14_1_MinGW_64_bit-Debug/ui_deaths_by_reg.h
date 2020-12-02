/********************************************************************************
** Form generated from reading UI file 'deaths_by_reg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEATHS_BY_REG_H
#define UI_DEATHS_BY_REG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deaths_by_reg
{
public:
    QPushButton *pushButton;
    QTableView *tableView;

    void setupUi(QWidget *deaths_by_reg)
    {
        if (deaths_by_reg->objectName().isEmpty())
            deaths_by_reg->setObjectName(QString::fromUtf8("deaths_by_reg"));
        deaths_by_reg->resize(400, 300);
        pushButton = new QPushButton(deaths_by_reg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 230, 75, 23));
        tableView = new QTableView(deaths_by_reg);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(60, 20, 256, 192));

        retranslateUi(deaths_by_reg);

        QMetaObject::connectSlotsByName(deaths_by_reg);
    } // setupUi

    void retranslateUi(QWidget *deaths_by_reg)
    {
        deaths_by_reg->setWindowTitle(QCoreApplication::translate("deaths_by_reg", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("deaths_by_reg", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deaths_by_reg: public Ui_deaths_by_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEATHS_BY_REG_H
