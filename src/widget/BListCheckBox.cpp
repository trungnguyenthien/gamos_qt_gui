#include "BListCheckBox.h"

#include <QButtonGroup>
#include <cmath>

#include "../utils/Helper.h"
BListCheckBox::BListCheckBox(QWidget *parent) : QWidget(parent) {}

void BListCheckBox::initUI() {
  grid = new QGridLayout(this);
  setLayout(grid);
  label = unique_ptr<QLabel>(new QLabel(this));
  label.get()->setText(title);
  label.get()->setFont(font_subHeader());
  grid->addWidget(label.get(), 0, 0, 1, 2);
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
      vectorRadioButton.push_back(unique_ptr<QRadioButton>(radioButton));
      index++;
    }
  } else {
    int index = 0;
    for (auto item : options) {
      int row = index % maxRowPerColumn;
      int column = index / maxRowPerColumn;
      QCheckBox *box = new QCheckBox(item, this);
      vectorCheckBox.push_back(unique_ptr<QCheckBox>(box));
      grid->addWidget(box, row + 1, column);
      index++;
    }
  }
}
