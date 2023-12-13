#include "BComboBox.h"

#include "../utils/Helper.h"
BComboBox::BComboBox(QWidget *parent, QString title) : QWidget(parent) {
  this->title = title;
  grid = new QGridLayout(this);
  setLayout(grid);
  combobox = new QComboBox(this);
  label = new QLabel(this);
}

void BComboBox::addItem(QString text) { combobox->addItem(text); }

void BComboBox::initUI() {
  label->setText(title);
  label->setAlignment(Qt::AlignVCenter);
  ds_label_align_left(label);
  label->setFont(font_subHeader());
  ds_wg_set_expanding_w(label);
  ds_wg_set_expanding_w(combobox);

  if (isTitleInLine) {
    grid->addWidget(label, 0, 0);
    grid->addWidget(combobox, 0, 1);
  } else {
    grid->addWidget(label, 0, 0, 1, 2);
    grid->addWidget(combobox, 1, 0, 1, 2);
  }
}

int BComboBox::selectedIndex() { return combobox->currentIndex(); }
