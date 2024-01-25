#include "BExpertWindow.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabBar>

#include "utils/Helper.h"
#include "widget/BVStackWidget.h"
#include "widget/TerminalDialog.h"

void BExpertWindow::initPhantomLayout() {
  BVStackWidget *leftStack = new BVStackWidget(this);
  // BVStackWidget *rightStack = new BVStackWidget(this);
  QGridLayout *grid = new QGridLayout(this);
  grid->setColumnStretch(0, 1);  // Cột trái với hệ số co giãn là 2
  grid->setColumnStretch(1, 1);  // Cột phải với hệ số co giãn là 3
  // grid->setColumnStretch(2, 1);  // Cột phải với hệ số co giãn là 3
  grid->setColumnStretch(3, 1);  // Cột phải với hệ số co giãn là 3
  phantomLayout->setLayout(grid);

  grid->addWidget(leftStack, 0, 1);
  // grid->addWidget(rightStack, 0, 2);

  // group_geom_source = full_group_geom_source();

  // GEOMETRY
  // cbbGeom = new BComboBox(this, "Mathematical Phantom");
  // for (auto group : group_geom_source) {
  //   QString label = group.label;
  //   cbbGeom->addItem(label);
  // }
  // cbbGeom->isTitleInLine = false;
  // ds_wg_set_expanding_w(cbbGeom);
  // cbbGeom->initUI();

  // bGroupNumberInput = new BGroupNumberInput(this);
  // connectCbbIndexChange(cbbGeom->combobox, [this](int index) {
  //   this->bGroupNumberInput->removeAll();
  //   GroupNumberInputValue selectGroup = this->group_geom_source[index];
  //   this->bGroupNumberInput->initUI(selectGroup);
  // });

  // leftStack->addSubWidget(cbbGeom);
  // leftStack->addSubWidget(bGroupNumberInput);

  // matter_source.push_back(MATTER::LEAD);
  // matter_source.push_back(MATTER::ALUMIUM);
  // matter_source.push_back(MATTER::PAPER);
  // matter_source.push_back(MATTER::CONCRETE);
  // matter_source.push_back(MATTER::WATER);
  // matter_source.push_back(MATTER::AIR);
  // matter_source.push_back(MATTER::COMPACT_BONE);
  // matter_source.push_back(MATTER::CORTICAL_BONE);
  // matter_source.push_back(MATTER::BRAIN);
  // matter_source.push_back(MATTER::EYE_LENS);
  // matter_source.push_back(MATTER::GLASS_LEAD);
  // matter_source.push_back(MATTER::GLUCOSE);
  // matter_source.push_back(MATTER::LUNG);
  // matter_source.push_back(MATTER::SKELETAL_MUSCLE);
  // matter_source.push_back(MATTER::STRIATED_MUSCLE);
  // matter_source.push_back(MATTER::PARAFFIN);
  // matter_source.push_back(MATTER::SKIN);
  // matter_source.push_back(MATTER::TESTES);
  // matter_source.push_back(MATTER::GRAPHITE);
  // matter_source.push_back(MATTER::ADULT_THYROID);
  // matter_source.push_back(MATTER::ADULT_SPLEEN);
  // matter_source.push_back(MATTER::ADULT_HEART);
  // matter_source.push_back(MATTER::ADULT_KIDNEY);
  // matter_source.push_back(MATTER::ADULT_LIVER);
  // matter_source.push_back(MATTER::ADULT_OVARY);
  // matter_source.push_back(MATTER::ADULT_PANCREAS);

  // cbbMatter = new BComboBox(this, "Matterial");
  // for (MATTER matter : matter_source) {
  //   cbbMatter->addItem(MATTER_text(matter));
  // }
  // cbbMatter->isTitleInLine = false;
  // cbbMatter->initUI();
  // ds_wg_set_expanding_w(cbbMatter);
  // leftStack->addSubWidget(cbbMatter);

  pathPhantomVoxel = new BPathInput(this, "PhantomVoxel", "");
  leftStack->addSubWidget(pathPhantomVoxel);
  pathMessPhantom = new BPathInput(this, "MessPhantom", "");
  leftStack->addSubWidget(pathMessPhantom);

  QLabel *phantomPosLabel = new QLabel("Phantom's position", this);
  phantomPosLabel->setFont(font_subHeader());
  leftStack->addSubWidget(phantomPosLabel);

  phantomPosXYZ = new BPos3Input(this, "");
  phantomPosXYZ->initUI("POS_X", "POS_Y", "POS_Z");
  leftStack->addSubWidget(phantomPosXYZ);

  // phantomAngXYZ = new BPos3Input(this, "");
  // phantomAngXYZ->initUI("ANG_X", "ANG_Y", "ANG_Z");
  // rightStack->addSubWidget(phantomAngXYZ);
}

