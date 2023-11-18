#ifndef __BMAINWINDOWS_H__
#define __BMAINWINDOWS_H__

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include "widget/BVStackWidget.h"
#include "widget/BHStackWidget.h"
#include <QtWidgets/QLabel>
#include <memory>

using namespace std;
class BMainWindow : public BVStackWidget
{
    Q_OBJECT
public:
    unique_ptr<QWidget> rootPlaceHolder;
    unique_ptr<BHStackWidget> topPlaceHolder;
    unique_ptr<QPushButton> backButton;
    unique_ptr<QLabel> titleLabel;
    BMainWindow(QWidget *parent);
};

#endif // __BMAINWINDOWS_H__