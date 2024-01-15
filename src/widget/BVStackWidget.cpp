#include "BVStackWidget.h"

BVStackWidget::BVStackWidget(QWidget *parent) : QWidget(parent) {
  mainLayout = new QVBoxLayout(parent);
  setLayout(mainLayout);
  mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  mainLayout->setSpacing(5);
  mainLayout->setContentsMargins(0, 0, 0, 0);
  mainLayout->setMargin(0);
}

void BVStackWidget::addSubLayout(QLayout *layout) { mainLayout->addLayout(layout); }

QVBoxLayout *BVStackWidget::getLayout() { return this->mainLayout; }

void BVStackWidget::addSubWidget(QWidget *widget) { mainLayout->addWidget(widget); }