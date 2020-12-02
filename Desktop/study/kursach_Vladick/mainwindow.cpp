#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialog4.h"
#include "autorization.h"
#include "QMessageBox"

QString login2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MainWindow::pushButton_2_enabled();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushButton_2_enabled()
{
   QMessageBox::critical(this, "LOL", login2);
   //if(login2 != "warehouse") ui->pushButton_2->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()
{
    window1 = new Dialog1;
    window1->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    window2 = new Dialog2;
    window2->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    window3 = new Dialog3;
    window3->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    window4 = new Dialog4;
    window4->show();
}
