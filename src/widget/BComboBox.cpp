
#include "BComboBox.h"
BComboBox::BComboBox(QWidget *parent, string title) : BHStackWidget(this) {
  label = unique_ptr<QLabel>(new QLabel(this));
  label.get()->setText(title.data());
  addSubWidget(label.get(), 50, 20);

  combobox = unique_ptr<QComboBox>(new QComboBox(this));
  addSubWidget(combobox.get(), 0, 20);
}
