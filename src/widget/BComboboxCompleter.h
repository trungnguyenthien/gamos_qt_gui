#ifndef BCOMBOBOXCOMPLETER_H
#define BCOMBOBOXCOMPLETER_H

#include <QComboBox>
#include <QCompleter>
#include <QString>
#include <vector>

class BComboboxCompleter : public QComboBox {
  Q_OBJECT

public:
  explicit BComboboxCompleter(QWidget *parent = nullptr);
  void setSuggestKeywords(const std::vector<QString> &keywords);

private:
  QCompleter *completer;
};

#endif  // BCOMBOBOXCOMPLETER_H
