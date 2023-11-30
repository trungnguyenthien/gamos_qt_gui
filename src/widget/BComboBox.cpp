#include "BComboBox.h"

#include "../utils/Helper.h"
BComboBox::BComboBox(QWidget *parent, string title) : BHStackWidget(parent) {
  label = unique_ptr<QLabel>(new QLabel(this));
  label.get()->setText(title.data());
  label.get()->setAlignment(Qt::AlignVCenter);
  ds_label_align_left(label.get());
  addSubWidget(label.get(), 120, 30);

  combobox = unique_ptr<QComboBox>(new QComboBox(this));
  addSubWidget(combobox.get(), 0, 30);
}
