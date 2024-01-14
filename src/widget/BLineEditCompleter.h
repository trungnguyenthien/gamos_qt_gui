#ifndef BLINEEDITCOMPLETER_H
#define BLINEEDITCOMPLETER_H

#include <QCompleter>
#include <QLineEdit>
#include <QString>
#include <vector>

class BLineEditCompleter : public QLineEdit {
  Q_OBJECT

public:
  explicit BLineEditCompleter(QWidget *parent = nullptr);
  void setSuggestKeywords(const std::vector<QString> &keywords);

private:
  QCompleter *completer;
};

#endif  // BLINEEDITCOMPLETER_H
