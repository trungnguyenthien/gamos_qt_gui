#ifndef __BDEMO1WINDOW_H__
#define __BDEMO1WINDOW_H__

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <memory>

#include "virtual/BWindow.h"

using namespace std;
class BDemo1Window : public QWidget, public BWindow {
 private:
  unique_ptr<QGridLayout> grid;

 public:
  unique_ptr<QPushButton> btn_multiple;
  unique_ptr<QPushButton> btn_one;
  BDemo1Window(QWidget *parent);
  ~BDemo1Window();

  // Virtual class BWindow
  string title() override;
  string description() override;
  QWidget *self_widget() override;
};

#endif  // __BDEMO1WINDOW_H__