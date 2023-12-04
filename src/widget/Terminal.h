#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include <QDialog>
#include <QGridLayout>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QTextEdit>
#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include <iostream>
#include <vector>
using namespace std;
class Terminal : public QDialog {
  Q_OBJECT
 private:
  QGridLayout *grid;
  QStringList commandLines;
  //  private slots:
  //   void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
  //   void readOutput();

 public:
  QProcess process;
  QTextEdit *terminalOutput;
  Terminal(QWidget *parent);
  void setCurrentDir(QString dir);
  void addCommand(QString cmd);
  void execute();
};
#endif  // __TERMINAL_H__