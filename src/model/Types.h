#ifndef __TYPES_H__
#define __TYPES_H__

#include <iostream>
using namespace std;
enum class RADIATION { NONE, GAMMA, E_NEGATIVE, E_POSITIVE, NEUTRON, ALPHA };
string RADIATION_text(RADIATION r);
// energy_source.push_back(ENERGY::NONE);
// energy_source.push_back(ENERGY::_1_KEV);
// energy_source.push_back(ENERGY::_10_MEV);
// energy_source.push_back(ENERGY::_100_KEV);
// energy_source.push_back(ENERGY::_1_MEV);
// energy_source.push_back(ENERGY::_10_MEV);
// energy_source.push_back(ENERGY::_100_MEV);

enum class ENERGY {
  NONE,
  _1_KEV,
  _10_KEV,
  _100_KEV,
  _1_MEV,
  _10_MEV,
  _100_MEV
};

// matter_source.push_back(MATTER::LEAD);
// matter_source.push_back(MATTER::ALUMIUM);
// matter_source.push_back(MATTER::PAPER);
// matter_source.push_back(MATTER::CONCRETE);
// matter_source.push_back(MATTER::WATER);

enum class MATTER { LEAD, ALUMIUM, PAPER, CONCRETE, WATER };

#endif  // __TYPES_H__