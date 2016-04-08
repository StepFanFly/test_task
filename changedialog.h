#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QDate>

namespace Ui {
class changeDialog;
}

class changeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changeDialog(QWidget *parent = 0);
    ~changeDialog();

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
    Ui::changeDialog *ui;
};

#endif // CHANGEDIALOG_H
