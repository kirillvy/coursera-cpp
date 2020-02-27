#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  if (r.empty) {
    os << "No stop";
  } else {
    os << r.buses;
  }
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  if (r.empty) {
    os << "No bus" << endl;
  } else {
    for (auto [stop, buses]: r.stops) {
      os << "Stop " << stop << ": ";
      if (buses.size() == 0) {
        os << "no interchange";
      } else {
        os << buses;
      }
      os << endl;
    }
  }
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  if (r.empty) {
    os << "No buses" << endl;
  } else {
    for (auto [bus, stops]: r.stops) {
      os << "Bus " << bus << ": " << stops << endl;
    }
  }
  return os;
}


ostream& operator<<(ostream& out, const StopList& list) {
  for (auto s: list) {
    out << s << ' ';
  }
  return out;
}