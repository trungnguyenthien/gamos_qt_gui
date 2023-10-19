#ifndef BPathInput_H
#define BPathInput_H

#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtCore/QString>
#include "BHStackWidget.h"

class BPathInput : public BHStackWidget
{
    Q_OBJECT
private:
    QString *path;
    QLineEdit *lineEdit;

public:
    BPathInput(QWidget *parent, const QString &hint);
    QString getPath();
    void setPath(QString &path);
};

#endif