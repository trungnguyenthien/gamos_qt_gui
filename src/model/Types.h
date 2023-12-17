#ifndef __TYPES_H__
#define __TYPES_H__

#include <QString>
#include <iostream>
using namespace std;
enum class RADIATION { NONE, GAMMA, E_NEGATIVE, E_POSITIVE, NEUTRON, ALPHA };
string RADIATION_text(RADIATION r);
QString RADIATION_value(RADIATION r);

enum class ENERGY {
  NONE,
  _1_KEV,
  _10_KEV,
  _100_KEV,
  _1_MEV,
  _10_MEV,
  _100_MEV
};

QString ENERGY_text(ENERGY en);
QString ENERGY_unit(ENERGY en);
int ENERGY_value(ENERGY en);

enum class MATTER { LEAD, ALUMIUM, PAPER, CONCRETE, WATER };
QString MATTER_text(MATTER mat);
QString MATTER_g4_name(MATTER mat);

#endif  // __TYPES_H__