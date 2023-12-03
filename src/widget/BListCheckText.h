#ifndef __BLISTCHECKTEXT_H__
#define __BLISTCHECKTEXT_H__

#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QWidget>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;
class BListCheckText : public QWidget {
  Q_OBJECT
 private:
  unique_ptr<QGridLayout> grid;
  QLineEdit* makeCheck(int index, QString text, QString hintEdit,
                       QButtonGroup* group);
  void handleCheckBoxStateChange(bool isChecked, QLineEdit* edit);

 public:
  QString hintEdit = "NO HINT";
  QString title = "NO TITLE";
  QString defaultValue = "";
  vector<QString> options;
  bool isSingleChoice = false;
  bool allowEdit = true;
  BListCheckText(QWidget* parent);
  void initUI();
  unordered_map<int, string> selectedValue();
  vector<unique_ptr<QLineEdit>> lineEdits;
  vector<int> selectedIndices;
};

#endif  // __BLISTCHECKTEXT_H__