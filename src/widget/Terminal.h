#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include <QProcess>
#include <iostream>

using namespace std;
class Terminal {
 public:
  QProcess proc;
  void setCurrentDir(QString dir);
};
#endif  // __TERMINAL_H__