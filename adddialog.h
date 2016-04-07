#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = 0);
    ~addDialog();

    QString name() const;
    QString text() const;
    QString text_crt() const;
    QDate dateCreate() const;
    QDate dateDeadline() const;
    QDate dateFinished() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addDialog *ui;
};

#endif // ADDDIALOG_H
