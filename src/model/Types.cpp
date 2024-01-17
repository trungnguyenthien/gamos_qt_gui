#include "Types.h"
string RADIATION_text(RADIATION r) {
  switch (r) {
    case RADIATION::NONE:
      return "";
      break;

    case RADIATION::GAMMA:
      return "GAMMA";
      break;

    case RADIATION::E_NEGATIVE:
      return "e-";
      break;

    case RADIATION::E_POSITIVE:
      return "e+";
      break;

    case RADIATION::NEUTRON:
      return "NEUTRON";
      break;

    case RADIATION::ALPHA:
      return "ALPHA";
      break;
  }
  return "";
}

QString RADIATION_value(RADIATION r) {
  //(gamma,e-, e+, neutron, alpha)
  switch (r) {
    case RADIATION::NONE:
      return "";
      break;

    case RADIATION::GAMMA:
      return "gamma";
      break;

    case RADIATION::E_NEGATIVE:
      return "e-";
      break;

    case RADIATION::E_POSITIVE:
      return "e+";
      break;

    case RADIATION::NEUTRON:
      return "neutron";
      break;

    case RADIATION::ALPHA:
      return "alpha";
      break;
  }
  return "";
}

QString ENERGY_text(ENERGY en) {
  switch (en) {
    case ENERGY::_1_KEV:
      return "1 KeV";
      break;

    case ENERGY::_10_KEV:
      return "10 KeV";
      break;

    case ENERGY::_100_KEV:
      return "100 KeV";
      break;

    case ENERGY::_1_MEV:
      return "1 MeV";
      break;

    case ENERGY::_10_MEV:
      return "10 MeV";
      break;

    case ENERGY::_100_MEV:
      return "100 MeV";
      break;

    default:
      break;
  }
  return "";
}

QString ENERGY_unit(ENERGY en) {
  switch (en) {
    case ENERGY::_1_KEV:
      return "keV";
      break;

    case ENERGY::_10_KEV:
      return "keV";
      break;

    case ENERGY::_100_KEV:
      return "keV";
      break;

    case ENERGY::_1_MEV:
      return "MeV";
      break;

    case ENERGY::_10_MEV:
      return "MeV";
      break;

    case ENERGY::_100_MEV:
      return "MeV";
      break;

    default:
      break;
  }
  return "";
}

int ENERGY_value(ENERGY en) {
  switch (en) {
    case ENERGY::_1_KEV:
      return 1;

    case ENERGY::_10_KEV:
      return 10;

    case ENERGY::_100_KEV:
      return 100;

    case ENERGY::_1_MEV:
      return 1;
      break;

    case ENERGY::_10_MEV:
      return 10;

    case ENERGY::_100_MEV:
      return 100;

    default:
      break;
  }
  return 0;
}

QString MATTER_text(MATTER mat) {
  switch (mat) {
    case MATTER::LEAD:
      return "lead";
    case MATTER::ALUMIUM:
      return "alumium";

    case MATTER::PAPER:
      return "paper";

    case MATTER::CONCRETE:
      return "concrete";

    case MATTER::WATER:
      return "water";

    case MATTER::TUNGSEN_VONFRAM:
      return "Tungsten/Vonfram​";

    default:
      break;
  }
  return "";
}

