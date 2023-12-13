#ifndef __BCOMBOBOX_H__
#define __BCOMBOBOX_H__

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>
#include <memory>
#include <vector>

using namespace std;
class BComboBox : public QWidget {
  Q_OBJECT
 private:
  QGridLayout *grid;

 public:
  QString title;
  bool isTitleInLine = false;
  void addItem(QString text);
  void initUI();
  int selectedIndex();
  BComboBox(QWidget *parent, QString title);
  QComboBox *combobox;
  QLabel *label;
};

#endif  // __BCOMBOBOX_H__