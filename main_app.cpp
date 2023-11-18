#include <QtWidgets/QApplication>
// #include "src/BExpertWindow.h"
#include "src/BMainWindow.h"

int main(int argc, char **argv)
{
  QApplication a(argc, argv);
  BMainWindow *mainWidget = new BMainWindow(nullptr);
  mainWidget->setWindowTitle("APPLICATION TITLE");
  // widget.adjustSize();
  mainWidget->setWindowState(Qt::WindowMaximized);
  // widget.move(QApplication::desktop()->screen()->rect().center() - widget.rect().center());
  mainWidget->show();
  return a.exec();
}

/*

#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCone.h>

int main(int argc, char** argv)
{
  if (argc < 2) {
    (void)fprintf(stderr, "\n\n\tUsage: %s <modelfilename>\n\n",
                  argc > 0 ? argv[0] : "viewerapp");
    exit(1);
  }
  // Initialize SoQt and Inventor API libraries. This returns a main
  // window to use.
  QWidget* mainwin = SoQt::init(argc, argv, argv[0]);
  // Open the argument file..
  SoInput in;
  SbBool ok = in.openFile(argv[1]);
  if (!ok) { exit(1); }
  // ..and import it.
  SoSeparator * root = SoDB::readAll(&in);
  if (root == NULL) { exit(1); }
  root->ref();
  // Use the ExaminerViewer, for a nice interface for 3D model
  // inspection.
  SoQtExaminerViewer * viewer = new SoQtExaminerViewer(mainwin);
  viewer->setSceneGraph(root);
  viewer->show();
  // Pop up the main window.
  SoQt::show(mainwin);
  // Loop until exit.
  SoQt::mainLoop();
  // Clean up resources.
  delete viewer;
  root->unref();
  return 0;
}

*/