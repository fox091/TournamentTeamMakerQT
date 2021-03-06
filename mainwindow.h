#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playerlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnSoloAdd_clicked();

    void on_btnDuoAdd_clicked();

    void on_btnBuildTeams_clicked();

    void on_txtSoloAdd_returnPressed();

    void on_txtDuoAdd_returnPressed();

    void on_txtDuoAdd2_returnPressed();

    void on_txtBuildTeams_returnPressed();

private:
    Ui::MainWindow *ui;
    PlayerList pList;
    void addSolo();
    void addDuo();
    void buildTeams();
};

#endif // MAINWINDOW_H
