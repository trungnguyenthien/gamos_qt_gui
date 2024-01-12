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
      return "Tungsten/Vonfram​";  // TODO: Request G4 NAME

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
}

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
}
