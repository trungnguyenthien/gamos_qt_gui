#ifndef __BWINDOWS_H__
#define __BWINDOWS_H__

#include <QWidget>
#include <string>

using namespace std;

class BWindow {
 public:
  virtual string title() = 0;        // Pure virtual function
  virtual string description() = 0;  // Another pure virtual function
  virtual QWidget *self_widget() = 0;
};

#endif  // __BWINDOWS_H__