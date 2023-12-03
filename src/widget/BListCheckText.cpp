#include "BListCheckText.h"

#include "../utils/Helper.h"

BListCheckText::BListCheckText(QWidget* parent) : QWidget(parent) {}

void BListCheckText::initUI() {
  grid = unique_ptr<QGridLayout>(new QGridLayout(this));
  this->setLayout(grid.get());
  QButtonGroup* group = new QButtonGroup(this);
  QLabel* titleLabel = new QLabel(this);
  titleLabel->setText(title);
  titleLabel->setFont(font_subHeader());
  grid->addWidget(titleLabel, 0, 0, 1, 2);

  for (int index = 0; index < options.size(); index++) {
    makeCheck(index, options[index], hintEdit, group);
  }
}

unordered_map<int, QString> BListCheckText::selectedValue() {
  unordered_map<int, QString> output;
  for (int i = 0; i < lineEdits.size(); i++) {
    auto edit = lineEdits[i];
    QString text = edit->text();

    if (edit->isReadOnly()) {
      continue;
    }
    output[i] = text;
  }
  return output;
}

QLineEdit* BListCheckText::makeCheck(int index, QString text, QString hintEdit,
                                     QButtonGroup* group) {
  const int CHECK_COL = 0;
  const int TEXT_COL = 1;
  QLabel* label = new QLabel(this);
  QLineEdit* edit = new QLineEdit(this);
  lineEdits.push_back(edit);
  edit->setPlaceholderText(hintEdit);
  edit->setReadOnly(true);
  // edit->hide();
  int rowIndex = index + 1;
  const int rowHeight = 25;
  if (this->isSingleChoice) {
    QRadioButton* radioButton = new QRadioButton(this);
    ds_wg_set_fixed_h(radioButton, rowHeight);
    radioButton->setText(text);
    radioButton->setStyleSheet(
        "QRadioButton::indicator { subcontrol-position: left; }");
    group->addButton(radioButton);
    grid->addWidget(radioButton, rowIndex, CHECK_COL);
    grid->addWidget(edit, rowIndex, TEXT_COL);
    connectRadioButtonToggle(radioButton, [this, edit](bool checked) {
      this->handleCheckBoxStateChange(checked, edit);
    });
  } else {
    QCheckBox* checkBox = new QCheckBox(this);
    ds_wg_set_fixed_h(checkBox, rowHeight);
    checkBox->setText(text);
    checkBox->setStyleSheet(
        "QCheckBox::indicator { subcontrol-position: left; }");
    grid->addWidget(checkBox, rowIndex, CHECK_COL);
    grid->addWidget(edit, rowIndex, TEXT_COL);

    connectCheckBoxToggle(checkBox, [this, edit](bool checked) {
      this->handleCheckBoxStateChange(checked, edit);
    });
  }

  return edit;
}

void BListCheckText::handleCheckBoxStateChange(bool isChecked,
                                               QLineEdit* edit) {
  edit->setReadOnly(!isChecked);
  cout << "isChecked " << isChecked;
  // edit->hide();

  if (isChecked && allowEdit) {
    edit->show();
  }

  if (isChecked) {
    edit->setText(defaultValue);
  } else {
    edit->setText("");
  }
}
