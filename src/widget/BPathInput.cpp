#include "BPathInput.h"

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

BPathInput::BPathInput(QWidget *parent, const QString &hint)
    : BHStackWidget(parent) {
  lineEdit = new QLineEdit(this);
  lineEdit->setPlaceholderText(hint);
  lineEdit->setAlignment(Qt::AlignRight);
  lineEdit->setReadOnly(true);
  addSubWidget(lineEdit);

  QPushButton *button = new QPushButton("Select", parent);
  button->setFixedWidth(50);
  addSubWidget(button);

  setStyleSheet("background-color:#EAEAEA;");
}

QString BPathInput::getPath() { return *(this->path); }

void BPathInput::setPath(QString &path2) { this->path = &path2; }
