#include "AppData.h"
QString AppData::gamosDir() { return AppData::setting.value("gamosDir", ""); }

QString AppData::workingDir() {
  return AppData::setting.value("workingDir", "");
}

void AppData::setGamosDir(QString dir) {}

void AppData::setWorkingDir(QString dir) {}
