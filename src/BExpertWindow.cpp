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
  BVStackWidget *leftStack = new BVStackWidget(this);
  BVStackWidget *rightStack = new BVStackWidget(this);
  QGridLayout *grid = new QGridLayout(this);
  grid->setColumnStretch(0, 1);
  grid->setColumnStretch(1, 1);
  grid->setColumnStretch(2, 1);
  grid->setColumnStretch(3, 1);
  sourceLayout->setLayout(grid);

  grid->addWidget(leftStack, 0, 1);
  grid->addWidget(rightStack, 0, 2);

  cbbParticles = new BComboBox(this, "Particles");
  particles = {PARTICLE::NONE,       PARTICLE::ALPHA, PARTICLE::E_NEGATIVE,
               PARTICLE::E_POSITIVE, PARTICLE::GAMMA, PARTICLE::NEUTRON};
  for (PARTICLE item : particles) {
    cbbParticles->addItem(PARTICLE_text(item));
  }
  cbbParticles->isTitleInLine = true;
  cbbParticles->initUI();
  //   cbbParticles->hide();
  leftStack->addSubWidget(cbbParticles);

  numberEngergy = new BNumberInput(this, NumberInputValue("Energy", "Energy", "1", ""));
  numberEngergy->initUI(true, false);
  leftStack->addSubWidget(numberEngergy);

  cbbDirectDistribution = new BComboBox(this, "Direct Distribution");
  group_direction_source = full_group_direction_source();
  for (auto group : group_direction_source) {
    QString label = group.label;
    cbbDirectDistribution->addItem(label);
  }
  cbbDirectDistribution->isTitleInLine = false;
  ds_wg_set_expanding_w(cbbDirectDistribution);
  cbbDirectDistribution->initUI();
  leftStack->addSubWidget(cbbDirectDistribution);

  bGroupDirectDistribution = new BGroupNumberInput(this);
  connectCbbIndexChange(cbbDirectDistribution->combobox, [this](int index) {
    this->bGroupDirectDistribution->removeAll();
    GroupNumberInputValue selectGroup = this->group_direction_source[index];
    this->bGroupDirectDistribution->initUI(selectGroup);
  });
  leftStack->addSubWidget(bGroupDirectDistribution);

  cbbIsotopes = new BLineEditCompleter(this, "Isotopes");
  cbbIsotopes->isTitleInLine = true;
  cbbIsotopes->setSuggestKeywords(isotope_sources());
  cbbIsotopes->initUI();
  //   cbbIsotopes->hide();
  rightStack->addSubWidget(cbbIsotopes);

  numberActivity = new BNumberInput(this, NumberInputValue("Activity", "Activity", "1", ""));
  numberActivity->initUI(true, false);
  rightStack->addSubWidget(numberActivity);

  distributions.push_back(DISTRIBUTIONTYPE::NONE);
  distributions.push_back(DISTRIBUTIONTYPE::ORGANS);
  distributions.push_back(DISTRIBUTIONTYPE::SHAPES);
  cbbDistributionType = new BComboBox(this, "Distribution");
  for (DISTRIBUTIONTYPE dis : distributions) {
    cbbDistributionType->addItem(DISTRIBUTIONTYPE_text(dis));
  }
  cbbDistributionType->isTitleInLine = true;
  cbbDistributionType->initUI();
  rightStack->addSubWidget(cbbDistributionType);

  organs.push_back(ORGANTYPE::NONE);
  organs.push_back(ORGANTYPE::THYROID);
  organs.push_back(ORGANTYPE::LIVER);
  organs.push_back(ORGANTYPE::HEART);
  organs.push_back(ORGANTYPE::LUNG);
  organs.push_back(ORGANTYPE::BONE);
  organs.push_back(ORGANTYPE::KIDNEY);
  organs.push_back(ORGANTYPE::BRAIN);
  organs.push_back(ORGANTYPE::STOMACH_WALL);
  organs.push_back(ORGANTYPE::PANCREAS);
  organs.push_back(ORGANTYPE::GALLBLADDER);
  cbbOrganType = new BComboBox(this, "Organs");
  for (ORGANTYPE org : organs) {
    cbbOrganType->addItem(ORGANTYPE_text(org));
  }
  cbbOrganType->isTitleInLine = true;
  cbbOrganType->initUI();
  rightStack->addSubWidget(cbbOrganType);

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
    GroupNumberInputValue selectGroup = this->group_shape_source[index];
    this->bGroupShapeInput->initUI(selectGroup);
  });

  rightStack->addSubWidget(cbbShape);
  rightStack->addSubWidget(bGroupShapeInput);

  pathNmImage = new BPathInput(this, "NM Image", "");
  rightStack->addSubWidget(pathNmImage);

  this->cbbOrganType->hide();
  this->cbbShape->hide();
  this->bGroupShapeInput->hide();

  connectCbbIndexChange(cbbDistributionType->combobox, [this](int index) {
    this->cbbOrganType->hide();
    this->cbbShape->hide();
    this->bGroupShapeInput->hide();
    qDebug() << "connectCbbIndexChange(cbbDistributionType->combobox " << index;

    switch (distributions[index]) {
      case DISTRIBUTIONTYPE::ORGANS:
        this->cbbOrganType->show();
        this->cbbOrganType->combobox->setCurrentIndex(0);
        this->cbbShape->combobox->setCurrentIndex(0);
        this->bGroupShapeInput->removeAll();
        break;

      case DISTRIBUTIONTYPE::SHAPES:
        this->cbbShape->show();
        this->bGroupShapeInput->show();
        this->cbbOrganType->combobox->setCurrentIndex(0);
        this->cbbShape->combobox->setCurrentIndex(0);
        this->bGroupShapeInput->removeAll();
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
