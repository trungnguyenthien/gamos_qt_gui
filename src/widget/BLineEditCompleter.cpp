#include "BLineEditCompleter.h"

#include <QGridLayout>
#include <QStringListModel>

#include "../model/B10ItemModel.h"
#include "../utils/Helper.h"

void BLineEditCompleter::initUI() {
  QGridLayout *grid = new QGridLayout(this);
  grid->setSpacing(0);
  grid->setContentsMargins(0, 0, 0, 0);
  grid->setMargin(0);
  setLayout(grid);
  this->setLayout(grid);

  label->setAlignment(Qt::AlignVCenter);
  ds_label_align_left(label);
  label->setFont(font_subHeader());
  ds_wg_set_expanding_w(label);
  ds_wg_set_expanding_w(lineEdit);

  if (isTitleInLine) {
    grid->addWidget(label, 0, 0);
    grid->addWidget(lineEdit, 0, 1);
  } else {
    grid->addWidget(label, 0, 0, 1, 2);
    grid->addWidget(lineEdit, 1, 0, 1, 2);
  }
}

BLineEditCompleter::BLineEditCompleter(QWidget *parent, QString labelText) : QWidget(parent) {
  label = new QLabel(this);
  label->setText(labelText);
  lineEdit = new QLineEdit(this);
  completer = new QCompleter(this);
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setFilterMode(Qt::MatchContains);
  lineEdit->setCompleter(completer);
}

void BLineEditCompleter::setSuggestKeywords(const std::vector<QString> &keywords) {
  QStringList keywordList;
  for (const auto &keyword : keywords) {
    keywordList << keyword;
  }
  // B10ItemModel *model = new B10ItemModel(this);
  // model->setKeywords(keywords);
  QStringListModel *model = new QStringListModel(keywordList, completer);
  completer->setModel(model);
  completer->setCompletionMode(QCompleter::PopupCompletion);
  completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
}
