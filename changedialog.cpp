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
