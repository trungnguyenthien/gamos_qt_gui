#include "BListCheckBox.h"

#include <QButtonGroup>

#include "../utils/Helper.h"
BListCheckBox::BListCheckBox(QWidget *parent, string title, bool isSingleChoice,
                             vector<QString> options)
    : BVStackWidget(parent) {
  this->isSingleChoice = isSingleChoice;
  label = unique_ptr<QLabel>(new QLabel(this));
  label.get()->setText(QString::fromStdString(title));
  label.get()->setFont(font_subHeader());
  addSubWidget(label.get());
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
