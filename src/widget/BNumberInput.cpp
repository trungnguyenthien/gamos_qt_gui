#include "BNumberInput.h"

#include <QtGui/QDoubleValidator>
#include <QtGui/QIntValidator>

#include "../utils/Helper.h"

void BNumberInput::initUI(bool isTitleInLine, bool isNormalFont) {
  // this->content->setFixedWidth(50);
  this->content->setPlaceholderText(hint);
  this->turnOnDoubleValidator(0, 99999999, 4);

  QGridLayout *grid = new QGridLayout(this);
  grid->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  grid->setSpacing(5);
  // grid->setContentsMargins(0, 0, 0, 0);
  // grid->setMargin(0);
  setLayout(grid);

  if (isNormalFont) {
    this->label->setFont(font_default());
  } else {
    this->label->setFont(font_subHeader());
  }

  label->setAlignment(Qt::AlignVCenter);
  ds_label_align_left(label);
  ds_wg_set_expanding_w(label);
  ds_wg_set_expanding_w(content);

  if (isTitleInLine) {
    grid->addWidget(label, 0, 0);
    grid->addWidget(content, 0, 1);
  } else {
    grid->addWidget(label, 0, 0);
    grid->addWidget(content, 1, 0);
  }
}

BNumberInput::BNumberInput(QWidget *parent, const QString &labelText, const QString &hint)
    : QWidget(parent) {
  this->hint = hint;
  content = new QLineEdit(this);
  label = new QLabel(this);
  label->setText(labelText);
}

BNumberInput::BNumberInput(QWidget *parent, NumberInputValue inputValue) : QWidget(parent) {
  content = new QLineEdit(this);
  label = new QLabel(this);
  label->setText(inputValue.label);

  this->numberInputValue = inputValue;
  this->content->setText(inputValue.value);
}

void BNumberInput::turnOnIntValidator(int min, int max) {
  content->setValidator(new QIntValidator(min, max, this));
}

void BNumberInput::turnOnDoubleValidator(int min, int max, int decimals) {
  content->setValidator(new QDoubleValidator(min, max, decimals, this));
}