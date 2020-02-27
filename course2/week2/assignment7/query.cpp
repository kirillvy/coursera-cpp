#include "query.h"

istream& operator>>(istream& is, Query& q) {
  // Реализуйте эту функцию
  string command;
  is >> command;
  if (command == "NEW_BUS") {
    string bus;
    int stopCount;
    is >> bus >> stopCount;
    StopList busStops(stopCount);
    for (auto& stop: busStops) {
      is >> stop;
    }
    q = {QueryType::NewBus, bus, "", busStops};
  } else if (command == "ALL_BUSES") {
    // AllBuses(buses, stops);
    q = {QueryType::AllBuses};
  } else {
    string arg2;
    is >> arg2;
    if (command == "BUSES_FOR_STOP") {
      q = {QueryType::BusesForStop, "", arg2};
    } else if (command == "STOPS_FOR_BUS") {
      q = {QueryType::StopsForBus, arg2};
    }
  }
  return is;
}