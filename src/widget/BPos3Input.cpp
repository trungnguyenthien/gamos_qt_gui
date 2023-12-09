
#include "BPos3Input.h"

#include <QLabel>

#include "../utils/Helper.h"

BPos3Input::BPos3Input(QWidget *parent, QString title) : QWidget(parent) {
  this->title = title;
  grid = new QGridLayout(this);
  setLayout(grid);
}

void BPos3Input::initUI() {
  grid->addWidget(titleLabel(title, this), 0, 0, 1, 6);

  grid->addWidget(normalLabel("POX_X", this), 1, 0);
  px = makeNumberEdit("", 0, this);
  grid->addWidget(px, 1, 1);

  grid->addWidget(normalLabel("POX_Y", this), 1, 2);
  py = makeNumberEdit("", 0, this);
  grid->addWidget(py, 1, 3);

  grid->addWidget(normalLabel("POX_Z", this), 1, 4);
  pz = makeNumberEdit("", 0, this);
  grid->addWidget(pz, 1, 5);

  // grid->addWidget(v_blankWidget(), 999, 0);
}

float BPos3Input::posX() { return toFloat(px->text()); }

float BPos3Input::posY() { return toFloat(py->text()); }

float BPos3Input::posZ() { return toFloat(pz->text()); }
