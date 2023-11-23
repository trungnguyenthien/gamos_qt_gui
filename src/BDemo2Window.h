#ifndef __BDEMO2WINDOW_H__
#define __BDEMO2WINDOW_H__

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <memory>

#include "virtual/BWindow.h"

using namespace std;
class BDemo2Window : public QWidget, public BWindow {
 private:
  unique_ptr<QGridLayout> grid;

 public:
  unique_ptr<QPushButton> btn_enter;

  /// @brief Constructor
  /// @param parent
  /// @param mode 0 (mutiple), 1 (one)
  BDemo2Window(QWidget *parent, int mode = 0);
  ~BDemo2Window();

  // Virtual class BWindow
  string title() override;
  string description() override;
  QWidget *self_widget() override;
};

#endif  // __BDEMO2WINDOW_H__