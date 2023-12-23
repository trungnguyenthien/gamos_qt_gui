#include "BDemo1Window.h"

#include "BDemo2Window.h"
#include "BMainWindow.h"
#include "utils/Helper.h"

BDemo1Window::BDemo1Window(QWidget *parent) : QWidget(parent) {
  grid = unique_ptr<QGridLayout>(new QGridLayout(this));
  this->setLayout(grid.get());

  btn_multiple = unique_ptr<QPushButton>(new QPushButton(this));
  btn_multiple.get()->setText(
      "The interaction of\nONE radiation \nMULTIPLE matters");
  ds_wg_set_expanding_w(btn_multiple.get());
  ds_wg_set_fixed_h(btn_multiple.get(), 70);
  ds_pushButton_buttonStyle(btn_multiple.get());
  connectButtonClicked(btn_multiple.get(), [this] {
    BMainWindow::shared->push(new BDemo2Window(this, 0));
  });

  btn_one = unique_ptr<QPushButton>(new QPushButton(this));
  btn_one.get()->setText(
      "The interaction of\n MULTIPLE radiations \nONE matter");
  ds_wg_set_expanding_w(btn_one.get());
  ds_wg_set_fixed_h(btn_one.get(), 70);
  ds_pushButton_buttonStyle(btn_one.get());
  connectButtonClicked(btn_one.get(), [this] {
    BMainWindow::shared->push(new BDemo2Window(this, 1));
  });

  grid.get()->addItem(h_blank(), 1, 0, 1, 1);
  grid.get()->addWidget(btn_multiple.get(), 1, 1, 1, 1);
  grid.get()->addWidget(btn_one.get(), 1, 2, 1, 1);
  grid.get()->addItem(h_blank(), 1, 3, 1, 1);
  grid.get()->addWidget(h_blankWidget(), 2, 0, 1, 1);
  grid.get()->addWidget(h_blankWidget(), 3, 0, 1, 1);
}

BDemo1Window::~BDemo1Window() {}

string BDemo1Window::title() { return ""; }

string BDemo1Window::description() { return ""; }

QWidget *BDemo1Window::self_widget() { return this; }
