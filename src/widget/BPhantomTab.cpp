#include "BPhantomTab.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>

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
    // Render Right
    QLabel *lbl02 = new QLabel(parent);
    lbl02->setText("1) HELLO WORLD");
    right->addWidget(lbl02);
    lbl02->setStyleSheet("background-color:yellow;");

    addLayout(left);
    addLayout(right);
}