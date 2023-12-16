#include "Helper.h"

#include <QDebug>
#include <QFileDialog>
#include <QFont>
#include <QFontDatabase>
#include <QIcon>
#include <QJsonDocument>
#include <QMessageBox>
#include <QPixmap>
#include <QSize>
#include <QSpacerItem>
#include <QWidget>
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
  def.setPointSize(14);
  def.setBold(true);
  return def;
}

QFont font_size(int size) {
  QFont def = font_default();
  def.setPointSize(size);
  def.setBold(true);
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

QLabel *titleLabel(QString title, QWidget *parent) {
  QLabel *label = new QLabel(parent);
  label->setText(title);
  label->setFont(font_subHeader());
  return label;
}

QLabel *normalLabel(QString title, QWidget *parent) {
  QLabel *label = new QLabel(parent);
  label->setText(title);
  label->setFont(font_default());
  return label;
}

QLineEdit *makeNumberEdit(QString hint, float defaultNum, QWidget *parent) {
  QLineEdit *edit = new QLineEdit(parent);
  // Đặt placeholder text
  edit->setPlaceholderText(hint);

  // Tạo một QDoubleValidator để chỉ cho phép nhập giá trị số thực
  QDoubleValidator *validator = new QDoubleValidator(edit);
  validator->setNotation(QDoubleValidator::StandardNotation);
  edit->setValidator(validator);

  // Đặt giá trị mặc định
  edit->setText(QString::number(defaultNum));
  ds_wg_set_fixed_w(edit, 50);
  return edit;
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

void ds_pushButton_buttonStyle(QPushButton *button, int w, int h,
                               QString imageName) {
  // QPixmap pixmap("./resources/img/" + imageName);
  // QIcon ic(pixmap);
  // button->setIcon(ic);
  button->setStyleSheet(
      "QPushButton {"
      "    border-radius: 10px;"        // Adjust the radius for roundness
      "    border: 2px solid #8f8f91;"  // Border color and thickness
      "    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
      "                                  stop:0 #f6f7fa, stop:1 #dadbde);"
      "    min-width: 40px;"  // Minimum width
      "}"
      "QPushButton:pressed {"
      "    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
      "                                  stop:0 #dadbde, stop:1 #f6f7fa);"
      "}");
  // button->setIconSize(QSize(w, h));
  button->setText(imageName);
  button->setFont(font_size(w));
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

void connectCheckBoxToggle(QCheckBox *cb,
                           const std::function<void(bool)> &slot) {
  QObject::connect(cb, &QCheckBox::toggled, slot);
}

void connectRadioButtonToggle(QRadioButton *rb,
                              const std::function<void(bool)> &slot) {
  QObject::connect(rb, &QRadioButton::toggled, slot);
}

QString openDirectory(QWidget *parent, QString startDir, QString defaultDir) {
  return QFileDialog::getExistingDirectory(
      parent, "Select Directory", startDir.isEmpty() ? defaultDir : startDir,
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}

void saveFile(QString outputDir, QString fileName, QStringList lines) {
  // Kết hợp đường dẫn và tên tệp
  QString filePath = outputDir + "/" + fileName;

  // Tạo đối tượng QFile để tạo và ghi tệp
  QFile file(filePath);

  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);

    // Ghi từng dòng từ QStringList vào tệp
    foreach (const QString &line, lines) {
      out << line << "\n";
    }

    file.close();
    qDebug() << "Tệp đã được lưu tại: " << filePath;
  } else {
    qDebug() << "Không thể tạo hoặc ghi tệp.";
  }
}

QString getCurrentDateTime() {
  QDateTime currentDateTime = QDateTime::currentDateTime();
  QString formattedDateTime = currentDateTime.toString("yyyyMMdd_HHmmss");
  return formattedDateTime;
}

float toFloat(QString str) {
  // QString str = "3.14";  // Thay thế bằng chuỗi bạn muốn chuyển đổi
  bool ok;  // Sử dụng để kiểm tra lỗi
  float yourFloat = str.toFloat(&ok);
  if (ok) {
    // Chuyển đổi thành công
    qDebug() << "Giá trị float: " << yourFloat;
  } else {
    // Có lỗi, trả về 0
    qDebug() << "Lỗi: không thể chuyển đổi chuỗi thành float.";
    yourFloat = 0.0f;  // Trả về 0
  }
  return yourFloat;
}

QString createSessionDir(QString name) {
  return AppData::workingDir() + QString("/") + getCurrentDateTime() + "_" +
         name;
}

void replaceRegex(QStringList *source, const QString &regex,
                  const QString &value) {
  if (!source) {
    return;  // Kiểm tra nếu source là NULL
  }

  QRegExp expression(regex);

  for (int i = 0; i < source->size(); ++i) {
    (*source)[i].replace(expression, value);
  }
}

void messageBox(QString message, QWidget *parent = nullptr) {
  // Tạo một hộp thoại thông báo với thông điệp và parent (nếu có).
  QMessageBox msgBox(parent);
  msgBox.setWindowTitle("Thông báo");  // Đặt tiêu đề của hộp thoại
  msgBox.setText(message);             // Đặt nội dung thông điệp

  // Thêm nút OK vào hộp thoại
  msgBox.addButton(QMessageBox::Ok);

  // Hiển thị hộp thoại và chờ người dùng tương tác
  msgBox.exec();
}
