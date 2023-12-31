#ifndef BExpertWindow_H
#define BExpertWindow_H

#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

#include "virtual/BWindow.h"

class BExpertWindow : public QTabWidget, public BWindow {
  Q_OBJECT
 public:
  QWidget *phantomLayout;
  QWidget *sourceLayout;
  QWidget *outputLayout;
  BExpertWindow(QWidget *parent);
  ~BExpertWindow();

  // Virtual class BWindow
  string title() override;
  string description() override;
  QWidget *self_widget() override;
};

#endif