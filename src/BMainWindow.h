#ifndef __BMAINWINDOWS_H__
#define __BMAINWINDOWS_H__

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include "widget/BVStackWidget.h"
#include "widget/BHStackWidget.h"
#include <QtWidgets/QLabel>
#include <memory>
#include <QStackedWidget>
#include "virtual/BWindow.h"
#include <vector>
using namespace std;

class BMainWindow : public BVStackWidget
{
    Q_OBJECT
private:
    vector<unique_ptr<BWindow>> windows;

public:
    // unique_ptr<BWindow> rootWindows;
    unique_ptr<QStackedWidget> stackedWidget;
    unique_ptr<BHStackWidget> topPlaceHolder;
    unique_ptr<QPushButton> backButton;
    unique_ptr<QLabel> titleLabel;

    vector<unique_ptr<BWindow>> getContentWindows();
    void push(BWindow *wd);
    void pop_back();
    BMainWindow(QWidget *parent);
};

BMainWindow *shared_mainwindow;
#endif // __BMAINWINDOWS_H__