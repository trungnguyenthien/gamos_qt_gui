#ifndef __BDEMO2WINDOW_H__
#define __BDEMO2WINDOW_H__

#include <QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <memory>
#include <vector>

#include "model/Types.h"
#include "virtual/BWindow.h"
#include "widget/BComboBox.h"
#include "widget/BListCheckBox.h"

using namespace std;
class BDemo2Window : public QWidget, public BWindow {
 private:
  unique_ptr<QGridLayout> grid;
  int mode = 0;
  vector<RADIATION> radiation_source;
  vector<int> radiation_check;
  vector<ENERGY> energy_source;
  // vector<bool> radiation_check;
  vector<MATTER> matter_source;

 public:
  unique_ptr<QPushButton> btn_enter;
  unique_ptr<BComboBox> cbbRadiation;
  unique_ptr<BListCheckBox> listRadiation;
  unique_ptr<BComboBox> cbbEnergy;
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