#ifndef BExpertWindow_H
#define BExpertWindow_H

#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

class BExpertWindow : public QTabWidget
{
    Q_OBJECT
public:
    QWidget *phantomLayout;
    QWidget *sourceLayout;
    QWidget *outputLayout;
    BExpertWindow(QWidget *parent);
};

#endif