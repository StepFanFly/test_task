#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "sqlconnectiondialog.h"
#include "adddialog.h"
#include "changedialog.h"
#include <QtWidgets>
#include <QtSql>
#include <QtSql/QSqlTableModel>
#include <QDate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool isConnected;

    QSqlError addConnection(const QString &dbName, const QString &host, const QString &user, const QString &passwd, const int port);
    QSqlError addConnection();
    void closeConnection();

private slots:
    void newRecord();
    void changeRecord();
    void deleteRecord();
    void on_action_triggered();
    void on_action_2_triggered();

    void on_action_4_triggered();

private:
    Ui::MainWindow *ui;
    QString dbName,host,user,password;
    int port;
    QSqlDatabase maindb;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
