#ifndef BStyleLabel_H
#define BStyleLabel_H

#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

enum BLabelStyle { title, subTitle, header1, header2, normal, error, notice };

class BStyleLabel : public QLabel {
  Q_OBJECT
 private:
 public:
  BStyleLabel(QWidget *parent, BLabelStyle style, const QString &text);
};

#endif