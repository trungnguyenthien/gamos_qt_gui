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
      return "KeV";
      break;

    case ENERGY::_10_KEV:
      return "KeV";
      break;

    case ENERGY::_100_KEV:
      return "KeV";
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

    default:
      break;
  }
  return "";
}
