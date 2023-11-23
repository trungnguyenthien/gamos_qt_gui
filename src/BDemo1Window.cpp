#include "BDemo1Window.h"

#include "utils/Helper.h"

BDemo1Window::BDemo1Window(QWidget* parent) : QWidget(parent) {
  grid = unique_ptr<QGridLayout>(new QGridLayout(this));
  this->setLayout(grid.get());

  btn_multiple = unique_ptr<QPushButton>(new QPushButton(this));
  btn_multiple.get()->setText(
      "The interaction of\n a radiantion with multiple matters");
  ds_wg_set_expanding_w(btn_multiple.get());
  ds_wg_set_fixed_h(btn_multiple.get(), 50);

  btn_one = unique_ptr<QPushButton>(new QPushButton(this));
  btn_one.get()->setText("The interaction of\n a radiantion with one matters");
  ds_wg_set_expanding_w(btn_one.get());
  ds_wg_set_fixed_h(btn_one.get(), 50);

  grid.get()->addItem(h_blank(), 1, 0, 1, 1);
  grid.get()->addWidget(btn_multiple.get(), 1, 1, 1, 1);
  grid.get()->addWidget(btn_one.get(), 1, 2, 1, 1);
  grid.get()->addItem(h_blank(), 1, 3, 1, 1);
}

BDemo1Window::~BDemo1Window() {}

string BDemo1Window::title() {}

string BDemo1Window::description() {}

QWidget* BDemo1Window::self_widget() {}
