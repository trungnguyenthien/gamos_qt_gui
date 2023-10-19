#include "BPhantomTab.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include "BNumberInput.h"

BPhantomTab::BPhantomTab(QWidget *parent) : QHBoxLayout(parent)
{
    left = new QVBoxLayout(parent);
    right = new QVBoxLayout(parent);
    left->setAlignment(Qt::AlignTop);
    right->setAlignment(Qt::AlignTop);

    // Render Left
    QLabel *lbl01 = new QLabel(parent);
    lbl01->setText("1) HELLO WORLD");
    left->addWidget(lbl01);
    lbl01->setStyleSheet("background-color:blue;");

    BNumberInput *number1 = new BNumberInput(parent, "POS_X", "0.00");
    number1->turnOnIntValidator(10, 77);
    left->addWidget(number1);

    // Render Right
    QLabel *lbl02 = new QLabel(parent);
    lbl02->setText("1) HELLO WORLD");
    right->addWidget(lbl02);
    lbl02->setStyleSheet("background-color:yellow;");

    addLayout(left, 1);
    addLayout(right, 1);
}