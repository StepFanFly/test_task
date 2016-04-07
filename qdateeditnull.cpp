#include "qdateeditnull.h"

QDateEditnull::QDateEditnull(const QDate& date, QWidget* parent)
    : QDateEdit(date, parent)
{
    this->setSpecialValueText("Null");
    QDateEdit::setDate(this->minimumDate());
}

QDateEditnull::QDateEditnull(QWidget* parent)
    : QDateEdit(parent)
{
    this->setSpecialValueText("Null");
    QDateEdit::setDate(this->minimumDate());
}

QDateEditnull::~QDateEditnull()
{
}

void QDateEditnull::clear()
{
    this->setDate(this->minimumDate());
}

QDate QDateEditnull::nullDate() const
{
    if (date() == this->minimumDate())
        return QDate();
    return date();
}

void QDateEditnull::setDate(const QDate& date)
{
    if (date.isNull())
        QDateEdit::setDate(this->minimumDate());
    QDateEdit::setDate(date);
}
