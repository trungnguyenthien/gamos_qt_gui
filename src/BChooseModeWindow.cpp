#include "BChooseModeWindow.h"
#include <QtWidgets/QLabel>
#include "utils/Helper.h"

BChooseModeWindow::BChooseModeWindow(QWidget *parent) : QWidget(parent)
{
    grid = unique_ptr<QGridLayout>(new QGridLayout(this));
    this->setLayout(grid.get());

    unique_ptr<QLabel> lb_welcome = unique_ptr<QLabel>(new QLabel(this));
    lb_welcome.get()->setText("WELCOME");
    lb_welcome.get()->setFont(font_header());
    unique_ptr<QLabel> lb_description = unique_ptr<QLabel>(new QLabel(this));
    btn_demo = unique_ptr<QPushButton>(new QPushButton(this));
    btn_simple = unique_ptr<QPushButton>(new QPushButton(this));
    btn_expert = unique_ptr<QPushButton>(new QPushButton(this));

    grid.get()->addWidget(lb_welcome.get(), 0, 1, 1, 3);
}
