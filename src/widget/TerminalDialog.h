#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include <QDialog>
#include <QGridLayout>
#include <QKeyEvent>
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

#include "../utils/BFileGen.h"
using namespace std;
class TerminalDialog : public QDialog {
  Q_OBJECT
private:
  QGridLayout *grid;
  QStringList commandLines;
  QStringList infoLines;
  QString currentDir;
  //  private slots:
  //   void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
  //   void readOutput();

public:
  QProcess process;
  QTextEdit *infomationText;
  QTextEdit *terminalOutput;
  TerminalDialog(QWidget *parent);
  void setCurrentDir(QString dir);
  void addCommand(QString cmd);
  void addInfo(QString info);
  void addBFile(BFileGen *bfile);
  void execute();
  void setInfoText(QTextEdit *edit, QStringList lines);
  void showInfo();

protected:
  void keyPressEvent(QKeyEvent *event) override {
    if (event->key() == Qt::Key_Escape) {
      event->ignore();  // Ignore the Escape key press event
    } else {
      QDialog::keyPressEvent(event);
    }
  }
};
#endif  // __TERMINAL_H__