void BExpertWindow::initSourceLayout() {
  BVStackWidget *stack1 = new BVStackWidget(this);
  BVStackWidget *stack2 = new BVStackWidget(this);
  BVStackWidget *stack3 = new BVStackWidget(this);
  BVStackWidget *stack4 = new BVStackWidget(this);
  QGridLayout *grid = new QGridLayout(this);
  grid->setColumnStretch(0, 1);
  grid->setColumnStretch(1, 1);
  grid->setColumnStretch(2, 1);
  grid->setColumnStretch(3, 1);
  sourceLayout->setLayout(grid);

  grid->addWidget(stack1, 0, 0);
  grid->addWidget(stack2, 0, 1);
  grid->addWidget(stack3, 0, 2);
  grid->addWidget(stack4, 0, 3);

  // STACK 1 ========================================================
  cbbParticles = new BComboBox(this, "Particles");
  particles = {PARTICLE::NONE,       PARTICLE::ALPHA, PARTICLE::E_NEGATIVE,
               PARTICLE::E_POSITIVE, PARTICLE::GAMMA, PARTICLE::NEUTRON};
  for (PARTICLE item : particles) {
    cbbParticles->addItem(PARTICLE_text(item));
  }
  cbbParticles->isTitleInLine = true;
  cbbParticles->initUI();
  stack1->addSubWidget(cbbParticles);

  numberEngergy = new BNumberInput(this, NumberInputValue("Energy", "Energy", "1", ""));
  numberEngergy->initUI(true, false);
  stack1->addSubWidget(numberEngergy);

  cbbIsotopes = new BLineEditCompleter(this, "Isotopes");
  cbbIsotopes->isTitleInLine = true;
  cbbIsotopes->setSuggestKeywords(isotope_sources());
  cbbIsotopes->initUI();
  stack1->addSubWidget(cbbIsotopes);

  numberActivity = new BNumberInput(this, NumberInputValue("Activity", "Activity", "1", ""));
  numberActivity->initUI(true, false);
  stack1->addSubWidget(numberActivity);

  pathNmImage = new BPathInput(this, "NM Image", "");
  stack1->addSubWidget(pathNmImage);

  // STACK 2 ========================================================
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::NONE);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::AT_POINT);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::USER_DEF_VOLUME);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::USER_DEF_VOLUME_SURFACE);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::STEP_ALONG_LINE);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::IN_SQUARE);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::IN_RECT);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::IN_DISC);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::IN_DISC_WITH_GAUSSIAN_DISTRIBUTION);
  positionDirectionSource.push_back(POSITION_DISTRIBUTION::IN_VOXEL_PHANTOM_FILE);
  cbbPositionDirection = new BComboBox(this, "Position Distribution");
  cbbPositionDirection->isTitleInLine = false;
  for (POSITION_DISTRIBUTION pd : positionDirectionSource) {
    cbbPositionDirection->addItem(POSITION_DISTRIBUTION_text(pd));
  }
  cbbPositionDirection->initUI();
  stack2->addSubWidget(cbbPositionDirection);

  pos3AtPoint = new BPos3Input(this, "");
  pos3AtPoint->initUI("POS_X", "POS_Y", "POS_Z");
  pos3AtPoint->hide();
  stack2->addSubWidget(pos3AtPoint);

  group_shape_source = full_group_shape_source();

  // GEOMETRY
  cbbShape = new BComboBox(this, "Shape");
  for (auto group : group_shape_source) {
    QString label = group.label;
    cbbShape->addItem(label);
  }
  cbbShape->isTitleInLine = true;
  ds_wg_set_expanding_w(cbbShape);
  cbbShape->initUI();

  bGroupShapeInput = new BGroupNumberInput(this);
  connectCbbIndexChange(cbbShape->combobox, [this](int index) {
    this->bGroupShapeInput->removeAll();
    pos3PositionOfShape->hide();
    GroupNumberInputValue selectGroup = this->group_shape_source[index];
    this->bGroupShapeInput->initUI(selectGroup);
    if (index > 0) {
      pos3PositionOfShape->show();
    }
  });

  pos3PositionOfShape = new BPos3Input(this, "Position of Shape");
  pos3PositionOfShape->initUI("POS_X", "POS_Y", "POS_Z");
  pos3PositionOfShape->hide();

  stack2->addSubWidget(cbbShape);
  stack2->addSubWidget(bGroupShapeInput);
  stack2->addSubWidget(pos3PositionOfShape);

  this->cbbShape->hide();
  this->bGroupShapeInput->hide();

  bGroupStepAlongLine = new BGroupNumberInput(this);
  bGroupStepAlongLine->initUI(
      makeGroupNumberInputValue("", "",
                                {
                                    NumberInputValue("POS_X", "POS_X", "1", "mm"),
                                    NumberInputValue("POS_Y", "POS_Y", "1", "mm"),
                                    NumberInputValue("POS_Z", "POS_Z", "1", "mm"),
                                    NumberInputValue("DIR_X", "DIR_X", "1", "mm"),
                                    NumberInputValue("DIR_Y", "DIR_Y", "1", "mm"),
                                    NumberInputValue("DIR_Z", "DIR_Z", "1", "mm"),
                                    NumberInputValue("STEP", "STEP", "1", ""),
                                }));
  bGroupStepAlongLine->hide();
  stack2->addSubWidget(bGroupStepAlongLine);

  bGroupPositionInSquare = new BGroupNumberInput(this);
  bGroupPositionInSquare->initUI(
      makeGroupNumberInputValue("", "",
                                {
                                    NumberInputValue("POS_X", "POS_X", "1", "mm"),
                                    NumberInputValue("POS_Y", "POS_Y", "1", "mm"),
                                    NumberInputValue("POS_Z", "POS_Z", "1", "mm"),
                                    NumberInputValue("DIR_X", "DIR_X", "1", "mm"),
                                    NumberInputValue("DIR_Y", "DIR_Y", "1", "mm"),
                                    NumberInputValue("DIR_Z", "DIR_Z", "1", "mm"),
                                    NumberInputValue("HALF_WIDTH​", "HALF_WIDTH​", "1", "mm"),
                                }));
  bGroupPositionInSquare->hide();
  stack2->addSubWidget(bGroupPositionInSquare);

  bGroupPositionInRect = new BGroupNumberInput(this);
  bGroupPositionInRect->initUI(makeGroupNumberInputValue(
      "", "",
      {
          NumberInputValue("POS_X", "POS_X", "1", "mm"),
          NumberInputValue("POS_Y", "POS_Y", "1", "mm"),
          NumberInputValue("POS_Z", "POS_Z", "1", "mm"),
          NumberInputValue("DIR_X", "DIR_X", "1", "mm"),
          NumberInputValue("DIR_Y", "DIR_Y", "1", "mm"),
          NumberInputValue("DIR_Z", "DIR_Z", "1", "mm"),
          NumberInputValue("HALF_WIDTH​_X", "HALF_WIDTH​_X", "1", "mm"),
          NumberInputValue("HALF_WIDTH​_Y", "HALF_WIDTH​_Y", "1", "mm"),
      }));
  bGroupPositionInRect->hide();
  stack2->addSubWidget(bGroupPositionInRect);

  bGroupPositionInDisc = new BGroupNumberInput(this);
  bGroupPositionInDisc->initUI(
      makeGroupNumberInputValue("", "",
                                {
                                    NumberInputValue("POS_X", "POS_X", "1", "mm"),
                                    NumberInputValue("POS_Y", "POS_Y", "1", "mm"),
                                    NumberInputValue("POS_Z", "POS_Z", "1", "mm"),
                                    NumberInputValue("DIR_X", "DIR_X", "1", "mm"),
                                    NumberInputValue("DIR_Y", "DIR_Y", "1", "mm"),
                                    NumberInputValue("DIR_Z", "DIR_Z", "1", "mm"),
                                    NumberInputValue("RADIUS", "RADIUS", "1", "mm"),
                                }));
  bGroupPositionInDisc->hide();
  stack2->addSubWidget(bGroupPositionInDisc);

  bGroupPositionInDiscGauss = new BGroupNumberInput(this);
  bGroupPositionInDiscGauss->initUI(
      makeGroupNumberInputValue("", "",
                                {
                                    NumberInputValue("POS_X", "POS_X", "1", "mm"),
                                    NumberInputValue("POS_Y", "POS_Y", "1", "mm"),
                                    NumberInputValue("POS_Z", "POS_Z", "1", "mm"),
                                    NumberInputValue("DIR_X", "DIR_X", "1", "mm"),
                                    NumberInputValue("DIR_Y", "DIR_Y", "1", "mm"),
                                    NumberInputValue("DIR_Z", "DIR_Z", "1", "mm"),
                                    NumberInputValue("SIGMA", "SIGMA", "1", "mm"),
                                }));
  bGroupPositionInDiscGauss->hide();
  stack2->addSubWidget(bGroupPositionInDiscGauss);

  bGroupPositionInVoxel = new BGroupNumberInput(this);
  bGroupPositionInVoxel->initUI(
      makeGroupNumberInputValue("", "",
                                {
                                    NumberInputValue("POS_X", "POS_X", "1", "mm"),
                                    NumberInputValue("POS_Y", "POS_Y", "1", "mm"),
                                    NumberInputValue("POS_Z", "POS_Z", "1", "mm"),
                                    NumberInputValue("ROT_X", "ROT_X", "1", "mm"),
                                    NumberInputValue("ROT_Y", "ROT_Y", "1", "mm"),
                                    NumberInputValue("ROT_Z", "ROT_Z", "1", "mm"),
                                }));
  bGroupPositionInVoxel->hide();
  stack2->addSubWidget(bGroupPositionInVoxel);

  connectCbbIndexChange(cbbPositionDirection->combobox, [this](int index) {
    this->showPositionDistribution(this->positionDirectionSource[index]);
  });

  // STACK 3 ========================================================
  cbbDirectDistribution = new BComboBox(this, "Direct Distribution");
  group_direction_source = full_group_direction_source();
  for (auto group : group_direction_source) {
    QString label = group.label;
    cbbDirectDistribution->addItem(label);
  }
  cbbDirectDistribution->isTitleInLine = false;
  ds_wg_set_expanding_w(cbbDirectDistribution);
  cbbDirectDistribution->initUI();
  stack3->addSubWidget(cbbDirectDistribution);

  bGroupDirectDistribution = new BGroupNumberInput(this);
  connectCbbIndexChange(cbbDirectDistribution->combobox, [this](int index) {
    this->bGroupDirectDistribution->removeAll();
    GroupNumberInputValue selectGroup = this->group_direction_source[index];
    this->bGroupDirectDistribution->initUI(selectGroup);
  });
  stack3->addSubWidget(bGroupDirectDistribution);

  // STACK 4 ========================================================
  timeDistributionSource.push_back(TIME_DISTRIBUTION::NONE);
  timeDistributionSource.push_back(TIME_DISTRIBUTION::CONSTANT);
  timeDistributionSource.push_back(TIME_DISTRIBUTION::INTERVAL);
  cbbTimeDistribution = new BComboBox(this, "Time Distribution");
  cbbTimeDistribution->isTitleInLine = false;
  for (TIME_DISTRIBUTION time : timeDistributionSource) {
    cbbTimeDistribution->addItem(TIME_DISTRIBUTION_text(time));
  }
  cbbTimeDistribution->initUI();
  stack4->addSubWidget(cbbTimeDistribution);

  numberTimeConstant = new BNumberInput(this, "TIME_CONSTANT", "");
  numberTimeConstant->initUI(true, true);
  numberTimeConstant->hide();
  stack4->addSubWidget(numberTimeConstant);
  bGroupTimeInterval = new BGroupNumberInput(this);
  bGroupTimeInterval->initUI(
      makeGroupNumberInputValue("SOURCE_TIME", "SOURCE_TIME",
                                {
                                    NumberInputValue("TIME_INTERVAL", "TIME_INTERVAL", "1", ""),
                                    NumberInputValue("TIME_OFFSET", "TIME_OFFSET", "1", ""),
                                }));
  bGroupTimeInterval->hide();
  stack4->addSubWidget(bGroupTimeInterval);

  connectCbbIndexChange(cbbTimeDistribution->combobox, [this](int index) {
    this->bGroupTimeInterval->hide();
    this->numberTimeConstant->hide();

    switch (this->timeDistributionSource[index]) {
      case TIME_DISTRIBUTION::CONSTANT:
        this->numberTimeConstant->show();
        break;

      case TIME_DISTRIBUTION::INTERVAL:
        this->bGroupTimeInterval->show();
        break;
    }
  });
}

