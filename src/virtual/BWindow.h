#ifndef __BWINDOWS_H__
#define __BWINDOWS_H__

#include <string>
#include <QWidget>

using namespace std;

class BWindow : public QWidget
{
public:
    virtual string title() = 0;       // Pure virtual function
    virtual string description() = 0; // Another pure virtual function
};

#endif // __BWINDOWS_H__