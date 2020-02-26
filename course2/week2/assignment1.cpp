#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <set>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

using StopList = vector<string>;

struct Query {
  QueryType type;
  string bus;
  string stop;
  StopList stops;
};

ostream& operator<<(ostream& out, const StopList& list) {
  for (auto s: list) {
    out << s << ' ';
  }
  return out;
}

istream& operator >> (istream& is, Query& q) {
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

struct BusesForStopResponse {
  // Наполните полями эту структуру
  StopList buses;
  bool empty;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  if (r.empty) {
    os << "No stop";
  } else {
    os << r.buses;
  }
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
  vector<pair<string, StopList>> stops;
  bool empty;
};

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

struct AllBusesResponse {
  // Наполните полями эту структуру
  map<string, StopList> stops;
  bool empty;
};

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

class BusManager {
public:
  void AddBus(const string& bus, const StopList& stops) {
    // Реализуйте этот метод  buses[bus] = busStops;
    for (auto stop : stops) {
      busStops[stop].push_back(bus);
    }
    buses[bus] = stops;
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    try {
      return {busStops.at(stop)};
    } catch (out_of_range) {
      return {{}, true};
    }
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
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

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
    if (buses.size() == 0) {
      return {{}, true};
    }
    return {buses};
  }
private:
  map<string, StopList> buses;
  map<string, StopList> busStops;
};    

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses();
      break;
    }
  }

  return 0;
}
