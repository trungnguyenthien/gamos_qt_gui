#include "BComboBox.h"

#include "../utils/Helper.h"
BComboBox::BComboBox(QWidget *parent, string title) : BVStackWidget(parent) {
  label = unique_ptr<QLabel>(new QLabel(this));
  label.get()->setText(title.data());
  label.get()->setAlignment(Qt::AlignVCenter);
  ds_label_align_left(label.get());
  label.get()->setFont(font_subHeader());
  ds_wg_set_expanding_w(label.get());
  addSubWidget(label.get());

  combobox = unique_ptr<QComboBox>(new QComboBox(this));
  ds_wg_set_expanding_w(combobox.get());
  addSubWidget(combobox.get());
}