QString MATTER_g4_name(MATTER mat) {
  switch (mat) {
    case MATTER::LEAD:
      return "G4_Pb";

    case MATTER::ALUMIUM:
      return "G4_Al";

    case MATTER::PAPER:
      return "G4_TISSUE_SOFT_ICRP";

    case MATTER::CONCRETE:
      return "G4_CONCRETE";

    case MATTER::WATER:
      return "G4_WATER";

    case MATTER::TUNGSEN_VONFRAM:
      return "G4_W";

    case MATTER::AIR:
      return "G4_AIR";

    case MATTER::COMPACT_BONE:
      return "G4_BONE_COMPACT_ICRU";

    case MATTER::CORTICAL_BONE:
      return "G4_BONE_CORTICAL_ICRP";

    case MATTER::BRAIN:
      return "G4_BRAIN_ICRP";

    case MATTER::EYE_LENS:
      return "G4_EYE_LENS_ICRP";

    case MATTER::GLASS_LEAD:
      return "G4_GLASS_LEAD";

    case MATTER::GLUCOSE:
      return "G4_GLUCOSE";

    case MATTER::LUNG:
      return "G4_LUNG_ICRP";

    case MATTER::SKELETAL_MUSCLE:
      return "G4_MUSCLE_SKELETAL_ICRP";

    case MATTER::STRIATED_MUSCLE:
      return "G4_MUSCLE_STRIATED_ICRU";

    case MATTER::PARAFFIN:
      return "G4_PARAFFIN";

    case MATTER::SKIN:
      return "G4_SKIN_ICRP";

    case MATTER::TESTES:
      return "G4_TESTES_ICRP";

    case MATTER::GRAPHITE:
      return "G4_GRAPHITE";

    case MATTER::ADULT_THYROID:
      return "ICRU46_Thyroid";

    case MATTER::ADULT_SPLEEN:
      return "ICRU46_Spleen";

    case MATTER::ADULT_HEART:
      return "ICRU46_Heart";

    case MATTER::ADULT_KIDNEY:
      return "ICRU46_Kidney";

    case MATTER::ADULT_LIVER:
      return "ICRU46_Liver";

    case MATTER::ADULT_OVARY:
      return "ICRU46_Ovary";

    case MATTER::ADULT_PANCREAS:
      return "ICRU46_Pancreas";

    default:
      break;
  }
  return "";
}

QString PARTICLE_text(PARTICLE par) {
  switch (par) {
    case PARTICLE::NONE:
      return "";
      break;

    case PARTICLE::GAMMA:
      return "GAMMA";
      break;

    case PARTICLE::E_NEGATIVE:
      return "e-";
      break;

    case PARTICLE::E_POSITIVE:
      return "e+";
      break;

    case PARTICLE::NEUTRON:
      return "NEUTRON";
      break;

    case PARTICLE::ALPHA:
      return "ALPHA";
      break;
  }
  return "";
}

QString PARTICLE_value(PARTICLE par) {
  switch (par) {
    case PARTICLE::NONE:
      return "";
      break;

    case PARTICLE::GAMMA:
      return "gamma";
      break;

    case PARTICLE::E_NEGATIVE:
      return "e-";
      break;

    case PARTICLE::E_POSITIVE:
      return "e+";
      break;

    case PARTICLE::NEUTRON:
      return "neutron";
      break;

    case PARTICLE::ALPHA:
      return "alpha";
      break;
  }
  return "";
}

QString ISOTOPE_text(ISOTOPE value) {
  // NONE,

  switch (value) {
    case ISOTOPE::Am241:
      return "Am241";
    case ISOTOPE::Ba133:
      return "Ba133";
    case ISOTOPE::Cs137:
      return "Cs137";
    case ISOTOPE::Co57:
      return "Co57";
    case ISOTOPE::Co60:
      return "Co60";
    case ISOTOPE::Cs134:
      return "Cs134";
    case ISOTOPE::Na22:
      return "Na22";
    case ISOTOPE::F18:
      return "F18";
    case ISOTOPE::V48:
      return "V48";
    case ISOTOPE::Sc44:
      return "Sc44";
    case ISOTOPE::Mn54:
      return "Mn54";
    case ISOTOPE::Co58:
      return "Co58";
    case ISOTOPE::Sb125:
      return "Sb125";
    case ISOTOPE::I123:
      return "I123";
    case ISOTOPE::I125:
      return "I125";
    case ISOTOPE::I131:
      return "I131";
    case ISOTOPE::Ga68:
      return "Ga68";
    case ISOTOPE::Tc99m:
      return "Tc99m";
    case ISOTOPE::Xx999:
      return "Xx999";
  }
  return "";
}

