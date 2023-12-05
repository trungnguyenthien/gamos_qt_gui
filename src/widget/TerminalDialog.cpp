#include "TerminalDialog.h"

#include <QByteArray>
#include <QDebug>
#include <QTextStream>
void TerminalDialog::setCurrentDir(QString dir) {
  process.setWorkingDirectory(dir);
}

void TerminalDialog::addCommand(QString cmd) { commandLines << cmd; }

void TerminalDialog::addInfo(QString info) { infoLines << info; }

void TerminalDialog::execute() {
  for (const QString &command : commandLines) {
    process.start(command);
    process.waitForFinished();
  }
}

TerminalDialog::TerminalDialog(QWidget *parent) : QDialog(parent) {
  setWindowTitle("Application Terminal");
  showMaximized();

  grid = new QGridLayout(this);
  terminalOutput = new QTextEdit(this);
  terminalOutput->setTextColor(QColor("#FFFFFF"));
  terminalOutput->setStyleSheet("QTextEdit { background-color: #00AA00; }");
  terminalOutput->setReadOnly(true);

  infomationText = new QTextEdit(this);
  infomationText->setTextColor(QColor("#FFFFFF"));
  infomationText->setStyleSheet("QTextEdit { background-color: #0000AA; }");
  infomationText->setReadOnly(true);

  setLayout(grid);
  grid->addWidget(infomationText, 1, 0);
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