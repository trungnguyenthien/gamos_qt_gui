#ifndef BVStackWidget_H
#define BVStackWidget_H

#include <QtWidgets/QLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class BVStackWidget : public QWidget {
  Q_OBJECT
 private:
  QVBoxLayout *mainLayout;

 public:
  BVStackWidget(QWidget *parent);
  void addSubWidget(QWidget *widget);
  void addSubLayout(QLayout *layout);
  QVBoxLayout *getLayout();
};

#endif