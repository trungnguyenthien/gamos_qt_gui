#ifndef BExpertWindow_H
#define BExpertWindow_H

#include <QCheckBox>
#include <QLabel>
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

#include "model/Isotope.h"
#include "model/Types.h"
#include "utils/BFileGen.h"
#include "virtual/BWindow.h"
#include "widget/BComboBox.h"
#include "widget/BGroupNumberInput.h"
#include "widget/BLineEditCompleter.h"
#include "widget/BListCheckBox.h"
#include "widget/BListCheckText.h"
#include "widget/BNumberInput.h"
#include "widget/BPathInput.h"
#include "widget/BPos3Input.h"

class BExpertWindow : public QTabWidget, public BWindow {
  Q_OBJECT
private:
  QWidget *phantomLayout;
  QWidget *sourceLayout;
  QWidget *outputLayout;
  void initPhantomLayout();
  void initSourceLayout();
  void initOutputLayout();

  vector<GroupNumberInputValue> group_geom_source;
  GroupNumberInputValue groupNumberInputValue;
  BGroupNumberInput *bGroupNumberInput;
  BComboBox *cbbGeom;

  vector<GroupNumberInputValue> group_shape_source;
  BComboBox *cbbShape;
  GroupNumberInputValue groupShapeInputValue;
  BGroupNumberInput *bGroupShapeInput;

  vector<MATTER> matter_source;
  BComboBox *cbbMatter;

  BPathInput *pathPhantomVoxel, *pathMessPhantom;
  BPos3Input *phantomPosXYZ, *phantomAngXYZ;

  BComboBox *cbbParticles;
  vector<PARTICLE> particles;

  BNumberInput *numberEngergy;
  BPos3Input *distributionPosXYZ, *distributionAngXYZ, *directionDirXYZ;

  BLineEditCompleter *cbbIsotopes;
  BNumberInput *numberActivity;

  BComboBox *cbbDistributionType;
  vector<DISTRIBUTIONTYPE> distributions;

  BComboBox *cbbOrganType;
  vector<ORGANTYPE> organs;

  BPathInput *pathNmImage;

public:
  BExpertWindow(QWidget *parent);
  ~BExpertWindow();

  // Virtual class BWindow
  string title() override;
  string description() override;
  QWidget *self_widget() override;
};

#endif