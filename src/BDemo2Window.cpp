#include "BDemo2Window.h"

#include <QComboBox>
#include <QStringList>
#include <QVariant>

#include "utils/AppData.h"
#include "utils/BFileGen.h"
#include "utils/Helper.h"
#include "widget/BVStackWidget.h"
#include "widget/TerminalDialog.h"

BDemo2Window::BDemo2Window(QWidget* parent, int mode) : QWidget(parent) {
  grid = unique_ptr<QGridLayout>(new QGridLayout(this));
  this->mode = mode;
  this->isMultiple = (mode == 0);
  this->setLayout(grid.get());
  BVStackWidget* column1 = new BVStackWidget(parent);
  grid.get()->addWidget(column1, 0, 1);

  BVStackWidget* column2 = new BVStackWidget(parent);
  grid.get()->addWidget(column2, 0, 2);

  /// SET UP RADIATION
  radiation_source.push_back(RADIATION::GAMMA);
  radiation_source.push_back(RADIATION::E_NEGATIVE);
  radiation_source.push_back(RADIATION::E_POSITIVE);
  radiation_source.push_back(RADIATION::NEUTRON);
  radiation_source.push_back(RADIATION::ALPHA);
  vector<QString> radiationOptions;
  for (auto item : radiation_source) {
    radiationOptions.push_back(QString::fromStdString(RADIATION_text(item)));
  }
  listRadiation = new BListCheckBox(this);
  listRadiation->numberColumn = 3;
  listRadiation->isSingleChoice = isMultiple;
  listRadiation->title = "The Radiation";
  listRadiation->options = radiationOptions;
  listRadiation->initUI();
  // grid.get()->addWidget(listRadiation, 1, 1, 1, 1);
  column1->addSubWidget(listRadiation);

  /// SET UP ENERGY
  energy_source.push_back(ENERGY::NONE);
  energy_source.push_back(ENERGY::_1_KEV);
  energy_source.push_back(ENERGY::_10_MEV);
  energy_source.push_back(ENERGY::_100_KEV);
  energy_source.push_back(ENERGY::_1_MEV);
  energy_source.push_back(ENERGY::_10_MEV);
  energy_source.push_back(ENERGY::_100_MEV);
  cbbEnergy = new BComboBox(this, "The Energy");
  cbbEnergy->isTitleInLine = true;
  cbbEnergy->hide();

  for (auto item : energy_source) {
    cbbEnergy->addItem(ENERGY_text(item));
  }
  cbbEnergy->initUI();
  if (isMultiple) {
    cbbEnergy->show();
    // grid.get()->addWidget(cbbEnergy, 2, 1, 1, 1);
    column1->addSubWidget(cbbEnergy);
  }

  /// SET UP MATTER
  matter_source.push_back(MATTER::LEAD);
  matter_source.push_back(MATTER::ALUMIUM);
  matter_source.push_back(MATTER::PAPER);
  matter_source.push_back(MATTER::CONCRETE);
  matter_source.push_back(MATTER::WATER);
  vector<QString> matterOptions;
  for (auto item : matter_source) {
    matterOptions.push_back(MATTER_text(item));
  }

  listMatterMutiple = new BListCheckText(this);
  listMatterMutiple->title = "The Matter";
  listMatterMutiple->hintEdit = "Input thickness";
  listMatterMutiple->isSingleChoice = !isMultiple;
  listMatterMutiple->allowEdit = isMultiple;
  listMatterMutiple->defaultValue = "1";
  listMatterMutiple->options = matterOptions;
  listMatterMutiple->initUI();
  // grid.get()->addWidget(listMatterMutiple, 3, 1, 1, 1);
  column1->addSubWidget(listMatterMutiple);

  pos3Rad = new BPos3Input(this, "Position of Radiation");
  pos3Rad->initUI();
  column2->addSubWidget(pos3Rad);

  pos3Mat = new BPos3Input(this, "Position of Matterial");
  pos3Mat->initUI();
  column2->addSubWidget(pos3Mat);

  btn_enter = unique_ptr<QPushButton>(new QPushButton(this));
  // ds_wg_set_expanding_w(btn_enter.get());
  // ds_wg_set_expanding_h(btn_enter.get());
  btn_enter.get()->setText("ENTER");
  connectButtonClicked(btn_enter.get(), [this]() {
    this->session_dir = createSessionDir("DEMO");
    auto geomFile = genGeomFile();
    auto inFile = genInFile();
    // TerminalDialog* ter = new TerminalDialog(this);
    // ter->exec();
  });
  // grid.get()->addWidget(btn_enter.get(), 4, 1, 1, 1);
  column1->addSubWidget(btn_enter.get());

  grid.get()->addWidget(h_blankWidget(), 4, 0);
  grid.get()->addWidget(v_blankWidget(), 5, 1);
  grid.get()->addWidget(h_blankWidget(), 4, 3);
}

