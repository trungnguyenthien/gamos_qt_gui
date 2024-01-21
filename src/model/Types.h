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

// G4_Al

// G4_Pb

// G4_W

// G4_AIR

// G4_BONE_COMPACT_ICRU

// G4_BONE_CORTICAL_ICRP

// G4_BRAIN_ICRP

// G4_CONCRETE

// G4_EYE_LENS_ICRP

// G4_GLASS_LEAD

// G4_GLUCOSE

// G4_LUNG_ICRP

// G4_MUSCLE_SKELETAL_ICRP

// G4_MUSCLE_STRIATED_ICRU

// G4_PARAFFIN

// G4_SKIN_ICRP

// G4_TESTES_ICRP

// G4_TISSUE_SOFT_ICRP

// G4_WATER

// G4_GRAPHITE

// ICRU46_Thyroid Adult

// ICRU46_Spleen Adult

// ICRU46_Heart Adult (healthy)

// ICRU46_Kidney Adult

// ICRU46_Liver Adult (healthy)

enum class MATTER {
  LEAD,
  ALUMIUM,
  PAPER,
  CONCRETE,
  WATER,
  TUNGSEN_VONFRAM,
  AIR,
  COMPACT_BONE,
  CORTICAL_BONE,
  BRAIN,
  EYE_LENS,
  GLASS_LEAD,
  GLUCOSE,
  LUNG,
  SKELETAL_MUSCLE,
  STRIATED_MUSCLE,
  PARAFFIN,
  SKIN,
  TESTES,
  GRAPHITE,
  ADULT_THYROID,
  ADULT_SPLEEN,
  ADULT_HEART,
  ADULT_KIDNEY,
  ADULT_LIVER,
  ADULT_OVARY,
  ADULT_PANCREAS
};
QString MATTER_text(MATTER mat);
QString MATTER_g4_name(MATTER mat);

enum class PARTICLE { NONE, GAMMA, E_NEGATIVE, E_POSITIVE, NEUTRON, ALPHA };
QString PARTICLE_text(PARTICLE par);
QString PARTICLE_value(PARTICLE par);

enum class ISOTOPE {
  NONE,
  Am241,
  Ba133,
  Cs137,
  Co57,
  Co60,
  Cs134,
  Na22,
  F18,
  V48,
  Sc44,
  Mn54,
  Co58,
  Sb125,
  I123,
  I125,
  I131,
  Ga68,
  Tc99m,
  Xx999
};
QString ISOTOPE_text(ISOTOPE value);
QString ISOTOPE_value(ISOTOPE value);

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

  NumberInputValue() {
    label = "";
    isRequired = false;
    name = "";
    value = "";
    valueUnit = "";
  }

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

enum class SOURCETYPE { NONE, ISOTOPES, PARTICLES };
QString SOURCETYPE_text(SOURCETYPE value);
QString SOURCETYPE_value(SOURCETYPE value);

vector<GroupNumberInputValue> full_group_geom_source();
#endif  // __TYPES_H__