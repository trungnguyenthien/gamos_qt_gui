#include "BMainWindow.h"
#include "widget/BHStackWidget.h"
#include <QPixmap>
#include <QFont>
#include <QSizePolicy>
#include "utils/Helper.h"
#include "BChooseModeWindow.h"
#include <iostream>
BMainWindow *BMainWindow::shared_mainwindow = nullptr;

BMainWindow::BMainWindow(QWidget *parent) : BVStackWidget(parent)
{
    BMainWindow::shared_mainwindow = this;
    topPlaceHolder = unique_ptr<BHStackWidget>(new BHStackWidget(this));
    backButton = unique_ptr<QPushButton>(new QPushButton(this));
    topPlaceHolder.get()->addSubWidget(backButton.get());

    addSubWidget(topPlaceHolder.get());
    topPlaceHolder.get()->getLayout()->setContentsMargins(-1, -1, -1, -1);
    titleLabel = unique_ptr<QLabel>(new QLabel());
    // titleLabel.get()->setText("Heelllo");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setFont(font_title());
    titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    topPlaceHolder.get()->getLayout()->addWidget(titleLabel.get(), 1);

    ds_pushButton(backButton.get(), 40, 40, "ic-back-button.png");
    ds_pushButton_removeBorder(backButton.get());

    stackedWidget = unique_ptr<QStackedWidget>(new QStackedWidget(this));
    getLayout()->addWidget(stackedWidget.get(), 1);

    QObject::connect(backButton.get(), &QPushButton::clicked, [this]()
                     {
                         this->pop_back();
                         // if (stackedWidget.count() > 0) {
                         //     stackedWidget.removeWidget(stackedWidget.widget(stackedWidget.count() - 1));
                         // }
                     });

    push(new BChooseModeWindow(this));
    // push(new BChooseModeWindow(this));
}

void BMainWindow::push(BWindow *wd)
{
    windows.push_back(wd);
    BWindow *back = windows.back();

    stackedWidget.get()->addWidget(back->self_widget());
    stackedWidget.get()->setCurrentWidget(back->self_widget());

    titleLabel.get()->setText(back->title().data());
}

void BMainWindow::pop_back()
{
    if (windows.empty())
    {
        return;
    }
    BWindow *last = windows.back();
    windows.pop_back();
    cout << windows.size() << endl;
    stackedWidget.get()->removeWidget(last->self_widget());
    // delete last->self_widget();
    // delete last;

    if (windows.empty())
    {
        titleLabel.get()->setText("{EMPTY}");
        return;
    }

    BWindow *back = windows.back();
    stackedWidget.get()->setCurrentWidget(back->self_widget());
    titleLabel.get()->setText(back->title().data());
}
