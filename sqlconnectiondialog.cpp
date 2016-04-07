#include "sqlconnectiondialog.h"
#include "ui_sqlconnectiondialog.h"

sqlconnectiondialog::sqlconnectiondialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sqlconnectiondialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("Новое соединение"));
}

sqlconnectiondialog::~sqlconnectiondialog()
{
    delete ui;
}

QString sqlconnectiondialog::databaseName() const
{
    return ui->editNameDB->text();
}

QString sqlconnectiondialog::userName() const
{
    return ui->editNameUser->text();
}

QString sqlconnectiondialog::password() const
{
    return ui->editPassword->text();
}

QString sqlconnectiondialog::hostName() const
{
    return ui->editHost->text();
}

int sqlconnectiondialog::port() const
{
    return ui->editPort->value();
}

void sqlconnectiondialog::on_buttonBox_accepted()
{
    accept();
}

void sqlconnectiondialog::on_buttonBox_rejected()
{
    reject();
}
