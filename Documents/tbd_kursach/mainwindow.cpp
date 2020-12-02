#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlDatabase"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto db = QSqlDatabase::addDatabase("QPSQL");
    db.setPort(5432);
    db.setHostName("localhost");
    db.setDatabaseName("Sklad");
    //db.setUserName(login1);
    //db.setPassword(password1);
    db.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    deaths_year = new deaths_by_year;
    deaths_year -> show();
}

void MainWindow::on_pushButton_2_clicked()
{
    deaths_reg = new deaths_by_reg;
    deaths_reg -> show();
}
