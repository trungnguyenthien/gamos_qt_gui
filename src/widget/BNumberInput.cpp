#include "BNumberInput.h"
#include <QtGui/QIntValidator>
#include <QtGui/QDoubleValidator>

BNumberInput::BNumberInput(QWidget *parent, const QString &labelText, const QString &hint) : BHStackWidget(parent)
{
    content = new QLineEdit(this);
    content->setFixedWidth(50);
    content->setPlaceholderText(hint);

    QLabel *label = new QLabel(this);
    label->setText(labelText);

    addSubWidget(content);
    addSubWidget(label);
}

void BNumberInput::turnOnIntValidator(int min, int max)
{
    content->setValidator(new QIntValidator(min, max, this));
}

void BNumberInput::turnOnDoubleValidator(int min, int max, int decimals)
{
    content->setValidator(new QDoubleValidator(min, max, decimals, this));
}