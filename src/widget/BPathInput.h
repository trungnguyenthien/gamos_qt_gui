#ifndef BPathInput_H
#define BPathInput_H

#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include <functional>

#include "BHStackWidget.h"
using namespace std;
class BPathInput : public BHStackWidget {
  Q_OBJECT
 private:
  QString path;
  QLineEdit *lineEdit;

 public:
  function<void(QString)> onSelected;
  BPathInput(QWidget *parent, QString title, const QString hint);
  QString getPath();
  void setPath(QString path);
};

#endif