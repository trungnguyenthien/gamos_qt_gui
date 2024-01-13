#include "BNumberInput.h"

#include <QtGui/QDoubleValidator>
#include <QtGui/QIntValidator>

BNumberInput::BNumberInput(QWidget *parent, const QString &labelText, const QString &hint) : BHStackWidget(parent) {
  content = new QLineEdit(this);
  content->setFixedWidth(50);
  content->setPlaceholderText(hint);

  QLabel *label = new QLabel(this);
  label->setText(labelText);

  addSubWidget(content);
  addSubWidget(label);

  setStyleSheet("background-color:#EAEAEA;");
}

BNumberInput::BNumberInput(QWidget *parent, NumberInputValue inputValue) : BHStackWidget(parent) {
  content = new QLineEdit(this);
  content->setFixedWidth(50);
  // content->setPlaceholderText(hint);

  QLabel *label = new QLabel(this);
  label->setText(inputValue.label);

  addSubWidget(content);
  addSubWidget(label);

  setStyleSheet("background-color:#EAEAEA;");

  this->content->setText(inputValue.value);
  this->turnOnDoubleValidator(0, 99999999, 4);
}

void BNumberInput::turnOnIntValidator(int min, int max) { content->setValidator(new QIntValidator(min, max, this)); }

void BNumberInput::turnOnDoubleValidator(int min, int max, int decimals) {
  content->setValidator(new QDoubleValidator(min, max, decimals, this));
}