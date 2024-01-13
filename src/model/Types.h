#ifndef __TYPES_H__
#define __TYPES_H__

#include <QString>
#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;
enum class RADIATION { NONE, GAMMA, E_NEGATIVE, E_POSITIVE, NEUTRON, ALPHA };
string RADIATION_text(RADIATION r);
QString RADIATION_value(RADIATION r);

enum class ENERGY { NONE, _1_KEV, _10_KEV, _100_KEV, _1_MEV, _10_MEV, _100_MEV };

QString ENERGY_text(ENERGY en);
QString ENERGY_unit(ENERGY en);
int ENERGY_value(ENERGY en);
// Tungsten/Vonfram​
enum class MATTER { LEAD, ALUMIUM, PAPER, CONCRETE, WATER, TUNGSEN_VONFRAM };
QString MATTER_text(MATTER mat);
QString MATTER_g4_name(MATTER mat);

enum class PARTICLE { NONE, GAMMA, E_NEGATIVE, E_POSITIVE, NEUTRON, ALPHA };
QString PARTICLE_text(PARTICLE par);
QString PARTICLE_value(PARTICLE par);

enum class GEOM_SITUATION { NONE, SHIELDING, DISTANCE };

QString GEOM_SITUATION_text(GEOM_SITUATION gs);
QString GEOM_SITUATION_value(GEOM_SITUATION gs);

enum class SHIELDING_GEOM { NONE, BOX, TUBE };
QString SHIELDING_GEOM_text(SHIELDING_GEOM sg);
QString SHIELDING_GEOM_value(SHIELDING_GEOM sg);

struct SizeThickness {
  float width, height, depth;
  float thickness;

  SizeThickness(float width, float height, float depth, float thickness)
      : width(width), height(height), depth(depth), thickness(thickness) {}
};

enum class SIZE_THICK_PATTERN { NONE, T3, T4, T5, T6 };
QString SIZE_THICK_PATTERN_text(SIZE_THICK_PATTERN stp);
SizeThickness SIZE_THICK_PATTERN_value(SIZE_THICK_PATTERN stp);

struct SelectionValue {
  QString text;
  QString value;
};

struct NumberInputValue {
  QString label;
  bool isRequired = true;
  QString name;
  QString value;
  QString valueUnit;

  NumberInputValue(QString label, QString name, QString value, QString valueUnit)
      : label(label), name(name), value(value), valueUnit(valueUnit), isRequired(true) {}
};

struct GroupNumberInputValue {
  bool isNone = false;
  QString label;
  QString name;
  vector<NumberInputValue> values;

  GroupNumberInputValue() {
    isNone = true;
    label = "";
    name = "";
  }

  GroupNumberInputValue(QString label, QString name,
                        std::initializer_list<NumberInputValue> values) {
    // GroupNumberInputValue group;
    this->label = label;
    this->isNone = false;
    this->name = name;
    this->values = values;
    // for (const auto value : values) {
    //   this->values.push_back(value);
    // }
  }
};

GroupNumberInputValue makeGroupNumberInputValue(QString label, QString name,
                                                std::initializer_list<NumberInputValue> values);

#endif  // __TYPES_H__