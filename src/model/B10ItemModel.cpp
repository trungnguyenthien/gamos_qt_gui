#include "B10ItemModel.h"

#include <QStandardItem>

B10ItemModel::B10ItemModel(QObject *parent) : QStandardItemModel(parent) {
  setRowCount(10);     // Số lượng hàng
  setColumnCount(10);  // Số lượng cột
}

void B10ItemModel::setKeywords(const std::vector<QString> &keywords) {
  m_keywords = keywords;

  // Xóa dữ liệu hiện tại
  removeRows(0, rowCount());

  // Thêm dữ liệu mới
  for (const QString &keyword : m_keywords) {
    QList<QStandardItem *> rowItems;
    for (int i = 0; i < 10; ++i) {
      rowItems.append(new QStandardItem(keyword));  // Thêm cùng từ khóa vào mỗi cột
    }
    appendRow(rowItems);
  }
}
