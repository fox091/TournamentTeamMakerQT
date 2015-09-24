#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerlist.h"
#include <QList>
#include <QMessageBox>

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

void MainWindow::on_txtSoloAdd_returnPressed()
{
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

void MainWindow::on_txtDuoAdd_returnPressed()
{
    ui->txtDuoAdd2->setFocus();
}

void MainWindow::on_txtDuoAdd2_returnPressed()
{
    addDuo();
}

void MainWindow::addDuo() {
    pList.AddDuo(ui->txtDuoAdd->text(), ui->txtDuoAdd2->text());
    ui->txtDuoAdd->clear();
    ui->txtDuoAdd2->clear();
    ui->txtDuoAdd->setFocus();
}

void MainWindow::on_btnBuildTeams_clicked() {
    buildTeams();
}
void MainWindow::on_txtBuildTeams_returnPressed()
{
    buildTeams();
}

void MainWindow::buildTeams() {
    int teamSize = 0;
    int teamCount = 1;
    bool ok;
    teamSize = ui->txtBuildTeams->text().toInt(&ok, 10);
    if (!ok) {
        QMessageBox msgBox;
        msgBox.setText("Could not read number. (Did you type something other than a number?)");
        msgBox.exec();
        return;
    }
    if (teamSize <= 0) {
        QMessageBox msgBox;
        msgBox.setText("Team size cannot be lower than 1.");
        msgBox.exec();
        return;
    }
    if (pList.getTotalPlayers() % teamSize != 0) {
        QMessageBox msgBox;
        msgBox.setText("There are not enough players to fill all teams.  Add more players.");
        msgBox.exec();
        return;
    }
    QMessageBox msgBox;
    msgBox.setText("There are nksdfjsdlkfjot enough players to fill all teams.  Add more players.");
    msgBox.exec();
    QList<Player> playerList = pList.BuildTeams(teamSize);
    if (playerList.length() == 0) {
        QMessageBox msgBox;
        msgBox.setText("There too many duos in order to create full even teams.  Add more solos.");
        msgBox.exec();
    }
    for (int i = 0; i < pList.getTotalPlayers();i++) {
        if (teamSize > 1) {
            QString asdf = "Team %1:";
            if (i == 0)
                ui->lwResults->addItem(asdf.arg(teamCount++));
            else if (i % teamSize == 0)
                ui->lwResults->addItem(asdf.arg(teamCount++));
        }
        ui->lwResults->addItem(playerList[i].getName());
    }
}
