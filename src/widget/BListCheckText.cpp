#include "BListCheckText.h"

#include "../utils/Helper.h"

BListCheckText::BListCheckText(QWidget* parent, QString title, QString hintEdit,
                               bool isSingleChoice, vector<QString> options)
    : QWidget(parent) {
  this->isSingleChoice = isSingleChoice;
  this->title = title;
  this->hintEdit = hintEdit;
  this->options = options;
}

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

QLineEdit* BListCheckText::makeCheck(int index, QString text, QString hintEdit,
                                     QButtonGroup* group) {
  const int CHECK_COL = 0;
  const int TEXT_COL = 1;
  QLabel* label = new QLabel(this);
  QLineEdit* edit = new QLineEdit(this);
  edit->setPlaceholderText(hintEdit);
  edit->setReadOnly(true);
  edit->hide();
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

    // connectButtonClicked(btn_demo.get(), [this]() {
    //   BMainWindow::shared->push(new BDemo1Window(this));
    // });
  }

  return edit;
}

void BListCheckText::handleCheckBoxStateChange(bool isChecked,
                                               QLineEdit* edit) {
  edit->setReadOnly(!isChecked);

  if (!isChecked) {
    edit->setText("");
    edit->hide();
  } else {
    edit->show();
  }
}
