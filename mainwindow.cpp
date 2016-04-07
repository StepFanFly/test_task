#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSql>

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

void MainWindow::on_action_triggered()
{
    sqlconnectiondialog dialog(this);
    if (dialog.exec() != QDialog::Accepted)
    {

        return;
    }

}
