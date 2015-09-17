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
