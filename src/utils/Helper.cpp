#include "Helper.h"

#include <QDebug>
#include <QFont>
#include <QFontDatabase>
#include <QIcon>
#include <QJsonDocument>
#include <QPixmap>
#include <QSize>
#include <QSpacerItem>
#include <QtCore/QByteArray>
#include <QtCore/QJsonParseError>

#include "../model/BJsonValue.h"

QJsonObject loadRootJson(QString fileName) {
  QFile inFile(fileName);
  inFile.open(QIODevice::ReadOnly | QIODevice::Text);
  QByteArray data = inFile.readAll();
  inFile.close();
  QJsonParseError errorPtr;
  QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
  if (doc.isNull()) {
    qDebug() << "Parse File: " << fileName << " failed";
    return QJsonObject();
  }
  QJsonObject rootObj = doc.object();
  return rootObj;
}

QFont font_default() {
  QString defaultFontFamily =
      QFontDatabase::systemFont(QFontDatabase::GeneralFont).family();
  return QFont(defaultFontFamily);
}

QFont font_normal() {
  QFont def = font_default();
  def.setPointSize(13);
  return def;
}

QFont font_title() {
  QFont def = font_default();
  def.setPointSize(20);
  return def;
}

QFont font_header() {
  QFont def = font_default();
  def.setPointSize(17);
  def.setBold(true);
  return def;
}

QFont font_subHeader() {
  QFont def = font_default();
  def.setPointSize(15);
  return def;
}

QWidget *h_blankWidget() {
  QWidget *spacer = new QWidget();
  spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  return spacer;
}

QWidget *v_blankWidget() {
  QWidget *spacer = new QWidget();
  spacer->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
  return spacer;
}

QSpacerItem *h_blank() {
  return new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed);
}

QSpacerItem *v_blank() {
  return new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding);
}

void ds_wg_set_expanding_w(QWidget *wid) {
  wid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void ds_wg_set_expading_h(QWidget *wid) {
  wid->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
}

void ds_wg_set_expading_wh(QWidget *wid) {
  wid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void ds_wg_set_fixed_h(QWidget *wid, int value) { wid->setFixedHeight(value); }

void ds_wg_set_fixed_w(QWidget *wid, int value) { wid->setFixedWidth(value); }

void ds_label_align_right(QLabel *lb) { lb->setAlignment(Qt::AlignRight); }

void ds_label_align_left(QLabel *lb) { lb->setAlignment(Qt::AlignLeft); }

void ds_label_align_center(QLabel *lb) { lb->setAlignment(Qt::AlignCenter); }

void ds_pushButton(QPushButton *button, int w, int h, QString imageName) {
  QPixmap pixmap("./resources/img/" + imageName);
  QIcon ic(pixmap);
  button->setIcon(ic);
  button->setIconSize(QSize(w, h));
}

void ds_pushButton_removeBorder(QPushButton *button) {
  button->setStyleSheet("QPushButton { border: none; }");
}

void connectButtonClicked(QPushButton *button,
                          const std::function<void()> &slot) {
  QObject::connect(button, &QPushButton::clicked, slot);
}

void connectCbbIndexChange(QComboBox *cbb,
                           const std::function<void(int)> &slot) {
  QObject::connect(cbb, QOverload<int>::of(&QComboBox::currentIndexChanged),
                   [=](int index) { slot(index); });
}