QString ISOTOPE_value(ISOTOPE value) { return ISOTOPE_text(value); }

QString GEOM_SITUATION_text(GEOM_SITUATION gs) {
  switch (gs) {
    case GEOM_SITUATION::NONE:
      return "";
    case GEOM_SITUATION::SHIELDING:
      return "shielding";
    case GEOM_SITUATION::DISTANCE:
      return "";
    default:
      return "";
  }
  return "";
}

QString GEOM_SITUATION_value(GEOM_SITUATION gs) {
  switch (gs) {
    case GEOM_SITUATION::NONE:
      return "";
    case GEOM_SITUATION::SHIELDING:
      return "shielding";
    case GEOM_SITUATION::DISTANCE:
      return "";
    default:
      return "";
  }
  return "";
}

QString SHIELDING_GEOM_text(SHIELDING_GEOM sg) {
  switch (sg) {
    case SHIELDING_GEOM::NONE:
      return "";
    case SHIELDING_GEOM::BOX:
      return "box";
    case SHIELDING_GEOM::TUBE:
      return "tube";
    default:
      return "";
  }
  return "";
}

QString SHIELDING_GEOM_value(SHIELDING_GEOM sg) {
  switch (sg) {
    case SHIELDING_GEOM::NONE:
      return "";
    case SHIELDING_GEOM::BOX:
      return "box";
    case SHIELDING_GEOM::TUBE:
      return "tube";
    default:
      return "";
  }
  return "";
}

QString SIZE_THICK_PATTERN_text(SIZE_THICK_PATTERN stp) {
  switch (stp) {
    case SIZE_THICK_PATTERN::T3:
      return "250 x 210 x 120 mm​ \n Thickness: 3mm  ​";
    case SIZE_THICK_PATTERN::T4:
      return "250 x 210 x 120 mm​ \n Thickness: 4mm  ​";
    case SIZE_THICK_PATTERN::T5:
      return "250 x 210 x 120 mm​ \n Thickness: 5mm  ​";
    case SIZE_THICK_PATTERN::T6:
      return "250 x 210 x 120 mm​ \n Thickness: 6mm  ​";
    default:
      return "";
  }
  return "";
}

SizeThickness SIZE_THICK_PATTERN_value(SIZE_THICK_PATTERN stp) {
  switch (stp) {
    case SIZE_THICK_PATTERN::T3:
      return SizeThickness(250, 210, 120, 3);
    case SIZE_THICK_PATTERN::T4:
      return SizeThickness(250, 210, 120, 4);
    case SIZE_THICK_PATTERN::T5:
      return SizeThickness(250, 210, 120, 5);
    case SIZE_THICK_PATTERN::T6:
      return SizeThickness(250, 210, 120, 6);
    default:
      return SizeThickness(0, 0, 0, 0);
  }
  return SizeThickness(0, 0, 0, 0);
}

GroupNumberInputValue makeGroupNumberInputValue(QString label, QString name,
                                                std::initializer_list<NumberInputValue> values) {
  GroupNumberInputValue group;
  group.label = label;
  group.name = name;
  group.values = values;
  // for (const auto value : values) {
  //   group.values.push_back(value);
  // }
  return group;
}

QString SOURCETYPE_text(SOURCETYPE value) {
  switch (value) {
    case SOURCETYPE::ISOTOPES:
      return "ISOTOPES";
    case SOURCETYPE::PARTICLES:
      return "PARTICLES";
    default:
      return "";
  }
  return "";
}

QString SOURCETYPE_value(SOURCETYPE value) {
  switch (value) {
    case SOURCETYPE::ISOTOPES:
      return "ISOTOPES";
    case SOURCETYPE::PARTICLES:
      return "PARTICLES";
    default:
      return "";
  }
  return "";
}