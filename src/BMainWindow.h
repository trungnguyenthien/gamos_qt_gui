#ifndef __BMAINWINDOWS_H__
#define __BMAINWINDOWS_H__

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include "widget/BVStackWidget.h"
#include <QtWidgets/QLabel>

using namespace std;
class BMainWindow : public BVStackWidget
{
    Q_OBJECT
public:
    QWidget *rootPlaceHolder;
    QWidget *topPlaceHolder;
    QPushButton *backButton;
    QLabel *titleLabel;
    BMainWindow(QWidget *parent);
};

#endif // __BMAINWINDOWS_H__