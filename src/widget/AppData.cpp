#include "AppData.h"

#include "../utils/Helper.h"
QSettings AppDataDialog::setting;

QString AppDataDialog::gamosDir() {
  return AppDataDialog::setting.value("gamosDir", "").toString();
}

QString AppDataDialog::workingDir() {
  return AppDataDialog::setting.value("workingDir", "").toString();
}

void AppDataDialog::setGamosDir(QString dir) {
  AppDataDialog::setting.setValue("gamosDir", dir);
}

void AppDataDialog::setWorkingDir(QString dir) {
  AppDataDialog::setting.setValue("workingDir", dir);
}

AppDataDialog::AppDataDialog(QWidget *parent) : QDialog(parent) {
  setWindowTitle("Application Setting");
  setFixedSize(800, 200);

  grid = new QGridLayout(this);
  setLayout(grid);
  gamosHomePath =
      new BPathInput(this, "GAMOS_HOME_DIR", "Please select Gamos Home");
  gamosHomePath->setPath(AppDataDialog::gamosDir());
  gamosHomePath->onSelected = [this](QString dir) {
    AppDataDialog::setGamosDir(dir);
  };

  workingDirPath =
      new BPathInput(this, "WORKING_DIR", "Please select Working Dir");
  workingDirPath->setPath(AppDataDialog::workingDir());
  workingDirPath->onSelected = [this](QString dir) {
    AppDataDialog::setWorkingDir(dir);
  };

  grid->addWidget(gamosHomePath, 0, 0);
  grid->addWidget(workingDirPath, 1, 0);
  grid->addWidget(v_blankWidget(), 5, 0);
}
