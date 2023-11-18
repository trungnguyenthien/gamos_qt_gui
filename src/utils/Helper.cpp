#include "Helper.h"
#include <QtCore/QByteArray>
#include <QtCore/QJsonParseError>
#include <QJsonDocument>
#include <QDebug>
#include "../model/BJsonValue.h"
#include <QPixmap>
#include <QIcon>
#include <QSize>
#include <QFont>
#include <QFontDatabase>

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

QFont font_default()
{
    QString defaultFontFamily = QFontDatabase::systemFont(QFontDatabase::GeneralFont).family();
    return QFont(defaultFontFamily);
}

QFont font_normal()
{
    QFont def = font_default();
    def.setPointSize(13);
    return def;
}

QFont font_title()
{
    QFont def = font_default();
    def.setPointSize(20);
    return def;
}

QFont font_header()
{
    QFont def = font_default();
    def.setPointSize(16);
    return def;
}

QFont font_subHeader()
{
    QFont def = font_default();
    def.setPointSize(15);
    return def;
}

void ds_pushButton(QPushButton *button, int w, int h, QString imageName)
{
    QPixmap pixmap("./resources/img/" + imageName);
    QIcon ic(pixmap);
    button->setIcon(ic);
    button->setIconSize(QSize(w, h));
}

void ds_pushButton_removeBorder(QPushButton *button)
{
    button->setStyleSheet("QPushButton { border: none; }");
}
