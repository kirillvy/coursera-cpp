#pragma once

#include <map>
#include "query.h"

struct BusesForStopResponse {
  // Наполните полями эту структуру
  StopList buses;
  bool empty;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  // Наполните полями эту структуру
  vector<pair<string, StopList>> stops;
  bool empty;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  // Наполните полями эту структуру
  map<string, StopList> stops;
  bool empty;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);

ostream& operator<<(ostream& out, const StopList& list);
