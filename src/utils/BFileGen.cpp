
#include "BFileGen.h"

#include <QFile>
#include <QTextStream>

#include "Helper.h"

BFileGen::BFileGen(QString fileName, QString path) {
  this->fileName = fileName;
  this->path = path;
}

void BFileGen::write() { saveFile(path, fileName, lines); }