void BExpertWindow::initOutputLayout() {
  BVStackWidget *leftStack = new BVStackWidget(this);
  BVStackWidget *rightStack = new BVStackWidget(this);
  QGridLayout *grid = new QGridLayout(this);
  outputLayout->setLayout(grid);
  grid->setColumnStretch(0, 3);
  grid->setColumnStretch(1, 1);
  grid->setColumnStretch(2, 1);
  grid->setColumnStretch(3, 3);

  grid->addWidget(leftStack, 0, 1);
  grid->addWidget(rightStack, 0, 2);

  ckPartidePropagating = new QCheckBox("Partide propagating", this);
  ckDoseMap = new QCheckBox("Dose Map", this);
  ckEnergyDositionMap = new QCheckBox("Energy Position Map", this);

  leftStack->addSubWidget(ckPartidePropagating);
  leftStack->addSubWidget(ckDoseMap);
  leftStack->addSubWidget(ckEnergyDositionMap);

  QPushButton *btn_enter = new QPushButton(this);
  ds_wg_set_fixed_h(btn_enter, 40);
  ds_wg_set_expanding_w(btn_enter);
  btn_enter->setText("ENTER");

  connectButtonClicked(btn_enter, [this]() {
    this->session_dir = createSessionDir("SIMPLE");
    createDir(this->session_dir);
    setFullPermissions(this->session_dir);
    cout << endl;
    cout << "SESSION DIR " << this->session_dir.toStdString() << endl;
    auto geomFile = genGeomFile();
    if (geomFile == NULL) {
      return;
    }
    auto inFile = genInFile();
    if (inFile == NULL) {
      return;
    }

    TerminalDialog *ter = new TerminalDialog(this);
    ter->setCurrentDir(this->session_dir);
    ter->addBFile(inFile);
    ter->addBFile(geomFile);
    ter->showInfo();

    ter->addCommand("source " + AppData::gamosDir() + "/config/confgamos.sh");
    // ter->addCommand("cd " + this->session_dir);
    ter->addCommand("gamos " + inFile->fileName);
    ter->exec();
  });
  rightStack->addSubWidget(btn_enter);
}

