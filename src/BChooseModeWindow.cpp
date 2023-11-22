#include "BChooseModeWindow.h"

#include "utils/Helper.h"

BChooseModeWindow::BChooseModeWindow(QWidget *parent) : QWidget(parent)
{
    grid = unique_ptr<QGridLayout>(new QGridLayout(this));
    this->setLayout(grid.get());

    lb_welcome = unique_ptr<QLabel>(new QLabel(this));
    lb_welcome.get()->setText("WELCOME");
    lb_welcome.get()->setAlignment(Qt::AlignCenter);
    lb_welcome.get()->setFont(font_header());

    lb_description = unique_ptr<QLabel>(new QLabel(this));
    lb_description.get()->setText("Choose the mode:");
    lb_description.get()->setAlignment(Qt::AlignCenter);
    lb_description.get()->setFont(font_subHeader());

    btn_demo = unique_ptr<QPushButton>(new QPushButton(this));
    btn_demo.get()->setText("Demo");
    ds_wg_set_expading_w(btn_demo.get());
    ds_wg_set_fixed_h(btn_demo.get(), 50);

    btn_simple = unique_ptr<QPushButton>(new QPushButton(this));
    btn_simple.get()->setText("Simple");
    ds_wg_set_expading_w(btn_simple.get());
    ds_wg_set_fixed_h(btn_simple.get(), 50);

    btn_expert = unique_ptr<QPushButton>(new QPushButton(this));
    btn_expert.get()->setText("Expert");
    ds_wg_set_expading_w(btn_expert.get());
    ds_wg_set_fixed_h(btn_expert.get(), 50);

    grid.get()->addWidget(lb_welcome.get(), 0, 1, 1, 3);
    grid.get()->addWidget(lb_description.get(), 1, 1, 1, 3);
    grid.get()->addWidget(h_blankWidget(), 2, 0);
    grid.get()->addWidget(btn_demo.get(), 2, 1);
    grid.get()->addWidget(btn_simple.get(), 2, 2);
    grid.get()->addWidget(btn_expert.get(), 2, 3);
    grid.get()->addWidget(h_blankWidget(), 2, 4);
    grid.get()->addWidget(v_blankWidget(), 3, 0);
}

BChooseModeWindow::~BChooseModeWindow()
{
}

string BChooseModeWindow::title()
{
    return "";
}

string BChooseModeWindow::description()
{
    return "";
}

QWidget *BChooseModeWindow::self_widget()
{
    return this;
}
