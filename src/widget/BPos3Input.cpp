
#include "BPos3Input.h"

#include <QLabel>

#include "../utils/Helper.h"

BPos3Input::BPos3Input(QWidget *parent, QString title) : QWidget(parent) {
  this->title = title;
  grid = new QGridLayout(this);
  grid->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  grid->setSpacing(5);
  grid->setContentsMargins(0, 0, 0, 0);
  grid->setMargin(0);
  ds_wg_set_fixed_w(this, 300);
  setLayout(grid);
}

void BPos3Input::initUI(QString xLabel, QString yLabel, QString zLabel) {
  if (this->title.isEmpty() == false) {
    grid->addWidget(titleLabel(title, this), 0, 0, 1, 6);
  }

  grid->addWidget(normalLabel(xLabel, this), 1, 0);
  px = makeNumberEdit("", 0, this);
  grid->addWidget(px, 1, 1);

  grid->addWidget(normalLabel(yLabel, this), 1, 2);
  py = makeNumberEdit("", 0, this);
  grid->addWidget(py, 1, 3);

  grid->addWidget(normalLabel(zLabel, this), 1, 4);
  pz = makeNumberEdit("", 0, this);
  grid->addWidget(pz, 1, 5);
}

float BPos3Input::valueX() { return toFloat(px->text()); }

float BPos3Input::valueY() { return toFloat(py->text()); }

float BPos3Input::valueZ() { return toFloat(pz->text()); }
