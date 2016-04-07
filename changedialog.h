#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H

#include <QDialog>

namespace Ui {
class changeDialog;
}

class changeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit changeDialog(QWidget *parent = 0);
    ~changeDialog();

private:
    Ui::changeDialog *ui;
};

#endif // CHANGEDIALOG_H
