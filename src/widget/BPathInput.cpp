#include "BPathInput.h"

#include <QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

#include "../utils/Helper.h"

BPathInput::BPathInput(QWidget *parent, QString title, const QString hint)
    : BHStackWidget(parent) {
  lineEdit = new QLineEdit(this);
  lineEdit->setPlaceholderText(hint);
  lineEdit->setAlignment(Qt::AlignLeft);
  lineEdit->setReadOnly(true);
  addSubWidget(titleLabel(title, this));
  addSubWidget(lineEdit);

  QPushButton *button = new QPushButton("Select", parent);
  button->setFixedWidth(50);
  addSubWidget(button);

  setStyleSheet("background-color:#EAEAEA;");

  connectButtonClicked(button, [this]() {
    QString newPath = openDirectory(this, this->getPath(), "~");
    this->setPath(newPath);
    this->onSelected(newPath);
  });
}

QString BPathInput::getPath() { return (this->path); }

void BPathInput::setPath(QString path2) {
  this->path = path2;
  lineEdit->setText(path2);
}
