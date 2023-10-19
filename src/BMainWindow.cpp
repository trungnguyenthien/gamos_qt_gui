#include "BMainWindow.h"
#include <QtWidgets/QTabBar>
#include "widget/BPhantomTab.h"

BMainWindow::BMainWindow(QWidget *parent) : QTabWidget(parent)
{
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

// QWidget* buildPhantomLayout() {

// }