BDemo2Window::~BDemo2Window() {}

string BDemo2Window::title() {
  if (this->mode == 0) {
    return "The interaction of a radiantion with multiple matters";
  } else {
    return "The interaction of a radiantion with one matters";
  }
}

string BDemo2Window::description() { return ""; }

QWidget* BDemo2Window::self_widget() { return this; }

BFileGen BDemo2Window::genInFile() {
  QStringList lines;
  if (isMultiple) {
  } else {
  }
  if (isM) lines << "/tracking/verbose 1";
  lines << "/gamos/setParam GmGeometryFromText:FileName {FILE_GEOM}";
  lines << "/gamos/geometry GmGeometryFromText";
  lines << "/gamos/physicsList GmEMPhysics";
  lines << "/gamos/physicsList GmEMExtendedPhysics";
  lines << "";
  lines << "/gamos/generator GmGenerator";
  lines << "";
  lines << "/run/initialize";
  lines << "";
  lines << "/gamos/generator/addSingleParticleSource source1 {RADIATION} "
           "{ENERGY}.*{ENERGY_UNIT}";
  lines << "/gamos/generator/positionDist source1 GmGenerDistPositionPoint "
           "{RAD_X} {RAD_Y} {RAD_Z}";
  lines << "/gamos/generator/directionDist source1 GmGenerDistDirectionConst "
           "1. 0. 0.";
  lines << "";
  lines << "#/control/execute ../../../examples/visOGLIX.in";
  lines << "/control/execute ../../../examples/visVRML2FILE.in";
  lines << "#/control/execute ../../../examples/visDAWNFILE.in";
  lines << "";
  lines << "/run/beamOn 30";

  replaceRegex(&lines, "{FILE_GEOM}", "myGeom.geom");
}

BFileGen BDemo2Window::genGeomFile() {
  QStringList lines;
  if (isMultiple) {
  } else {
  }
  lines << ":ROTM R00 0. 0. 0.";
  lines << "";
  lines << ":VOLU world BOX 300. 100. 100. G4_AIR";
  lines << ":COLOR world 1. 1. 1. 1.";
  lines << ":VIS world ON";
  lines << "";
  lines << ":SOLID my_matter BOX 100. 50. {THICKNESS_I}";
  lines << ":VOLU my_matter my_matter {G4_MATTER_I}";
  lines << ":COLOR my_matter 1. 1. 1.";
  lines << ":PLACE my_matter 1 world R00 {X_MAT} {Y_MAT} {Z_MAT}";
}

vector<RADIATION> BDemo2Window::selectedRadiation() {
  vector<RADIATION> out;
  auto selectedIndices = listRadiation->selectedIndices();
  for (auto index : selectedIndices) {
    out.push_back(radiation_source[index]);
  }
  return out;
}

ENERGY BDemo2Window::selecedEnergy() {
  auto index = cbbEnergy->selectedIndex();
  return energy_source[index];
}

unordered_map<MATTER, QString> BDemo2Window::selectedMatter() {
  unordered_map<MATTER, QString> out;
  auto selectedValues = listMatterMutiple->selectedValue();
  for (const auto kv : selectedValues) {
    auto key = kv.first;
    auto value = kv.second;
    out[matter_source[key]] = value;
  }
  return out;
}