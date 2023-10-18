#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>

class BPhantomTab : public QHBoxLayout
{
    Q_OBJECT
public:
    QVBoxLayout *left;
    QVBoxLayout *right;
    BPhantomTab(QWidget *parent);
};