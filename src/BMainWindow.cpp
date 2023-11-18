#include "BMainWindow.h"
#include "widget/BHStackWidget.h"

BMainWindow::BMainWindow(QWidget *parent) : BVStackWidget(parent)
{
    BHStackWidget *topBar = new BHStackWidget(this);
    backButton = new QPushButton(this);
    topBar->addSubWidget(backButton);

    this->addSubWidget(topBar);
}
