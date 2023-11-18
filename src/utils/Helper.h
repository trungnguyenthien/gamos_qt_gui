#ifndef __HELPER_H__
#define __HELPER_H__

#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QJsonObject>
#include <QPushButton>
#include <QFont>

QJsonObject loadRootJson(QString file);
QFont font_default();
QFont font_normal();
QFont font_title();
QFont font_header();
QFont font_subHeader();

void ds_pushButton(QPushButton *button, int w, int h, QString imageName);
void ds_pushButton_removeBorder(QPushButton *button);
#endif // __HELPER_H__