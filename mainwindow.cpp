#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *addnewAction,*changeAction,*deleteAction;
    addnewAction = new QAction(QObject::tr("Добавить"),ui->tableView);
    changeAction = new QAction(QObject::tr("Изменить"),ui->tableView);
    deleteAction = new QAction(QObject::tr("Удалить"),ui->tableView);

    ui->tableView->addAction(addnewAction);
    ui->tableView->addAction(changeAction);
    ui->tableView->addAction(deleteAction);

    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);

    QObject::connect(addnewAction,SIGNAL(triggered()),this,SLOT(newRecord()));
    QObject::connect(changeAction,SIGNAL(triggered()),this,SLOT(changeRecord()));
    QObject::connect(deleteAction,SIGNAL(triggered()),this,SLOT(deleteRecord()));

    QObject::connect(ui->buttonNew,SIGNAL(clicked()),this,SLOT(newRecord()));
    QObject::connect(ui->buttonChange,SIGNAL(clicked()),this,SLOT(changeRecord()));
    QObject::connect(ui->buttonDelete,SIGNAL(clicked()),this,SLOT(deleteRecord()));

    isConnected=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSqlError MainWindow::addConnection(const QString &dbName, const QString &host, const QString &user, const QString &passwd, const int port)
{
    QSqlError err;
    maindb = QSqlDatabase::addDatabase("QPSQL", QString("test_task"));
    maindb.setDatabaseName(dbName);
    maindb.setHostName(host);
    maindb.setPort(port);
    if (!maindb.open(user, passwd)) {
        err = maindb.lastError();
        maindb = QSqlDatabase();
        QSqlDatabase::removeDatabase(QString("test_task"));
    }
    return err;
}

void MainWindow::on_action_triggered()
{
    sqlconnectiondialog dialog(this);
    if (dialog.exec() != QDialog::Accepted)
    {
        return;
    }

    QSqlError err=addConnection(dialog.databaseName(),dialog.hostName(),dialog.userName(),dialog.password(),dialog.port());
    if(err.type() != QSqlError::NoError){
        QMessageBox::warning(this, QObject::tr("Ошибка доступ к базе данных"), QObject::tr("Ошибка при попытке получить доступ к базе данных: ")+err.text());
    }
    model = new QSqlTableModel(this, maindb);
    model->setTable("test_table");
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(7, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    model->select();
    ui->tableView->show();
}

void MainWindow::on_action_2_triggered()
{
    maindb.close();
    maindb.removeDatabase(QString("test_task"));
    delete(model);
}

void MainWindow::newRecord()
{
    addDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted)
    {
        return;
    }

    QDate dateCreate,dateDeadline,dateFinished;
    QString name,text,textCrt;
    dateCreate=dialog.dateCreate();
    dateDeadline=dialog.dateDeadline();
    dateFinished=dialog.dateFinished();
    name=dialog.name();
    text=dialog.text();
    textCrt=dialog.text_crt();

    QSqlQuery query(maindb);
    query.prepare("INSERT into test_table (date_created, task, task_crt, date_deadline, executor, date_closed) "
                  "VALUES (:date_created, :task, :task_crt, :date_deadline, :executor, :date_closed)");
    query.bindValue(":date_created",dateCreate);
    query.bindValue(":task",text);
    query.bindValue(":task_crt",textCrt);
    query.bindValue(":date_deadline",dateDeadline);
    query.bindValue(":executor",name);
    query.bindValue(":date_closed",dateFinished);
    query.exec();

}

void MainWindow::changeRecord()
{
    QMessageBox::warning(this, tr("SMTHING CHAGED!"), tr("RUN FOREST RUN"));
}

void MainWindow::deleteRecord()
{
    QMessageBox::warning(this, tr("SMTHING DELETED!"), tr("YOU KILLED THEM"));
}

void MainWindow::on_action_4_triggered()
{
    if(maindb.isOpen())
    {
        maindb.close();
        maindb.removeDatabase(QString("test_task"));
    }
    this->close();
}
