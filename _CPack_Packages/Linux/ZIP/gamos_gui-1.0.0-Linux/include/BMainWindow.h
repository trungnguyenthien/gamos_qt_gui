#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

class BMainWindow: public QTabWidget {
    Q_OBJECT
public: 
    QWidget *phantomLayout;
    QWidget *sourceLayout;
    QWidget *outputLayout;
    BMainWindow(QWidget *parent);
};