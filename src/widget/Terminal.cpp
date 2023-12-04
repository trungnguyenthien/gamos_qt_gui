#include "Terminal.h"

#include <QByteArray>
#include <QDebug>
#include <QTextStream>
void Terminal::setCurrentDir(QString dir) { process.setWorkingDirectory(dir); }

void Terminal::addCommand(QString cmd) { commandLines << cmd; }

void Terminal::execute() {
  for (const QString &command : commandLines) {
    process.start(command);
    process.waitForFinished();
  }
}

Terminal::Terminal(QWidget *parent) : QDialog(parent) {
  grid = new QGridLayout(this);
  terminalOutput = new QTextEdit(this);
  setLayout(grid);
  grid->addWidget(terminalOutput, 1, 1);
  process.setProcessChannelMode(QProcess::MergedChannels);
  QObject::connect(&process, &QProcess::readyReadStandardOutput, [&]() {
    QTextStream in(&process);
    while (!in.atEnd()) {
      QString line = in.readLine();
      terminalOutput->append(line);
      terminalOutput->append("\n");
      qDebug() << "Output: " << line;
    }
  });
}
