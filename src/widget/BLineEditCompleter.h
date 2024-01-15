#ifndef BLINEEDITCOMPLETER_H
#define BLINEEDITCOMPLETER_H

#include <QCompleter>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <vector>
class BLineEditCompleter : public QWidget {
  Q_OBJECT

public:
  QLabel *label;
  QLineEdit *lineEdit;
  bool isTitleInLine = false;
  void initUI();
  BLineEditCompleter(QWidget *parent, QString labelText);
  void setSuggestKeywords(const std::vector<QString> &keywords);

private:
  QCompleter *completer;
};

#endif  // BLINEEDITCOMPLETER_H
