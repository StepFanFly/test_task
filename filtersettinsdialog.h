#ifndef FILTERSETTINSDIALOG_H
#define FILTERSETTINSDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class FilterSettinsDialog;
}

class FilterSettinsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterSettinsDialog(QWidget *parent = 0);
    ~FilterSettinsDialog();

    QDate dateFrom() const;
    QDate dateTo() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::FilterSettinsDialog *ui;
};

#endif // FILTERSETTINSDIALOG_H
