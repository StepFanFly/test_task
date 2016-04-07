#ifndef SQLCONNECTIONDIALOG_H
#define SQLCONNECTIONDIALOG_H

#include <QDialog>


namespace Ui {
class sqlconnectiondialog;
}

class sqlconnectiondialog : public QDialog
{
    Q_OBJECT

public:
    explicit sqlconnectiondialog(QWidget *parent = 0);
    ~sqlconnectiondialog();

    QString databaseName() const;
    QString userName() const;
    QString password() const;
    QString hostName() const;
    int port() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::sqlconnectiondialog *ui;
};

#endif // SQLCONNECTIONDIALOG_H
