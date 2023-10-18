#include "BVStackWidget.h"

BVStackWidget::BVStackWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(parent);
    setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

void BVStackWidget::addSubLayout(QLayout *layout)
{
    mainLayout->addLayout(layout);
}

void BVStackWidget::addSubWidget(QWidget *widget)
{
    mainLayout->addWidget(widget);
}