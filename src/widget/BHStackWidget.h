#ifndef BHStackWidget_H
#define BHStackWidget_H

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>

class BHStackWidget : public QWidget {
  Q_OBJECT
 private:
  QHBoxLayout *mainLayout;

 public:
  BHStackWidget(QWidget *parent);
  void addSubWidget(QWidget *widget);
  void addSubLayout(QLayout *layout);
  QHBoxLayout *getLayout();
};

#endif