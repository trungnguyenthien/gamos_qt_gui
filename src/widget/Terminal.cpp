#include "Terminal.h"
void Terminal::setCurrentDir(QString dir) { proc.setWorkingDirectory(dir); }

Terminal::Terminal(QWidget *parent) : QWidget(parent) {
  grid = new QGridLayout(this);
  terminalOutput = new QTextEdit(this);
  setLayout(grid);

  // connect(startButton, &QPushButton::clicked, this, &MyWidget::startProcess);
  connect(&process, &QProcess::readyReadStandardOutput, this,
          &Terminal::readOutput);
  connect(&process, &QProcess::finished, this, &Terminal::processFinished);
}

private slots:
void Terminal::processFinished(int exitCode, QProcess::ExitStatus exitStatus) {}
