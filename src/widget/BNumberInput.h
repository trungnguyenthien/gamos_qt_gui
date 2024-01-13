#ifndef BNumberInput_H
#define BNumberInput_H

#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

#include "../model/Types.h"
#include "BHStackWidget.h"

class BNumberInput : public BHStackWidget {
  Q_OBJECT
private:
public:
  QLineEdit *content;
  NumberInputValue numberInputValue;
  BNumberInput(QWidget *parent, const QString &label, const QString &hint);
  BNumberInput(QWidget *parent, NumberInputValue inputValue);
  void turnOnIntValidator(int min, int max);
  void turnOnDoubleValidator(int min, int max, int decimals);
};

#endif