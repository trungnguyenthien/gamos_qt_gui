#include "BDemo2Window.h"

#include <QComboBox>
#include <QVariant>

#include "utils/Helper.h"

BDemo2Window::BDemo2Window(QWidget* parent, int mode) : QWidget(parent) {
  grid = unique_ptr<QGridLayout>(new QGridLayout(this));
  this->mode = mode;
  bool isMultiple = mode == 0;
  this->setLayout(grid.get());
  /// SET UP RADIATION

  if (isMultiple) {
    radiation_source.push_back(RADIATION::NONE);
  }
  radiation_source.push_back(RADIATION::GAMMA);
  radiation_source.push_back(RADIATION::E_NEGATIVE);
  radiation_source.push_back(RADIATION::E_POSITIVE);
  radiation_source.push_back(RADIATION::NEUTRON);
  radiation_source.push_back(RADIATION::ALPHA);

  if (isMultiple) {
    cbbRadiation = unique_ptr<BComboBox>(new BComboBox(this, "The radiation"));
    ds_wg_set_expanding_w(cbbRadiation.get());
    for (auto item : radiation_source) {
      auto text = QString::fromStdString(RADIATION_text(item));
      cbbRadiation.get()->addItem(text);
    }

    grid.get()->addWidget(cbbRadiation.get(), 1, 1, 1, 1);
  } else {
    vector<QString> options;
    for (auto item : radiation_source) {
      options.push_back(QString::fromStdString(RADIATION_text(item)));
    }
    listRadiation = unique_ptr<BListCheckBox>(
        new BListCheckBox(this, "The radiation", true, options));
    grid.get()->addWidget(listRadiation.get(), 1, 1, 1, 1);
  }

  /// SET UP ENERGY
  energy_source.push_back(ENERGY::NONE);
  energy_source.push_back(ENERGY::_1_KEV);
  energy_source.push_back(ENERGY::_10_MEV);
  energy_source.push_back(ENERGY::_100_KEV);
  energy_source.push_back(ENERGY::_1_MEV);
  energy_source.push_back(ENERGY::_10_MEV);
  energy_source.push_back(ENERGY::_100_MEV);
  cbbEnergy = unique_ptr<BComboBox>(new BComboBox(this, "The Energy"));
  // vector<QString> energy_options;
  for (auto item : energy_source) {
    cbbEnergy.get()->addItem(ENERGY_text(item));
    // energy_options.push_back(QString::fromStdString(ENERGY_text(item)));
  }

  grid.get()->addWidget(cbbEnergy.get(), 2, 1, 1, 1);

  matter_source.push_back(MATTER::LEAD);
  matter_source.push_back(MATTER::ALUMIUM);
  matter_source.push_back(MATTER::PAPER);
  matter_source.push_back(MATTER::CONCRETE);
  matter_source.push_back(MATTER::WATER);
  vector<QString> matterOptions;
  for (auto item : matter_source) {
    matterOptions.push_back(MATTER_text(item));
  }

  if (isMultiple) {
    listMatterMutiple =
        new BListCheckText(this, "THE MATTER", "Please input thickness",
                           !isMultiple, matterOptions);
    listMatterMutiple->initUI();
    grid.get()->addWidget(listMatterMutiple, 3, 1, 1, 1);
  } else {
  }

  btn_enter = unique_ptr<QPushButton>(new QPushButton(this));
  // ds_wg_set_expanding_w(btn_enter.get());
  // ds_wg_set_expanding_h(btn_enter.get());
  btn_enter.get()->setText("ENTER");
  grid.get()->addWidget(btn_enter.get(), 4, 1, 1, 1);

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
