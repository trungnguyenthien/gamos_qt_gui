#include "VrmlViewer.h"

#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoBaseColor.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoSeparator.h>

#include <QDebug>
#include <QFileDialog>
#include <QString>

#include "Helper.h"

void openVrmlViewer(QString file, QWidget *parent) {
  SoInput in;
  SbBool ok = in.openFile(file.toStdString().c_str());
  if (!ok) {
    qDebug() << "openVrmlViewer !ok";
    exit(1);
  }
  // ..and import it.
  SoSeparator *root = SoDB::readAll(&in);
  if (root == NULL) {
    qDebug() << "openVrmlViewer root == NULL";
    exit(1);
  }
  qDebug() << "openVrmlViewer 1";
  root->ref();
  // Use the ExaminerViewer, for a nice interface for 3D model
  // inspection.
  QWidget *mainwin = SoQt::init("", "");
  SoQtExaminerViewer *viewer =
      new SoQtExaminerViewer(mainwin, file.toStdString().c_str());
  viewer->setTitle(file.toStdString().c_str());
  viewer->setSceneGraph(root);
  viewer->show();
}

QString openVrmlFileSelection(QString dir, QWidget *parent) {
  QString filter = "VRML files (*.vrml *.wrl)";
  QString title = "Select VRML file";
  QString selected = QFileDialog::getOpenFileName(parent, title, dir, filter);
  qDebug() << "openVrmlFileSelection FILE: " << selected << endl;
  return selected;
}

void openVrmlViewerDialog(QString dir, QWidget *parent) {
  QString selectFile = openVrmlFileSelection(dir, parent);
  if (selectFile.isEmpty()) {
    return;
  }

  openVrmlViewer(selectFile, parent);
}