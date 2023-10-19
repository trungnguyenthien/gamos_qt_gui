#ifndef BNumberInput_H
#define BNumberInput_H

#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtCore/QString>
#include "BHStackWidget.h"

class BNumberInput : public BHStackWidget
{
    Q_OBJECT
private:
public:
    QLineEdit *content;
    BNumberInput(QWidget *parent, const QString &label, const QString &hint);
    void turnOnIntValidator(int min, int max);
    void turnOnDoubleValidator(int min, int max, int decimals);
};

#endif