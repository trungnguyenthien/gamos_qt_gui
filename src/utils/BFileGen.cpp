
#include "BFileGen.h"

#include <QFile>
#include <QTextStream>

#include "Helper.h"

void BFileGen::write() { saveFile(path, fileName, lines); }
