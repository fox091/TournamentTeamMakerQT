#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerlist.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSoloAdd_clicked() {
    addSolo();
}

void MainWindow::addSolo() {
    pList.AddSolo(ui->txtSoloAdd->text());
    ui->txtSoloAdd->clear();
    ui->txtSoloAdd->setFocus();
}

void MainWindow::on_btnDuoAdd_clicked() {
    addDuo();
}

void MainWindow::addDuo() {
    pList.AddDuo(ui->txtDuoAdd->text(), ui->txtDuoAdd2->text());
    ui->txtDuoAdd->clear();
    ui->txtDuoAdd2->clear();
    ui->txtDuoAdd->setFocus();
}

void MainWindow::on_btnBuildTeams_clicked() {

}

void MainWindow::buildTeams() {

}
