#include "changedialog.h"
#include "ui_changedialog.h"

changeDialog::changeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeDialog)
{
    ui->setupUi(this);
}

changeDialog::~changeDialog()
{
    delete ui;
}

QString changeDialog::name() const
{
    return ui->editName->text();
}

QString changeDialog::text() const
{
    return ui->editTaskText->toPlainText();
}

QString changeDialog::text_crt() const
{
    return ui->editTaskCrt->toPlainText();
}

QDate changeDialog::dateCreate() const
{
    return ui->editDateStart->date();
}

QDate changeDialog::dateDeadline() const
{
    return ui->editDateDeadline->date();
}

QDate changeDialog::dateFinished() const
{
    return ui->editDateFinished->nullDate();
}
void changeDialog::on_buttonBox_accepted()
{
    accept();
}

void changeDialog::on_buttonBox_rejected()
{
    reject();
}
