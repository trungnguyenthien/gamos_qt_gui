#include "Helper.h"
#include <QtCore/QByteArray>
#include <QtCore/QJsonParseError>
#include <QJsonDocument>
#include <QDebug>
#include "../model/BJsonValue.h"

QJsonObject loadRootJson(QString fileName)
{
    QFile inFile(fileName);
    inFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = inFile.readAll();
    inFile.close();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull())
    {
        qDebug() << "Parse File: " << fileName << " failed";
        return QJsonObject();
    }
    QJsonObject rootObj = doc.object();
    return rootObj;
}