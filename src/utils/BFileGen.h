#ifndef __FILEGEN_H__
#define __FILEGEN_H__
#include <stdarg.h>

#include <QDebug>
#include <QString>
#include <QStringList>

using namespace std;
class BFileGen {
 public:
  BFileGen(QString fileName, QString path);
  QString fileName;
  QStringList lines;
  QString path;
  void write();
};

#endif  // __FILEGEN_H__