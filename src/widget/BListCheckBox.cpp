#include "BListCheckBox.h"

#include <QButtonGroup>
#include <cmath>

#include "../utils/Helper.h"
BListCheckBox::BListCheckBox(QWidget *parent) : QWidget(parent) {}

vector<int> BListCheckBox::selectedIndices() {
  vector<int> output;
  if (isSingleChoice) {
    // QButtonGroup *buttonGroup = new QButtonGroup(this);
    int index = 0;
    for (auto item : vectorRadioButton) {  // QRadioButton
      if (item->isChecked()) {
        output.push_back(index);
      }
      index++;
    }
  } else {
    int index = 0;
    for (auto item : vectorCheckBox) {  // QCheckBox
      if (item->isChecked()) {
        output.push_back(index);
      }
      index++;
    }
  }
  return output;
}

void BListCheckBox::initUI() {
  grid = new QGridLayout(this);
  setLayout(grid);
  label = new QLabel(this);
  label->setText(title);
  label->setFont(font_subHeader());
  grid->addWidget(label, 0, 0, 1, 2);
  int maxRowPerColumn = ceil((float)options.size() / numberColumn);

  if (isSingleChoice) {
    QButtonGroup *buttonGroup = new QButtonGroup(this);
    int index = 0;
    for (auto item : options) {
      int row = index % maxRowPerColumn;
      int column = index / maxRowPerColumn;
      QRadioButton *radioButton = new QRadioButton(item, this);
      grid->addWidget(radioButton, row + 1, column);
      buttonGroup->addButton(radioButton);
      vectorRadioButton.push_back(radioButton);
      index++;
    }
  } else {
    int index = 0;
    for (auto item : options) {
      int row = index % maxRowPerColumn;
      int column = index / maxRowPerColumn;
      QCheckBox *box = new QCheckBox(item, this);
      vectorCheckBox.push_back(box);
      grid->addWidget(box, row + 1, column);
      index++;
    }
  }
}
