#ifndef __HELPER_H__
#define __HELPER_H__

#include <QCheckBox>
#include <QComboBox>
#include <QDateTime>
#include <QFile>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QRegExp>
#include <QSpacerItem>
#include <QTextStream>
#include <QWidget>
#include <QtCore/QFile>
#include <QtCore/QJsonObject>
#include <QtCore/QString>
#include <functional>

#include "AppData.h"
QJsonObject loadRootJson(QString file);
QFont font_default();
QFont font_normal();
QFont font_title();
QFont font_header();
QFont font_subHeader();
QFont font_size(int size);

QWidget *h_blankWidget();
QWidget *v_blankWidget();
QLabel *titleLabel(QString title, QWidget *parent);
QLabel *normalLabel(QString title, QWidget *parent);

QLineEdit *makeNumberEdit(QString hint, float num, QWidget *parent);
QSpacerItem *h_blank();
QSpacerItem *v_blank();
// Widget Util
void ds_wg_set_expanding_w(QWidget *wid);
void ds_wg_set_expanding_h(QWidget *wid);
void ds_wg_set_expanding_wh(QWidget *wid);
void ds_wg_set_fixed_h(QWidget *wid, int value);
void ds_wg_set_fixed_w(QWidget *wid, int value);
void ds_label_align_right(QLabel *label);
void ds_label_align_left(QLabel *label);
void ds_label_align_center(QLabel *label);
void ds_pushButton_buttonStyle(QPushButton *button);
void ds_pushButton_buttonStyle(QPushButton *button, int w, int h,
                               QString imageName);
void ds_pushButton_button_text(QPushButton *button, QString title);
void ds_pushButton_removeBorder(QPushButton *button);

void connectButtonClicked(QPushButton *button,
                          const std::function<void()> &slot);
void connectCbbIndexChange(QComboBox *cbb,
                           const std::function<void(int)> &slot);

void connectCheckBoxToggle(QCheckBox *cb,
                           const std::function<void(bool)> &slot);

void connectRadioButtonToggle(QRadioButton *rb,
                              const std::function<void(bool)> &slot);

QString openDirectory(QWidget *parent, QString startDir, QString defaultDir);

void saveFile(QString outputDir, QString fileName, QStringList lines);

/// Ví dụ, nếu thời gian hiện tại là 15:30:45 vào ngày 10 tháng 12 năm 2023, thì
/// kết quả sẽ là chuỗi "20231210_153045".
QString getCurrentDateTime();

float toFloat(QString str);
QString createSessionDir(QString name);
void replaceRegex(QStringList *source, const QString &regex,
                  const QString &value);

void messageBox(QString message, QWidget *parent);

// return: TRUE: Create dir success, FALSE: Create fail
bool createDir(QString dir);
bool setFullPermissions(const QString &path);
void printStringList(QStringList list);

void openDirectory(QString dir);
#endif  // __HELPER_H__