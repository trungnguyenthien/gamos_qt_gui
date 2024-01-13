#include "BChooseModeWindow.h"

#include "BExpertWindow.h"
#include "BSimpleWindow.h"

BChooseModeWindow::BChooseModeWindow(QWidget *parent) : QWidget(parent) {
  grid = new QGridLayout(this);
  this->setLayout(grid);

  lb_welcome = new QLabel(this);
  lb_welcome->setText("WELCOME");
  lb_welcome->setAlignment(Qt::AlignCenter);
  lb_welcome->setFont(font_header());

  lb_description = new QLabel(this);
  lb_description->setText("Choose the mode:");
  lb_description->setAlignment(Qt::AlignCenter);
  lb_description->setFont(font_subHeader());

  btn_demo = new QPushButton(this);
  btn_demo->setText("Demo");
  btn_demo->setFont(font_subHeader());
  ds_wg_set_expanding_w(btn_demo);
  ds_wg_set_fixed_h(btn_demo, 50);
  ds_pushButton_buttonStyle(btn_demo);

  btn_simple = new QPushButton(this);
  btn_simple->setText("Simple");
  btn_simple->setFont(font_subHeader());
  ds_wg_set_expanding_w(btn_simple);
  ds_wg_set_fixed_h(btn_simple, 50);
  ds_pushButton_buttonStyle(btn_simple);

  btn_expert = new QPushButton(this);
  btn_expert->setText("Expert");
  btn_expert->setFont(font_subHeader());
  ds_wg_set_expanding_w(btn_expert);
  ds_wg_set_fixed_h(btn_expert, 50);
  ds_pushButton_buttonStyle(btn_expert);

  grid->addWidget(lb_welcome, 0, 1, 1, 3);
  grid->addWidget(lb_description, 1, 1, 1, 3);
  grid->addWidget(h_blankWidget(), 2, 0);
  grid->addWidget(btn_demo, 2, 1);
  grid->addWidget(btn_simple, 2, 2);
  grid->addWidget(btn_expert, 2, 3);
  grid->addWidget(h_blankWidget(), 2, 4);
  grid->addWidget(v_blankWidget(), 3, 0);
  connectButtonClicked(btn_demo, [this]() { BMainWindow::shared->push(new BDemo1Window(this)); });

  connectButtonClicked(btn_simple,
                       [this]() { BMainWindow::shared->push(new BSimpleWindow(this)); });

  connectButtonClicked(btn_expert,
                       [this]() { BMainWindow::shared->push(new BExpertWindow(this)); });
}

BChooseModeWindow::~BChooseModeWindow() {}

string BChooseModeWindow::title() { return ""; }

string BChooseModeWindow::description() { return ""; }

QWidget *BChooseModeWindow::self_widget() { return this; }
