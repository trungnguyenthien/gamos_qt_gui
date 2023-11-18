#include "BMainWindow.h"
#include "widget/BHStackWidget.h"
#include <QPixmap>
#include <QFont>
#include <QSizePolicy>
#include "utils/Helper.h"
#include "BChooseModeWindow.h"

BMainWindow::BMainWindow(QWidget *parent) : BVStackWidget(parent)
{
    topPlaceHolder = unique_ptr<BHStackWidget>(new BHStackWidget(this));
    backButton = unique_ptr<QPushButton>(new QPushButton(this));
    topPlaceHolder.get()->addSubWidget(backButton.get());

    addSubWidget(topPlaceHolder.get());
    topPlaceHolder.get()->getLayout()->setContentsMargins(-1, -1, -1, -1);
    titleLabel = unique_ptr<QLabel>(new QLabel(this));
    titleLabel.get()->setText("Heelllo");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setFont(font_title());
    // titleLabel->setStyleSheet("QLabel{margin-left: 10px; border-radius: 25px; background: red; color: #4A0C46;}");
    titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    topPlaceHolder.get()->getLayout()->addWidget(titleLabel.get(), 1);

    ds_pushButton(backButton.get(), 40, 40, "ic-back-button.png");
    ds_pushButton_removeBorder(backButton.get());

    stackedWidget = unique_ptr<QStackedWidget>(new QStackedWidget(this));
    this->addSubWidget(stackedWidget.get());

    unique_ptr<QWidget> rootWindows = unique_ptr<QWidget>(new BChooseModeWindow(this));
    stackedWidget.get()->addWidget(rootWindows.get());

    stackedWidget.get()->setCurrentWidget(rootWindows.get());
}
