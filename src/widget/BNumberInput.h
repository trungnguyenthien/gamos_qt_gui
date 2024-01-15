#ifndef BNumberInput_H
#define BNumberInput_H

#include <QGridLayout>
#include <QLabel>
#include <QWidget>
#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

#include "../model/Types.h"
// #include "BHStackWidget.h"
class BNumberInput : public QWidget {
  Q_OBJECT
private:
public:
  QLabel *label;
  QLineEdit *content;
  QString hint = "";
  NumberInputValue numberInputValue;
  void initUI(bool isTitleInLine, bool isNormalFont);
  BNumberInput(QWidget *parent, const QString &label, const QString &hint);
  BNumberInput(QWidget *parent, NumberInputValue inputValue);
  void turnOnIntValidator(int min, int max);
  void turnOnDoubleValidator(int min, int max, int decimals);
};

#endif