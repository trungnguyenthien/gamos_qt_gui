#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include <QGridLayout>
#include <QProcess>
#include <QTextEdit>
#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include <iostream>
using namespace std;
class Terminal : public QWidget {
  Q_OBJECT
 private:
  QGridLayout *grid;
  slots void processFinished(int exitCode, QProcess::ExitStatus exitStatus);

 public:
  QProcess process;
  QTextEdit *terminalOutput;
  Terminal(QWidget *parent);
  void setCurrentDir(QString dir);
};
#endif  // __TERMINAL_H__