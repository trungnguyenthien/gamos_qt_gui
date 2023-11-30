#include "BListCheckBox.h"

#include <QButtonGroup>
BListCheckBox::BListCheckBox(QWidget *parent, bool isSingleChoice,
                             vector<string> options)
    : BVStackWidget(parent) {
  this->isSingleChoice = isSingleChoice;
  if (isSingleChoice) {
    QButtonGroup *buttonGroup = new QButtonGroup(this);
    for (auto item : options) {
      QRadioButton *radioButton =
          new QRadioButton(QString::fromStdString(item));
      addSubWidget(radioButton);
      buttonGroup->addButton(radioButton);
      vectorRadioButton.push_back(unique_ptr<QPushBack>(radioButton));
    }
  } else {
    for (auto item : options) {
      QCheckBox *box = new QCheckBox(QString::fromStdString(item));
      vectorCheckBox.push_back(unique_ptr<QCheckBox>(box));
      addSubWidget(box);
    }
  }
}
