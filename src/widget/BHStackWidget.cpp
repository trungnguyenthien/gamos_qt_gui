#include "BHStackWidget.h"

BHStackWidget::BHStackWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QHBoxLayout(parent);
    setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setMargin(0);
}

void BHStackWidget::addSubLayout(QLayout *layout)
{
    mainLayout->addLayout(layout);
}

QHBoxLayout *BHStackWidget::getLayout()
{
    return this->mainLayout;
}

void BHStackWidget::addSubWidget(QWidget *widget)
{
    mainLayout->addWidget(widget);
}