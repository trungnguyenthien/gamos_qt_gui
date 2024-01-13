#ifndef WIDGET_BGROUPNUMBERINPUT_H_
#define WIDGET_BGROUPNUMBERINPUT_H_

#include <QGridLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>
#include <memory>
#include <vector>

#include "../model/Types.h"
#include "../utils/Helper.h"

using namespace std;

class BGroupNumberInput : public QWidget {
  Q_OBJECT
private:
  QGridLayout *grid;

public:
  BGroupNumberInput(QWidget *parent) : QWidget(parent) {
    grid = new QGridLayout(this);
    this->setLayout(grid);
    ds_wg_set_expanding_w(this);
  }
  GroupNumberInputValue groupNumberInputValue;
  void initUI(GroupNumberInputValue groupNumberInputValue);
  void removeAll();
  GroupNumberInputValue values();
};

#endif  // WIDGET_BGROUPNUMBERINPUT_H_
