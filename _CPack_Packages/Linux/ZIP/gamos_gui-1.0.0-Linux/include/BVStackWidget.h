#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLayout>

class BVStackWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *mainLayout;

public:
    BVStackWidget(QWidget *parent);
    void addSubWidget(QWidget *widget);
    void addSubLayout(QLayout *layout);
};