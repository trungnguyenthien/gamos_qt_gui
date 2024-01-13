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
  /// @brief Add widget with custom width
  /// @param widget
  /// @param width <0 (Minimize), 0 (Default, Expanding), >0 (Fixed)
  /// @param fixedHeight
  void addSubWidget(QWidget *widget, int width, int fixedHeight);
  void addSubLayout(QLayout *layout);
  QHBoxLayout *getLayout();
};

#endif