#include "BStyleLabel.h"
#include <QtGui/QFont>

BStyleLabel::BStyleLabel(QWidget *parent, BLabelStyle style, const QString &text) : QLabel(text, parent)
{
    QFont f("Arial", 10, QFont::Normal);
    switch (style)
    {
    case title:
        f.setPointSize(20);
        break;
    case subTitle:
        f.setPointSize(16);
        break;
    case header1:
        f.setBold(true);
        f.setPointSize(14);
        break;
    case header2:
        f.setBold(true);
        f.setPointSize(12);
        break;
    case normal:
        f.setPointSize(10);
        break;
    case error:
        f.setPointSize(10);
        break;
    case notice:
        f.setPointSize(10);
        f.setBold(true);
        break;
    }
    this->setFont(f);
}