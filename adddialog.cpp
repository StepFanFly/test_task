#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
}

addDialog::~addDialog()
{
    delete ui;
}

QString addDialog::name() const
{
    return ui->editName->text();
}

QString addDialog::text() const
{
    return ui->editTaskText->toPlainText();
}

QString addDialog::text_crt() const
{
    return ui->editTaskCrt->toPlainText();
}

QDate addDialog::dateCreate() const
{
    return ui->editDateStart->date();
}

QDate addDialog::dateDeadline() const
{
    return ui->editDateDeadline->date();
}

QDate addDialog::dateFinished() const
{
    return ui->editDateFinished->nullDate();
}

void addDialog::on_buttonBox_accepted()
{
    accept();
}

void addDialog::on_buttonBox_rejected()
{
    reject();
}
