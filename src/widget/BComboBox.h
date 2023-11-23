#ifndef __BCOMBOBOX_H__
#define __BCOMBOBOX_H__

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>
#include <memory>

#include "BHStackWidget.h"

using namespace std;
class BComboBox : public BHStackWidget {
  Q_OBJECT
 public:
  BComboBox(QWidget *parent, string title);
  unique_ptr<QComboBox> combobox;
  unique_ptr<QLabel> label;
}

#endif  // __BCOMBOBOX_H__