void BExpertWindow::showPositionDistribution(POSITION_DISTRIBUTION pd) {
  pos3AtPoint->hide();
  cbbShape->hide();
  cbbShape->combobox->setCurrentIndex(0);
  pos3PositionOfShape->hide();
  bGroupShapeInput->hide();
  bGroupStepAlongLine->hide();
  bGroupPositionInSquare->hide();
  bGroupPositionInRect->hide();
  bGroupPositionInDisc->hide();
  bGroupPositionInDiscGauss->hide();
  bGroupPositionInVoxel->hide();

  switch (pd) {
    case POSITION_DISTRIBUTION::AT_POINT:
      pos3AtPoint->show();
      break;

    case POSITION_DISTRIBUTION::USER_DEF_VOLUME:
      this->cbbShape->show();
      this->bGroupShapeInput->show();
      break;

    case POSITION_DISTRIBUTION::USER_DEF_VOLUME_SURFACE:
      this->cbbShape->show();
      this->bGroupShapeInput->show();
      break;

    case POSITION_DISTRIBUTION::STEP_ALONG_LINE:
      bGroupStepAlongLine->show();
      break;

    case POSITION_DISTRIBUTION::IN_SQUARE:
      bGroupPositionInSquare->show();
      break;

    case POSITION_DISTRIBUTION::IN_RECT:
      bGroupPositionInRect->show();
      break;

    case POSITION_DISTRIBUTION::IN_DISC:
      bGroupPositionInDisc->show();
      break;

    case POSITION_DISTRIBUTION::IN_DISC_WITH_GAUSSIAN_DISTRIBUTION:
      bGroupPositionInDiscGauss->show();
      break;

    case POSITION_DISTRIBUTION::IN_VOXEL_PHANTOM_FILE:
      bGroupPositionInVoxel->show();
      break;

    default:
      break;
  }
}

