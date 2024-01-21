#ifndef __BPOS3INPUT_H__
#define __BPOS3INPUT_H__

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>
#include <memory>
using namespace std;
class BPos3Input : public QWidget {
  Q_OBJECT
private:
  QGridLayout *grid;

public:
  QLineEdit *px, *py, *pz;
  float valueX();
  float valueY();
  float valueZ();
  QString title;
  void initUI(QString xLabel, QString yLabel, QString zLabel);
  BPos3Input(QWidget *parent, QString title);
  QLabel *label;
};

#endif  // __BPOS3INPUT_H__