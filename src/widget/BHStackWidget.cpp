#include "BHStackWidget.h"

BHStackWidget::BHStackWidget(QWidget *parent) : QWidget(parent) {
  mainLayout = new QHBoxLayout(parent);
  setLayout(mainLayout);
  mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

  mainLayout->setSpacing(5);
  mainLayout->setContentsMargins(0, 0, 0, 0);
  mainLayout->setMargin(0);
}

void BHStackWidget::addSubLayout(QLayout *layout) {
  mainLayout->addLayout(layout);
}

QHBoxLayout *BHStackWidget::getLayout() { return this->mainLayout; }

void BHStackWidget::addSubWidget(QWidget *widget) {
  mainLayout->addWidget(widget);
}

void BHStackWidget::addSubWidget(QWidget *widget, int width, int fixedHeight) {
  widget->setFixedHeight(fixedHeight);

  if (width < 0) {
    QSizePolicy policy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    widget->setSizePolicy(policy);
  }

  if (width == 0) {
    QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    widget->setSizePolicy(policy);
  }

  if (width > 0) {
    QSizePolicy policy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    widget->setFixedWidth(width);
    widget->setSizePolicy(policy);
  }

  mainLayout->addWidget(widget);
}