#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include <QtWidgets>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle(QObject::tr("Тестовое задание"));

    return a.exec();
}
