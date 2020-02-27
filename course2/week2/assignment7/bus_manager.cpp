#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const StopList& stops) {
  // Реализуйте этот метод  buses[bus] = busStops;
  for (auto stop : stops) {
    busStops[stop].push_back(bus);
  }
  buses[bus] = stops;
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
  // Реализуйте этот метод
  try {
    return {busStops.at(stop)};
  } catch (out_of_range) {
    return {{}, true};
  }
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
  // Реализуйте этот метод
  try {
    vector<pair<string, StopList>> result;
    auto& stops = buses.at(bus);
    for (auto& stop : stops) {
      StopList inters;
      for (auto& inter : busStops.at(stop)) {
        if (inter != bus) {
          inters.push_back(inter);
        }
      }
      // copy_if(busStops.at(stop).begin(), busStops.at(stop).end(), inters, [bus](string cur){ return cur != bus; });
      result.push_back({stop, inters});
    }
    return {result};
  } catch (out_of_range) {
    return {{}, true};
  }
}

AllBusesResponse BusManager::GetAllBuses() const {
  // Реализуйте этот метод
  if (buses.size() == 0) {
    return {{}, true};
  }
  return {buses};
}