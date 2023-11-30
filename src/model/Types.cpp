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
