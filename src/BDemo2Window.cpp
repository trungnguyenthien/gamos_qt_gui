#include "BDemo1Window.h"
#include "utils/Helper.h"

BDemo2Window::BDemo2Window(QWidget* parent, int mode) {
  grid = unique_ptr<QGridLayout>(new QGridLayout(this));
  this->setLayout(grid.get());
}

BDemo2Window::~BDemo2Window() {}

string BDemo2Window::title() { return ""; }

string BDemo2Window::description() { return ""; }

QWidget* BDemo2Window::self_widget() { return this; }
