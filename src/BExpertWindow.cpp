#include "BExpertWindow.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabBar>

#include "widget/BVStackWidget.h"

void BExpertWindow::initPhantomLayout() {
  BVStackWidget *leftStack = new BVStackWidget(this);
  BVStackWidget *rightStack = new BVStackWidget(this);
  QGridLayout *grid = new QGridLayout(this);
  grid->setColumnStretch(0, 1);  // Cột trái với hệ số co giãn là 2
  grid->setColumnStretch(1, 3);  // Cột phải với hệ số co giãn là 3
  grid->setColumnStretch(2, 3);  // Cột phải với hệ số co giãn là 3
  grid->setColumnStretch(3, 1);  // Cột phải với hệ số co giãn là 3
  phantomLayout->setLayout(grid);

  grid->addWidget(leftStack, 0, 1);
  grid->addWidget(rightStack, 0, 2);

  group_geom_source = full_group_geom_source();

  // GEOMETRY
  cbbGeom = new BComboBox(this, "Mathematical Phantom");
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

  leftStack->addSubWidget(cbbGeom);
  leftStack->addSubWidget(bGroupNumberInput);

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

  pathPhantomVoxel = new BPathInput(this, "PhantomVoxel", "");
  rightStack->addSubWidget(pathPhantomVoxel);
  pathMessPhantom = new BPathInput(this, "MessPhantom", "");
  rightStack->addSubWidget(pathMessPhantom);

  QLabel *phantomPosLabel = new QLabel("Phantom's position", this);
  phantomPosLabel->setFont(font_subHeader());
  rightStack->addSubWidget(phantomPosLabel);

  posXYZ = new BPos3Input(this, "");
  posXYZ->initUI("POS_X", "POS_Y", "POS_Z");
  rightStack->addSubWidget(posXYZ);

  angXYZ = new BPos3Input(this, "");
  angXYZ->initUI("ANG_X", "ANG_Y", "ANG_Z");
  rightStack->addSubWidget(angXYZ);
}

void BExpertWindow::initSourceLayout() {}

void BExpertWindow::initOutputLayout() {}

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

// QWidget* buildPhantomLayout() {

// }