#ifndef B10ITEMMODEL_H
#define B10ITEMMODEL_H

#include <QStandardItemModel>
#include <QString>
#include <vector>

class B10ItemModel : public QStandardItemModel {
  Q_OBJECT

public:
  explicit B10ItemModel(QObject *parent = nullptr);
  void setKeywords(const std::vector<QString> &keywords);

private:
  std::vector<QString> m_keywords;
};

#endif  // B10ITEMMODEL_H
