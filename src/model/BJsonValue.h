#ifndef __BJSONVALUE_H__
#define __BJSONVALUE_H__

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QList>

enum BJsonValueType
{
    MM,
    CM,
    M,
    EV,
    KEV,
    XYZ_M
};

struct BJsonValue
{
    BJsonValueType type;
    QString value;
    QString label;
    bool isInputable;

    QList<double> getDoubleValues()
    {
        QStringList values = value.split(" ");
        QList<double> output;
        foreach (QString v, values)
        {
            double doubleValue = v.toDouble();
            output.append(doubleValue);
        }
        return output;
    }

    QList<QString> getStringValues()
    {
        QStringList values = value.split(" ");
        QList<QString> output;
        foreach (QString v, values)
        {
            output.append(v);
        }
        return output;
    }
};

#endif // __BJSONVALUE_H__