#include "BSimpleWindow.h"

#include <QPushButton>
#include <initializer_list>

#include "utils/Helper.h"
#include "widget/TerminalDialog.h"

BFileGen *BSimpleWindow::genInFile() { return nullptr; }

BFileGen *BSimpleWindow::genGeomFile() { return nullptr; }

BSimpleWindow::BSimpleWindow(QWidget *parent) : QTabWidget(parent) {
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

string BSimpleWindow::title() { return "SIMPLE MODE"; }

string BSimpleWindow::description() { return ""; }

QWidget *BSimpleWindow::self_widget() { return this; }

void BSimpleWindow::initPhantomLayout() {
  BVStackWidget *leftStack = new BVStackWidget(this);
  BVStackWidget *rightStack = new BVStackWidget(this);
  QGridLayout *grid = new QGridLayout(this);
  phantomLayout->setLayout(grid);
  grid->setColumnStretch(0, 1);
  grid->setColumnStretch(1, 1);
  grid->setColumnStretch(2, 2);
  grid->setColumnStretch(3, 1);

  grid->addWidget(leftStack, 0, 1);
  grid->addWidget(rightStack, 0, 2);

  matter_source.push_back(MATTER::LEAD);
  matter_source.push_back(MATTER::ALUMIUM);
  matter_source.push_back(MATTER::PAPER);
  matter_source.push_back(MATTER::CONCRETE);
  matter_source.push_back(MATTER::WATER);
  matter_source.push_back(MATTER::AIR);
  matter_source.push_back(MATTER::COMPACT_BONE);
  matter_source.push_back(MATTER::CORTICAL_BONE);
  matter_source.push_back(MATTER::BRAIN);
  matter_source.push_back(MATTER::EYE_LENS);
  matter_source.push_back(MATTER::GLASS_LEAD);
  matter_source.push_back(MATTER::GLUCOSE);
  matter_source.push_back(MATTER::LUNG);
  matter_source.push_back(MATTER::SKELETAL_MUSCLE);
  matter_source.push_back(MATTER::STRIATED_MUSCLE);
  matter_source.push_back(MATTER::PARAFFIN);
  matter_source.push_back(MATTER::SKIN);
  matter_source.push_back(MATTER::TESTES);
  matter_source.push_back(MATTER::GRAPHITE);
  matter_source.push_back(MATTER::ADULT_THYROID);
  matter_source.push_back(MATTER::ADULT_SPLEEN);
  matter_source.push_back(MATTER::ADULT_HEART);
  matter_source.push_back(MATTER::ADULT_KIDNEY);
  matter_source.push_back(MATTER::ADULT_LIVER);
  matter_source.push_back(MATTER::ADULT_OVARY);
  matter_source.push_back(MATTER::ADULT_PANCREAS);

  cbbMatter = new BComboBox(this, "Matterial");
  for (MATTER matter : matter_source) {
    cbbMatter->addItem(MATTER_text(matter));
  }
  cbbMatter->isTitleInLine = false;
  cbbMatter->initUI();
  ds_wg_set_expanding_w(cbbMatter);
  leftStack->addSubWidget(cbbMatter);

  group_geom_source = full_group_geom_source();

  cbbGeom = new BComboBox(this, "Geometry");
  for (auto group : group_geom_source) {
    QString label = group.label;
    cbbGeom->addItem(label);
  }
  cbbGeom->isTitleInLine = false;
  ds_wg_set_expanding_w(cbbGeom);
  cbbGeom->initUI();

  bGroupNumberInput = new BGroupNumberInput(this);
  connectCbbIndexChange(cbbGeom->combobox, [this](int index) {
    this->bGroupNumberInput->removeAll();
    GroupNumberInputValue selectGroup = this->group_geom_source[index];
    this->bGroupNumberInput->initUI(selectGroup);
  });

  rightStack->addSubWidget(cbbGeom);
  rightStack->addSubWidget(bGroupNumberInput);
}

void BSimpleWindow::initSourceLayout() {
  BVStackWidget *leftStack = new BVStackWidget(this);
  BVStackWidget *rightStack = new BVStackWidget(this);
  QGridLayout *grid = new QGridLayout(this);
  sourceLayout->setLayout(grid);
  grid->setColumnStretch(0, 1);
  grid->setColumnStretch(1, 1);
  grid->setColumnStretch(2, 1);
  grid->setColumnStretch(3, 1);

  //   ds_wg_set_fixed_w(leftStack, 400);
  //   ds_wg_set_fixed_w(rightStack, 400);
  //   grid->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  //   grid->setSpacing(5);
  //   grid->setContentsMargins(0, 0, 0, 0);
  //   grid->setMargin(0);

  grid->addWidget(leftStack, 0, 1);
  grid->addWidget(rightStack, 0, 2);

  cbbSourceTypes = new BComboBox(this, "Sources");
  sourceTypes = {SOURCETYPE::NONE, SOURCETYPE::ISOTOPES, SOURCETYPE::PARTICLES};
  for (SOURCETYPE type : sourceTypes) {
    cbbSourceTypes->addItem(SOURCETYPE_text(type));
  }
  cbbSourceTypes->isTitleInLine = false;
  cbbSourceTypes->initUI();
  ds_wg_set_expanding_w(cbbSourceTypes);
  leftStack->addSubWidget(cbbSourceTypes);

  cbbIsotopes = new BLineEditCompleter(this, "Isotopes");
  cbbIsotopes->isTitleInLine = true;
  cbbIsotopes->setSuggestKeywords(isotope_sources());
  cbbIsotopes->initUI();
  //   cbbIsotopes->hide();
  leftStack->addSubWidget(cbbIsotopes);

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

  posXYZ = new BPos3Input(this, "Position");
  posXYZ->initUI("POS_X", "POS_Y", "POS_Z");
  //   pos3Rad->hide();
  rightStack->addSubWidget(posXYZ);

  cbbDirectDistribution = new BComboBox(this, "Direct Distribution");
  group_direction_source = full_group_direction_source();
  for (auto group : group_direction_source) {
    QString label = group.label;
    cbbDirectDistribution->addItem(label);
  }
  cbbDirectDistribution->isTitleInLine = false;
  ds_wg_set_expanding_w(cbbDirectDistribution);
  cbbDirectDistribution->initUI();
  rightStack->addSubWidget(cbbDirectDistribution);

  bGroupDirectDistribution = new BGroupNumberInput(this);
  connectCbbIndexChange(cbbDirectDistribution->combobox, [this](int index) {
    this->bGroupDirectDistribution->removeAll();
    GroupNumberInputValue selectGroup = this->group_direction_source[index];
    this->bGroupDirectDistribution->initUI(selectGroup);
  });
  rightStack->addSubWidget(bGroupDirectDistribution);

  leftStack->addSubWidget(numberEngergy);
  cbbSourceTypes->combobox->setCurrentIndex(0);
  this->cbbIsotopes->hide();
  this->cbbParticles->hide();
  this->numberEngergy->hide();

  connectCbbIndexChange(cbbSourceTypes->combobox, [this](int index) {
    this->cbbIsotopes->hide();
    this->cbbParticles->hide();
    this->numberEngergy->hide();
    SOURCETYPE selectSource = this->sourceTypes[index];
    switch (selectSource) {
      case SOURCETYPE::NONE:
        break;

      case SOURCETYPE::ISOTOPES:
        this->cbbIsotopes->show();
        this->cbbIsotopes->lineEdit->setText("");
        break;

      case SOURCETYPE::PARTICLES:
        this->cbbParticles->show();
        this->cbbParticles->combobox->setCurrentIndex(0);
        this->numberEngergy->show();
        this->numberEngergy->content->setText("");
        break;
    }
  });
}

void BSimpleWindow::initOutputLayout() {
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
