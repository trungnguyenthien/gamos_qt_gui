#include "BDemo2Window.h"

#include <QComboBox>
#include <QStringList>
#include <QVariant>

#include "utils/AppData.h"
#include "utils/BFileGen.h"
#include "utils/Helper.h"
#include "widget/BVStackWidget.h"
#include "widget/TerminalDialog.h"

BDemo2Window::BDemo2Window(QWidget *parent, int mode) : QWidget(parent) {
  grid = new QGridLayout(this);
  this->mode = mode;
  this->isMultipleMatter = (mode == 0);
  this->setLayout(grid);
  BVStackWidget *column1 = new BVStackWidget(parent);
  grid->addWidget(column1, 0, 1);

  BVStackWidget *column2 = new BVStackWidget(parent);
  grid->addWidget(column2, 0, 2);

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
  listRadiation->isSingleChoice = isMultipleMatter;
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
  cbbEnergy->isTitleInLine = false;
  cbbEnergy->hide();

  for (auto item : energy_source) {
    cbbEnergy->addItem(ENERGY_text(item));
  }
  cbbEnergy->initUI();
  cbbEnergy->show();
  // grid.get()->addWidget(cbbEnergy, 2, 1, 1, 1);
  column2->addSubWidget(cbbEnergy);

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
  listMatterMutiple->isSingleChoice = !isMultipleMatter;
  listMatterMutiple->allowEdit = true;
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

  btn_enter = new QPushButton(this);
  ds_wg_set_fixed_h(btn_enter, 40);
  btn_enter->setText("ENTER");

  connectButtonClicked(btn_enter, [this]() {
    this->session_dir = createSessionDir("DEMO");
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
  // grid.get()->addWidget(btn_enter.get(), 4, 1, 1, 1);
  column2->addSubWidget(btn_enter);

  grid->addWidget(h_blankWidget(), 4, 0);
  grid->addWidget(v_blankWidget(), 5, 1);
  grid->addWidget(h_blankWidget(), 4, 3);
}

BDemo2Window::~BDemo2Window() {}

string BDemo2Window::title() {
  if (this->mode == 0) {
    return "The interaction of ONE radiation with MULTIPLE matters";
  } else {
    return "The interaction of MULTIPLE radiations with ONE matter";
  }
}

string BDemo2Window::description() { return ""; }

QWidget *BDemo2Window::self_widget() { return this; }

BFileGen *BDemo2Window::genInFile() {
  vector<RADIATION> rads = selectedRadiation();
  ENERGY en = selecedEnergy();

  QStringList lines;
  // if (isMultiple) {
  if (rads.empty()) {
    messageBox("Please select RADIATION", this);
    return NULL;
  }

  if (ENERGY_value(en) == 0) {
    messageBox("Please select ENERGY", this);
    return NULL;
  }

  if (isMultipleMatter) {
    lines << "/tracking/verbose 1";
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
    lines << "/control/execute {GAMOS_HOME}/examples/visVRML2FILE.in";
    lines << "";
    lines << "/run/beamOn 30";

    replaceRegex(&lines, "{RADIATION}", RADIATION_value(rads[0]));
    replaceRegex(&lines, "{ENERGY}", QString::number(ENERGY_value(en)));
    replaceRegex(&lines, "{ENERGY_UNIT}", ENERGY_unit(en));
    replaceRegex(&lines, "{RAD_X}", QString::number(pos3Rad->posX()));
    replaceRegex(&lines, "{RAD_Y}", QString::number(pos3Rad->posY()));
    replaceRegex(&lines, "{RAD_Z}", QString::number(pos3Rad->posZ()));
  } else {
    lines << "/tracking/verbose 1";
    lines << "/gamos/setParam GmGeometryFromText:FileName {FILE_GEOM}";
    lines << "/gamos/geometry GmGeometryFromText";
    lines << "/gamos/physicsList GmEMPhysics";
    lines << "/gamos/physicsList GmEMExtendedPhysics";
    lines << "";
    lines << "/gamos/generator GmGenerator";
    lines << "";
    lines << "/run/initialize";
    int index = 0;
    for (auto pair : rads) {
      auto rad = rads[index];
      QString source_name = "source_" + QString::number(index + 1);
      QStringList radLines;

      radLines << "";
      radLines << "/gamos/generator/addSingleParticleSource {SOURCE_I} "
                  "{RADIATION_I} "
                  "{ENERGY}.*{ENERGY_UNIT}";
      radLines << "/gamos/generator/positionDist {SOURCE_I} "
                  "GmGenerDistPositionPoint "
                  "{RAD_X} {RAD_Y} {RAD_Z}";
      radLines << "/gamos/generator/directionDist {SOURCE_I} "
                  "GmGenerDistDirectionConst "
                  "1. 0. 0.";
      replaceRegex(&radLines, "{RADIATION_I}", RADIATION_value(rad));
      replaceRegex(&radLines, "{SOURCE_I}", source_name);
      replaceRegex(&radLines, "{ENERGY}", QString::number(ENERGY_value(en)));
      replaceRegex(&radLines, "{ENERGY_UNIT}", ENERGY_unit(en));
      replaceRegex(&radLines, "{RAD_X}", QString::number(pos3Rad->posX()));
      replaceRegex(&radLines, "{RAD_Y}", QString::number(pos3Rad->posY()));
      replaceRegex(&radLines, "{RAD_Z}", QString::number(pos3Rad->posZ()));

      lines += radLines;
      index++;
    }

    lines << "";
    lines << "/control/execute {GAMOS_HOME}/examples/visVRML2FILE.in";
    lines << "";
    lines << "/run/beamOn 30";
  }

  replaceRegex(&lines, "{GAMOS_HOME}", AppData::gamosDir());
  replaceRegex(&lines, "{FILE_GEOM}", "my.geom");

  BFileGen *file = new BFileGen();
  file->fileName = "my.in";
  file->lines = lines;
  file->path = session_dir;

  file->write();
  return file;
}

BFileGen *BDemo2Window::genGeomFile() {
  QStringList lines;
  unordered_map<MATTER, QString> mats = selectedMatter();
  if (mats.size() == 0) {
    messageBox("Please select MATTERIAL", this);
    return NULL;
  }
  lines << ":ROTM R00 0. 0. 0.";
  lines << "";
  lines << ":VOLU world BOX 300. 100. 100. G4_AIR";
  lines << ":COLOR world 1. 1. 1. 1.";
  lines << ":VIS world ON";

  auto xmat = QString::number(pos3Mat->posX());
  auto ymat = QString::number(pos3Mat->posY());
  auto zmat = QString::number(pos3Mat->posZ());
  int index = 0;
  for (auto pair : mats) {
    QString matter_name = "my_matter_" + QString::number(++index);
    auto key = pair.first;
    auto thickness = pair.second;
    auto g4matter = MATTER_g4_name(key);
    QStringList matLines;
    matLines << "";
    matLines << ":SOLID {MY_MATER_I_NAME} BOX 100. 50. {THICKNESS_I}";
    matLines << ":VOLU {MY_MATER_I_NAME} {MY_MATER_I_NAME} {G4_MATTER_I}";
    matLines << ":COLOR {MY_MATER_I_NAME} 1. 1. 1.";
    matLines << ":PLACE {MY_MATER_I_NAME} 1 world R00 {X_MAT} {Y_MAT} {Z_MAT}";

    replaceRegex(&matLines, "{MY_MATER_I_NAME}", matter_name);
    replaceRegex(&matLines, "{THICKNESS_I}", thickness);
    replaceRegex(&matLines, "{G4_MATTER_I}", g4matter);
    replaceRegex(&matLines, "{X_MAT}", xmat);
    replaceRegex(&matLines, "{Y_MAT}", ymat);
    replaceRegex(&matLines, "{Z_MAT}", zmat);
    lines += matLines;
  }

  BFileGen *file = new BFileGen();
  file->fileName = "my.geom";
  file->lines = lines;
  file->path = session_dir;
  file->write();
  return file;
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