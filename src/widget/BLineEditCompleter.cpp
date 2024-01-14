#include "BLineEditCompleter.h"

#include <QStringListModel>

BLineEditCompleter::BLineEditCompleter(QWidget *parent)
    : QLineEdit(parent), completer(new QCompleter(this)) {
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setFilterMode(Qt::MatchContains);
  setCompleter(completer);
}

void BLineEditCompleter::setSuggestKeywords(const std::vector<QString> &keywords) {
  QStringList keywordList;
  for (const auto &keyword : keywords) {
    keywordList << keyword;
  }

  QStringListModel *model = new QStringListModel(keywordList, completer);
  completer->setModel(model);
}
