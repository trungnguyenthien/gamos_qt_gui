#ifndef __APPDATA_H__
#define __APPDATA_H__
#include <QDialog>
#include <QGridLayout>
#include <QSettings>
#include <QString>
#include <QWidget>

#include "BPathInput.h"
using namespace std;
class AppDataDialog : public QDialog {
  Q_OBJECT
 private:
  QGridLayout *grid;
  BPathInput *gamosHomePath;
  BPathInput *workingDirPath;
  static QSettings setting;

 public:
  AppDataDialog(QWidget *parent);
  static QString gamosDir();
  static QString workingDir();
  static void setGamosDir(QString dir);
  static void setWorkingDir(QString dir);
};

#endif  // __APPDATA_H__