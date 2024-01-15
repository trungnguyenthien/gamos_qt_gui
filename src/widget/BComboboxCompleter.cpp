#include "BComboboxCompleter.h"

#include <QStringList>
#include <QStringListModel>

BComboboxCompleter::BComboboxCompleter(QWidget *parent)
    : QComboBox(parent), completer(new QCompleter(this)) {
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setFilterMode(Qt::MatchContains);
  setCompleter(completer);
}

void BComboboxCompleter::setSuggestKeywords(const std::vector<QString> &keywords) {
  QStringList keywordList;
  for (const auto &keyword : keywords) {
    keywordList << keyword;
  }

  setModel(new QStringListModel(keywordList, this));
  completer->setModel(model());
}
