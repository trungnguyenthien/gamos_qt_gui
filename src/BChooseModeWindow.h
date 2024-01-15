#ifndef __BCHOOSEMODEWINDOWS_H__
#define __BCHOOSEMODEWINDOWS_H__

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <memory>

#include "BDemo1Window.h"
#include "BExpertWindow.h"
#include "BMainWindow.h"
#include "BSimpleWindow.h"
#include "utils/Helper.h"
#include "virtual/BWindow.h"

using namespace std;
class BChooseModeWindow : public QWidget, public BWindow {
private:
  QGridLayout *grid;

public:
  QLabel *lb_description;
  QLabel *lb_welcome;
  QPushButton *btn_demo;
  QPushButton *btn_simple;
  QPushButton *btn_expert;
  BChooseModeWindow(QWidget *parent);
  ~BChooseModeWindow();

  // Virtual class BWindow
  string title() override;
  string description() override;
  QWidget *self_widget() override;
};
#endif  // __BCHOOSEMODEWINDOWS_H__