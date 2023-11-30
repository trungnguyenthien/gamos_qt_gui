#ifndef __BLISTCHECKBOX_H__
#define __BLISTCHECKBOX_H__

#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QRadioButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>
#include <memory>
#include <vector>

#include "BVStackWidget.h"

using namespace std;
class BListCheckBox : public BVStackWidget {
  Q_OBJECT
 public:
  bool isSingleChoice;
  BListCheckBox(QWidget *parent, bool isSingleChoice, vector<string> options);
  vector<unique_ptr<QCheckBox>> vectorCheckBox;
  vector<unique_ptr<QComboBox>> vectorRadioButton;

  vector<int> selectedIndices;
};
#endif  // __BLISTCHECKBOX_H__