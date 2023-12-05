#include "AppData.h"

QSettings AppData::setting;

QString AppData::gamosDir() {
  return AppData::setting.value("gamosDir", "").toString();
}

QString AppData::workingDir() {
  return AppData::setting.value("workingDir", "").toString();
}

void AppData::setGamosDir(QString dir) {
  AppData::setting.setValue("gamosDir", dir);
}

void AppData::setWorkingDir(QString dir) {
  AppData::setting.setValue("workingDir", dir);
}
