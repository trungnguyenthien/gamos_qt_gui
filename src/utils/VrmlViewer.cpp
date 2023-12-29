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
  qDebug() << "openVrmlViewer FILE: " << file.toStdString().c_str() << endl;
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
  qDebug() << "openVrmlViewer 2";
  // Use the ExaminerViewer, for a nice interface for 3D model
  // inspection.
  QWidget *mainwin = SoQt::init("", "");
  SoQtExaminerViewer *viewer = new SoQtExaminerViewer(mainwin);
  qDebug() << "openVrmlViewer 3";
  viewer->setSceneGraph(root);
  qDebug() << "openVrmlViewer 4";
  viewer->show();
  qDebug() << "openVrmlViewer 5";
}

QString openVrmlFileSelection(QString dir, QWidget *parent) {
  // Mở cửa sổ chọn file với thư mục được open ban đầu là `dir`
  // Chỉ cho chọn file có đuôi .vrml, .wrl
  QString filter = "VRML files (*.vrml *.wrl)";
  QString fileSelected =
      QFileDialog::getOpenFileName(parent, "Select VRML file", dir, filter);
  qDebug() << "openVrmlFileSelection FILE: " << fileSelected << endl;
  // Trả về đường dẫn file mà user chọn.
  // Nếu user không chọn thì trả về empty ""
  return fileSelected;
}

void openVrmlViewerDialog(QString dir, QWidget *parent) {
  QString selectFile = openVrmlFileSelection(dir, parent);
  if (selectFile.isEmpty()) {
    messageBox("Ban chua chon file VRML", parent);
    return;
  }

  openVrmlViewer(selectFile, parent);
}