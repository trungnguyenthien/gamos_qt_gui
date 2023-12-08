#include "BMainWindow.h"

#include <QFont>
#include <QPixmap>
#include <QSizePolicy>
#include <iostream>

#include "BChooseModeWindow.h"
#include "BDemo1Window.h"
#include "BDemo2Window.h"
#include "utils/Helper.h"
#include "widget/AppData.h"
#include "widget/BHStackWidget.h"
BMainWindow *BMainWindow::shared = nullptr;

BMainWindow::BMainWindow(QWidget *parent) : BVStackWidget(parent) {
  BMainWindow::shared = this;
  topPlaceHolder = unique_ptr<BHStackWidget>(new BHStackWidget(this));
  backButton = unique_ptr<QPushButton>(new QPushButton(this));
  settingButton = new QPushButton(this);
  topPlaceHolder.get()->addSubWidget(backButton.get());

  addSubWidget(topPlaceHolder.get());
  topPlaceHolder.get()->getLayout()->setContentsMargins(-1, -1, -1, -1);
  titleLabel = unique_ptr<QLabel>(new QLabel());
  // titleLabel.get()->setText("Heelllo");
  titleLabel->setAlignment(Qt::AlignCenter);
  titleLabel->setFont(font_title());
  titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

  topPlaceHolder.get()->getLayout()->addWidget(titleLabel.get(), 1);
  topPlaceHolder.get()->addSubWidget(settingButton);

  ds_pushButton_buttonStyle(backButton.get(), 20, 20, "⬅");
  ds_pushButton_buttonStyle(settingButton, 20, 20, "⋯");

  stackedWidget = unique_ptr<QStackedWidget>(new QStackedWidget(this));
  getLayout()->addWidget(stackedWidget.get(), 1);

  connectButtonClicked(backButton.get(), [this]() { this->pop_back(); });
  connectButtonClicked(settingButton, [this] {
    AppDataDialog *settingDialog = new AppDataDialog(this);
    settingDialog->exec();
  });

  push(new BDemo2Window(this, 0));
  // push(new BDemo1Window(this));
  // push(new BChooseModeWindow(this));
}

void BMainWindow::push(BWindow *wd) {
  windows.push_back(wd);
  BWindow *back = windows.back();

  stackedWidget.get()->addWidget(back->self_widget());
  stackedWidget.get()->setCurrentWidget(back->self_widget());

  titleLabel.get()->setText(back->title().data());
}

void BMainWindow::pop_back() {
  if (windows.empty()) {
    return;
  }
  BWindow *last = windows.back();
  windows.pop_back();
  cout << windows.size() << endl;
  stackedWidget.get()->removeWidget(last->self_widget());
  // delete last->self_widget();
  //   delete last;

  if (windows.empty()) {
    titleLabel.get()->setText("{ BYE BYE ^_^ }");
    backButton.get()->hide();
    return;
  }
  backButton.get()->show();
  BWindow *back = windows.back();
  stackedWidget.get()->setCurrentWidget(back->self_widget());
  titleLabel.get()->setText(back->title().data());
}
