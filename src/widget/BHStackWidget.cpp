#include "BHStackWidget.h"

BHStackWidget::BHStackWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QHBoxLayout(parent);
    setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

void BHStackWidget::addSubLayout(QLayout *layout)
{
    mainLayout->addLayout(layout);
}

void BHStackWidget::addSubWidget(QWidget *widget)
{
    mainLayout->addWidget(widget);
}