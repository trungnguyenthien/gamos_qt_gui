#ifndef __BCHOOSEMODEWINDOWS_H__
#define __BCHOOSEMODEWINDOWS_H__

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <memory>

using namespace std;
class BChooseModeWindow : public QWidget
{
private:
    unique_ptr<QGridLayout> grid;

public:
    unique_ptr<QPushButton> btn_demo;
    unique_ptr<QPushButton> btn_simple;
    unique_ptr<QPushButton> btn_expert;
    BChooseModeWindow(QWidget *parent);
};
#endif // __BCHOOSEMODEWINDOWS_H__