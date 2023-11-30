#include "BListCheckBox.h"

#include <QButtonGroup>
BListCheckBox::BListCheckBox(QWidget *parent, bool isSingleChoice,
                             vector<QString> options)
    : BVStackWidget(parent) {
  this->isSingleChoice = isSingleChoice;
  if (isSingleChoice) {
    QButtonGroup *buttonGroup = new QButtonGroup(this);
    for (auto item : options) {
      QRadioButton *radioButton = new QRadioButton(item);
      addSubWidget(radioButton);
      buttonGroup->addButton(radioButton);
      vectorRadioButton.push_back(unique_ptr<QRadioButton>(radioButton));
    }
  } else {
    for (auto item : options) {
      QCheckBox *box = new QCheckBox(item);
      vectorCheckBox.push_back(unique_ptr<QCheckBox>(box));
      addSubWidget(box);
    }
  }
}
