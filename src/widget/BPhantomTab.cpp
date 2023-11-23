#include "BPhantomTab.h"

#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

#include "BNumberInput.h"
#include "BPathInput.h"

BPhantomTab::BPhantomTab(QWidget *parent) : QHBoxLayout(parent) {
  left = new BVStackWidget(parent);
  right = new BVStackWidget(parent);

  // Render Left
  QLabel *lbl01 = new QLabel(parent);
  lbl01->setText("1) HELLO WORLD");
  left->addSubWidget(lbl01);

  BNumberInput *number1 = new BNumberInput(parent, "POS_X", "0.00");
  number1->turnOnIntValidator(10, 77);
  left->addSubWidget(number1);

  BPathInput *pathInput = new BPathInput(parent, "...");
  left->addSubWidget(pathInput);

  // Render Right
  QLabel *lbl02 = new QLabel(parent);
  lbl02->setText("1) HELLO WORLD");
  right->addSubWidget(lbl02);
  lbl02->setStyleSheet("background-color:#EAEAEA;");

  addWidget(left, 1);
  addWidget(right, 1);
}