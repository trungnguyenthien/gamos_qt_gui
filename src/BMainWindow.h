#ifndef __BMAINWINDOWS_H__
#define __BMAINWINDOWS_H__

#include <QStackedWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <memory>
#include <vector>

#include "virtual/BWindow.h"
#include "widget/BHStackWidget.h"
#include "widget/BVStackWidget.h"
using namespace std;

class BMainWindow : public BVStackWidget {
  Q_OBJECT
 public:
  // unique_ptr<BWindow> rootWindows;
  unique_ptr<QStackedWidget> stackedWidget;
  unique_ptr<BHStackWidget> topPlaceHolder;
  unique_ptr<QPushButton> backButton;
  unique_ptr<QLabel> titleLabel;

  vector<BWindow *> windows;
  void push(BWindow *wd);
  void pop_back();
  BMainWindow(QWidget *parent);
  static BMainWindow *shared_mainwindow;
};

#endif  // __BMAINWINDOWS_H__