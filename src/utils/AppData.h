#ifndef __APPDATA_H__
#define __APPDATA_H__
#include <QSettings>
#include <QString>

using namespace std;
class AppData {
 private:
  static QSettings setting;

 public:
  static QString gamosDir();
  static QString workingDir();
  static void setGamosDir(QString dir);
  static void setWorkingDir(QString dir);
};

#endif  // __APPDATA_H__