#ifndef BStyleLabel_H
#define BStyleLabel_H

#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtCore/QString>

enum BLabelStyle
{
    title,
    subTitle,
    header1,
    header2,
    normal,
    error,
    notice
};

class BStyleLabel : public QLabel
{
    Q_OBJECT
private:
public:
    BStyleLabel(QWidget *parent, BLabelStyle style, const QString &text);
};

#endif