BExpertWindow::BExpertWindow(QWidget *parent) : QTabWidget(parent) {
  phantomLayout = new QWidget(parent);
  sourceLayout = new QWidget(parent);
  outputLayout = new QWidget(parent);

  tabBar()->setDocumentMode(true);
  tabBar()->setExpanding(true);
  this->addTab(phantomLayout, "Phantom");
  this->addTab(sourceLayout, "Source");
  this->addTab(outputLayout, "Output");

  initPhantomLayout();
  initSourceLayout();
  initOutputLayout();
}

BExpertWindow::~BExpertWindow() {}

string BExpertWindow::title() { return "Expert Mode"; }

string BExpertWindow::description() { return ""; }

QWidget *BExpertWindow::self_widget() { return this; }

BFileGen *BExpertWindow::genInFile() { return nullptr; }

BFileGen *BExpertWindow::genGeomFile() { return nullptr; }

// QWidget* buildPhantomLayout() {

// }

QString POSITION_DISTRIBUTION_text(POSITION_DISTRIBUTION value) {
  switch (value) {
    case POSITION_DISTRIBUTION::NONE:
      return "";
    case POSITION_DISTRIBUTION::AT_POINT:
      return "Position at a point";
    case POSITION_DISTRIBUTION::USER_DEF_VOLUME:
      return "Position in a user defined volume";
    case POSITION_DISTRIBUTION::USER_DEF_VOLUME_SURFACE:
      return "Position in a user defined volume surface";
    case POSITION_DISTRIBUTION::STEP_ALONG_LINE:
      return "Position in steps along a line";
    case POSITION_DISTRIBUTION::IN_SQUARE:
      return "Position in a square";
    case POSITION_DISTRIBUTION::IN_RECT:
      return " Position in a rectangle";
    case POSITION_DISTRIBUTION::IN_DISC:
      return "Position in a disc";
    case POSITION_DISTRIBUTION::IN_DISC_WITH_GAUSSIAN_DISTRIBUTION:
      return "Position in a disc with gaussian distribution";
    case POSITION_DISTRIBUTION::IN_VOXEL_PHANTOM_FILE:
      return "Position in the voxels of a phantom file";

    default:
      return "";
  }
  return "";
}

QString TIME_DISTRIBUTION_text(TIME_DISTRIBUTION value) {
  switch (value) {
    case TIME_DISTRIBUTION::NONE:
      return "";
    case TIME_DISTRIBUTION::CONSTANT:
      return "Constant time";

    case TIME_DISTRIBUTION::INTERVAL:
      return "Time changing at constant interval";

    default:
      break;
  }
  return "";
}
