#ifndef QDATEEDITNULL_H
#define QDATEEDITNULL_H

#include <QDateEdit>

class QDateEditnull : public QDateEdit
{
    Q_OBJECT
    Q_PROPERTY(QDate nullDate READ nullDate WRITE setDate USER true)
public:
    QDateEditnull(const QDate& date, QWidget* parent);
    QDateEditnull(QWidget* parent);
    ~QDateEditnull();

    QDate nullDate() const;
signals:

public slots:
    void clear();
    void setDate(const QDate& date);
};

#endif // QDATEEDITNULL_H
