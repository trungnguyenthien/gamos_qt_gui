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

enum class POSITION_DISTRIBUTION {
  NONE,
  AT_POINT,
  USER_DEF_VOLUME,
  USER_DEF_VOLUME_SURFACE,
  STEP_ALONG_LINE,
  IN_SQUARE,
  IN_RECT,
  IN_DISC,
  IN_DISC_WITH_GAUSSIAN_DISTRIBUTION,
  IN_VOXEL_PHANTOM_FILE
};
QString POSITION_DISTRIBUTION_text(POSITION_DISTRIBUTION value);
// QString POSITION_DISTRIBUTION_value(POSITION_DISTRIBUTION value);

class BExpertWindow : public QTabWidget, public BWindow {
  Q_OBJECT
private:
  QWidget *phantomLayout;
  QWidget *sourceLayout;
  QWidget *outputLayout;
  void initPhantomLayout();
  void initSourceLayout();
  void initOutputLayout();

  vector<GroupNumberInputValue> group_shape_source;
  BComboBox *cbbShape;
  GroupNumberInputValue groupShapeInputValue;
  BGroupNumberInput *bGroupShapeInput;

  BPathInput *pathPhantomVoxel, *pathMessPhantom;
  BPos3Input *phantomPosXYZ;

  BComboBox *cbbParticles;
  vector<PARTICLE> particles;

  BNumberInput *numberEngergy;

  BComboBox *cbbDirectDistribution;
  vector<GroupNumberInputValue> group_direction_source;
  BGroupNumberInput *bGroupDirectDistribution;

  BLineEditCompleter *cbbIsotopes;
  BNumberInput *numberActivity;

  BPathInput *pathNmImage;

  vector<POSITION_DISTRIBUTION> positionDirectionSource;
  BComboBox *cbbPositionDirection;

  BPos3Input *pos3AtPoint;
  BPos3Input *pos3PositionOfShape;

  BGroupNumberInput *bGroupStepAlongLine;
  BGroupNumberInput *bGroupPositionInSquare;
  BGroupNumberInput *bGroupPositionInRect;
  BGroupNumberInput *bGroupPositionInDisc;
  BGroupNumberInput *bGroupPositionInDiscGauss;
  BGroupNumberInput *bGroupPositionInVoxel;

  QCheckBox *ckPartidePropagating;
  QCheckBox *ckDoseMap;
  QCheckBox *ckEnergyDositionMap;
  QString session_dir;

  void showPositionDistribution(POSITION_DISTRIBUTION pd);

public:
  BExpertWindow(QWidget *parent);
  ~BExpertWindow();

  // Virtual class BWindow
  string title() override;
  string description() override;
  QWidget *self_widget() override;

  BFileGen *genInFile();
  BFileGen *genGeomFile();
};

#endif