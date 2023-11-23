#ifndef __HELPER_H__
#define __HELPER_H__

#include <QFont>
#include <QPushButton>
#include <QSpacerItem>
#include <QWidget>
#include <QtCore/QFile>
#include <QtCore/QJsonObject>
#include <QtCore/QString>
#include <functional>

QJsonObject loadRootJson(QString file);
QFont font_default();
QFont font_normal();
QFont font_title();
QFont font_header();
QFont font_subHeader();

QWidget *h_blankWidget();
QWidget *v_blankWidget();

QSpacerItem *h_blank();
QSpacerItem *v_blank();
// Widget Util
void ds_wg_set_expanding_w(QWidget *wid);
void ds_wg_set_expanding_h(QWidget *wid);
void ds_wg_set_expanding_wh(QWidget *wid);
void ds_wg_set_fixed_h(QWidget *wid, int value);
void ds_wg_set_fixed_w(QWidget *wid, int value);

void ds_pushButton(QPushButton *button, int w, int h, QString imageName);
void ds_pushButton_removeBorder(QPushButton *button);

void connectButtonClicked(QPushButton *button,
                          const std::function<void()> &slot);
#endif  // __HELPER_H__