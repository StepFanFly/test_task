#include "filtersettinsdialog.h"
#include "ui_filtersettinsdialog.h"

FilterSettinsDialog::FilterSettinsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterSettinsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Настройки фильтра"));
}

FilterSettinsDialog::~FilterSettinsDialog()
{
    delete ui;
}

QDate FilterSettinsDialog::dateFrom() const
{
    return ui->dateEdit->date();
}

QDate FilterSettinsDialog::dateTo() const
{
    return ui->dateEdit_2->date();
}

void FilterSettinsDialog::on_buttonBox_accepted()
{
    accept();
}

void FilterSettinsDialog::on_buttonBox_rejected()
{
    reject();
}
