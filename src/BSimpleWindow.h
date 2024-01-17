#ifndef BSIMPLEWINDOW_H_
#define BSIMPLEWINDOW_H_

#include <QCheckBox>
#include <QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <initializer_list>
#include <memory>
#include <unordered_map>
#include <vector>

#include "model/Types.h"
#include "utils/BFileGen.h"
#include "virtual/BWindow.h"
#include "widget/BComboBox.h"
#include "widget/BGroupNumberInput.h"
#include "widget/BLineEditCompleter.h"
#include "widget/BListCheckBox.h"
#include "widget/BListCheckText.h"
#include "widget/BNumberInput.h"
#include "widget/BPos3Input.h"
using namespace std;
class BSimpleWindow : public QTabWidget, public BWindow {
private:
  QWidget *phantomLayout;
  QWidget *sourceLayout;
  QWidget *outputLayout;

  void initPhantomLayout();
  void initSourceLayout();
  void initOutputLayout();
  BComboBox *cbbSourceTypes;
  vector<SOURCETYPE> sourceTypes;

  BLineEditCompleter *cbbIsotopes;
  // vector<ISOTOPE> isotopes;

  BComboBox *cbbParticles;
  vector<PARTICLE> particles;

  BNumberInput *numberEngergy;

  vector<MATTER> matter_source;
  BComboBox *cbbMatter;

  vector<GroupNumberInputValue> group_geom_source;
  GroupNumberInputValue groupNumberInputValue;
  BGroupNumberInput *bGroupNumberInput;

  BPos3Input *posXYZ;

  BComboBox *cbbDirectDistribution;
  vector<GroupNumberInputValue> group_direction_source;
  BGroupNumberInput *bGroupDirectDistribution;

  QCheckBox *ckPartidePropagating;
  QCheckBox *ckDoseMap;
  QCheckBox *ckEnergyDositionMap;

  // vector<RADIATION> radiation_source;
  // vector<int> radiation_check;
  // vector<ENERGY> energy_source;
  // vector<PARTICLE> particle_source;
  // vector<MATTER> matter_source;
  // BPos3Input *pos3Rad;
  // BPos3Input *pos3Mat;
  QString session_dir;
  // bool isMultipleMatter = false;
  // vector<RADIATION> selectedRadiation();
  // ENERGY selecedEnergy();
  // unordered_map<MATTER, QString> selectedMatter();

  BFileGen *genInFile();
  BFileGen *genGeomFile();

public:
  BComboBox *cbbGeom;

  // QPushButton *btn_enter;
  // BListCheckBox *listRadiation;
  // BComboBox *cbbEnergy;
  // BComboBox *cbbParticle;
  // BListCheckText *listMatterMutiple;
  /// @brief Constructor
  /// @param parent
  /// @param mode 0 (mutiple), 1 (one)
  BSimpleWindow(QWidget *parent);

  // Virtual class BWindow
  string title() override;
  string description() override;
  QWidget *self_widget() override;
};

#endif  // BSIMPLEWINDOW_H_