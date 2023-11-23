#ifndef BPhantomTab_H
#define BPhantomTab_H

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

#include "BVStackWidget.h"

class BPhantomTab : public QHBoxLayout {
  Q_OBJECT
 public:
  BVStackWidget *left;
  BVStackWidget *right;
  BPhantomTab(QWidget *parent);
};

#endif