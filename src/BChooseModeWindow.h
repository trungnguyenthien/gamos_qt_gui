#ifndef __BCHOOSEMODEWINDOWS_H__
#define __BCHOOSEMODEWINDOWS_H__

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <memory>
#include "virtual/BWindow.h"

using namespace std;
class BChooseModeWindow : public QWidget, public BWindow
{
private:
    unique_ptr<QGridLayout> grid;

public:
    unique_ptr<QLabel> lb_description;
    unique_ptr<QLabel> lb_welcome;
    unique_ptr<QPushButton> btn_demo;
    unique_ptr<QPushButton> btn_simple;
    unique_ptr<QPushButton> btn_expert;
    BChooseModeWindow(QWidget *parent);
    ~BChooseModeWindow();

    // Virtual class BWindow
    string title() override;
    string description() override;
    QWidget *self_widget() override;
};
#endif // __BCHOOSEMODEWINDOWS_H__