/********************************************************************************
** Form generated from reading UI file 'deaths_by_year.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEATHS_BY_YEAR_H
#define UI_DEATHS_BY_YEAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deaths_by_year
{
public:
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QWidget *deaths_by_year)
    {
        if (deaths_by_year->objectName().isEmpty())
            deaths_by_year->setObjectName(QString::fromUtf8("deaths_by_year"));
        deaths_by_year->resize(525, 405);
        tableView = new QTableView(deaths_by_year);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(110, 30, 281, 221));
        pushButton = new QPushButton(deaths_by_year);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 280, 81, 21));

        retranslateUi(deaths_by_year);

        QMetaObject::connectSlotsByName(deaths_by_year);
    } // setupUi

    void retranslateUi(QWidget *deaths_by_year)
    {
        deaths_by_year->setWindowTitle(QCoreApplication::translate("deaths_by_year", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("deaths_by_year", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deaths_by_year: public Ui_deaths_by_year {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEATHS_BY_YEAR_H
