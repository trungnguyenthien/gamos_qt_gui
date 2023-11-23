#include "BExpertWindow.h"

#include <QtWidgets/QTabBar>

#include "widget/BPhantomTab.h"

BExpertWindow::BExpertWindow(QWidget *parent) : QTabWidget(parent) {
  phantomLayout = new QWidget(parent);
  sourceLayout = new QWidget(parent);
  outputLayout = new QWidget(parent);

  phantomLayout->setLayout(new BPhantomTab(parent));

  tabBar()->setDocumentMode(true);
  tabBar()->setExpanding(true);
  this->addTab(phantomLayout, "Phantom");
  this->addTab(sourceLayout, "Source");
  this->addTab(outputLayout, "Output");
}

BExpertWindow::~BExpertWindow() {
  delete phantomLayout;
  delete sourceLayout;
  delete outputLayout;
}

string BExpertWindow::title() { return "Expert Mode"; }

string BExpertWindow::description() { return ""; }

QWidget *BExpertWindow::self_widget() { return this; }

// QWidget* buildPhantomLayout() {

// }