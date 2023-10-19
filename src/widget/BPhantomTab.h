#ifndef BPhantomTab_H
#define BPhantomTab_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include "BVStackWidget.h"

class BPhantomTab : public QHBoxLayout
{
    Q_OBJECT
public:
    BVStackWidget *left;
    BVStackWidget *right;
    BPhantomTab(QWidget *parent);
};

#endif