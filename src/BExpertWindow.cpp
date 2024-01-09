#include "BExpertWindow.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabBar>

#include "widget/BVStackWidget.h"

void BExpertWindow::initPhantomLayout() {
  BVStackWidget *leftStack = new BVStackWidget(this);
  BVStackWidget *rightStack = new BVStackWidget(this);
  QGridLayout *grid = new QGridLayout(this);
  grid->setColumnStretch(0, 1);  // Cột trái với hệ số co giãn là 2
  grid->setColumnStretch(1, 2);  // Cột phải với hệ số co giãn là 3
  grid->setColumnStretch(2, 3);  // Cột phải với hệ số co giãn là 3
  grid->setColumnStretch(3, 1);  // Cột phải với hệ số co giãn là 3
  phantomLayout->setLayout(grid);

  grid->addWidget(leftStack, 0, 2);
  grid->addWidget(rightStack, 0, 3);
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
}

BExpertWindow::~BExpertWindow() {}

string BExpertWindow::title() { return "Expert Mode"; }

string BExpertWindow::description() { return ""; }

QWidget *BExpertWindow::self_widget() { return this; }

// QWidget* buildPhantomLayout() {

// }