#ifndef __BDEMO2WINDOW_H__
#define __BDEMO2WINDOW_H__

#include <QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <memory>
#include <unordered_map>
#include <vector>

#include "model/Types.h"
#include "utils/BFileGen.h"
#include "virtual/BWindow.h"
#include "widget/BComboBox.h"
#include "widget/BListCheckBox.h"
#include "widget/BListCheckText.h"
#include "widget/BPos3Input.h"

using namespace std;
class BDemo2Window : public QWidget, public BWindow {
private:
  QGridLayout *grid;
  int mode = 0;
  vector<RADIATION> radiation_source;
  vector<int> radiation_check;
  vector<ENERGY> energy_source;
  vector<MATTER> matter_source;
  BPos3Input *pos3Rad;
  BPos3Input *pos3Mat;
  QString session_dir;
  bool isMultipleMatter = false;
  vector<RADIATION> selectedRadiation();
  ENERGY selecedEnergy();
  unordered_map<MATTER, QString> selectedMatter();

  BFileGen *genInFile();
  BFileGen *genGeomFile();

public:
  QPushButton *btn_enter;
  BListCheckBox *listRadiation;
  BComboBox *cbbEnergy;
  BListCheckText *listMatterMutiple;
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