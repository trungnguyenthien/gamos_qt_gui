#include "BGroupNumberInput.h"

#include "BNumberInput.h"

void BGroupNumberInput::initUI(GroupNumberInputValue groupNumberInputValue) {
  this->groupNumberInputValue = groupNumberInputValue;
  int row = 0;
  for (NumberInputValue value : groupNumberInputValue.values) {
    BNumberInput *bNumberInput = new BNumberInput(this, value);
    this->grid->addWidget(bNumberInput, row, 0);
    row++;
  }
}

void BGroupNumberInput::removeAll() { grid_layout_clear(this->grid); }

GroupNumberInputValue BGroupNumberInput::values() {
  GroupNumberInputValue copy = this->groupNumberInputValue;
  vector<QWidget *> widgets = layout_getChildren(this->grid);
  int index = 0;
  for (QWidget *w : widgets) {
    BNumberInput *numberInput = dynamic_cast<BNumberInput *>(w);
    if (numberInput == nullptr) {
      continue;
    }
    copy.values[index].value = numberInput->content->text();
    index++;
  }
  return copy;
}
