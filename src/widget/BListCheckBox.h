#ifndef __BLISTCHECKBOX_H__
#define __BLISTCHECKBOX_H__

#include <QCheckBox>
#include <QComboBox>
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
class BListCheckBox : public BVStackWidget {
  Q_OBJECT
 public:
  bool isSingleChoice;
  BListCheckBox(QWidget *parent, string title, bool isSingleChoice,
                vector<QString> options);
  vector<unique_ptr<QCheckBox>> vectorCheckBox;
  vector<unique_ptr<QRadioButton>> vectorRadioButton;
  unique_ptr<QLabel> label;
  vector<int> selectedIndices;
};
#endif  // __BLISTCHECKBOX_H__