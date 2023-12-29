#ifndef UTILS_VRMLVIEWER_H_
#define UTILS_VRMLVIEWER_H_

#include <QString>
#include <QWidget>
using namespace std;
void openVrmlViewer(QString file, QWidget *parent);
QString openVrmlFileSelection(QString dir, QWidget *parent);
void openVrmlViewerDialog(QString dir, QWidget *parent);

#endif  // UTILS_VRMLVIEWER_H_