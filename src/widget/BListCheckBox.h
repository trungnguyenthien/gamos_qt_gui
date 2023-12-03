#ifndef __BLISTCHECKBOX_H__
#define __BLISTCHECKBOX_H__

#include <QCheckBox>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>
#include <memory>
#include <vector>

#include "BVStackWidget.h"

using namespace std;
class BListCheckBox : public QWidget {
  Q_OBJECT
 private:
  QGridLayout* grid;

 public:
  // CONFIG VARIABLE
  QString title;
  bool isSingleChoice;
  vector<QString> options;
  int numberColumn = 2;
  //
  BListCheckBox(QWidget* parent);
  vector<unique_ptr<QCheckBox>> vectorCheckBox;
  vector<unique_ptr<QRadioButton>> vectorRadioButton;
  unique_ptr<QLabel> label;
  vector<int> selectedIndices;
  void initUI();
};
#endif  // __BLISTCHECKBOX_H__