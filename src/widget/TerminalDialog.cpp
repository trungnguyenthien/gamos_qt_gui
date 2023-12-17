#include "TerminalDialog.h"

#include <QByteArray>
#include <QDebug>
#include <QTextCursor>
#include <QTextStream>

#include "../utils/Helper.h"
void TerminalDialog::setCurrentDir(QString dir) {
  currentDir = dir;
  process.setWorkingDirectory(dir);
}

void TerminalDialog::addCommand(QString cmd) { commandLines << cmd; }

void TerminalDialog::addInfo(QString info) { infoLines << info; }

void TerminalDialog::addBFile(BFileGen *bfile) {
  if (bfile == NULL) {
    qDebug() << "addBFile NULL";
    return;
  }

  addInfo("## --------------------------------------------------------- ##");
  addInfo("## ----- " + bfile->path + "/" + bfile->fileName + " ------ ##");

  for (auto line : bfile->lines) {
    addInfo(line);
  }
  addInfo("");
  addInfo("");
}

void TerminalDialog::execute() {
  qDebug() << "---- EXECUTE ----";
  QString joined = commandLines.join(";");
  qDebug() << "COMMAND: " << joined;
  process.start("/bin/bash", QStringList() << "-c" << joined);
  process.waitForFinished();
}

void TerminalDialog::setInfoText(QTextEdit *edit, QStringList lines) {
  edit->clear();
  for (QString line : lines) {
    edit->append(line);
  }
}

void TerminalDialog::showInfo() { setInfoText(infomationText, infoLines); }

TerminalDialog::TerminalDialog(QWidget *parent) : QDialog(parent) {
  setWindowTitle("Application Terminal");
  showMaximized();

  grid = new QGridLayout(this);
  terminalOutput = new QTextEdit(this);
  terminalOutput->setTextColor(QColor("#FFFFFF"));
  terminalOutput->setStyleSheet("QTextEdit { background-color: #000000; }");
  terminalOutput->setReadOnly(true);

  infomationText = new QTextEdit(this);
  infomationText->setTextColor(QColor("#FFFFFF"));
  infomationText->setStyleSheet("QTextEdit { background-color: #0000AA; }");
  infomationText->setReadOnly(true);

  QPushButton *openCurrentDir = new QPushButton(this);
  ds_pushButton_button_text(openCurrentDir, "Open Working Directory");
  connectButtonClicked(openCurrentDir,
                       [this] { openDirectory(this->currentDir); });

  QPushButton *startButton = new QPushButton(this);
  ds_pushButton_button_text(startButton, "Execute");
  connectButtonClicked(startButton, [this] { this->execute(); });

  setLayout(grid);
  grid->addWidget(openCurrentDir, 0, 0);
  grid->addWidget(infomationText, 1, 0);
  grid->addWidget(startButton, 0, 1);
  grid->addWidget(terminalOutput, 1, 1);
  process.setProcessChannelMode(QProcess::MergedChannels);
  QObject::connect(&process, &QProcess::readyReadStandardOutput, [&]() {
    QTextStream in(&process);
    while (!in.atEnd()) {
      QString line = in.readLine();
      terminalOutput->append(line);
      qDebug() << "Log: " << line;
    }

    terminalOutput->append("COMPLETED");
  });
}