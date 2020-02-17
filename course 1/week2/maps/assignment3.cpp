#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
NEW_BUS busstop_countstop1stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
ALL_BUSES — вывести список всех маршрутов с остановками.
 */ 

void PrintList(const vector<string>& list) {
  for (auto s: list) {
    cout << s << ' ';
  }
}

void NewBus(map<string, vector<string>>& stops, map<string, vector<string>>& buses, const string& bus, const vector<string>& busStops) {
  buses[bus] = busStops;
  for (auto stop : busStops) {
    stops[stop].push_back(bus);
  }
}
void BusesForStop(const map<string, vector<string>>& stops, const string& stopName) {
  auto stop = stops.find(stopName);
  if (stop == stops.end()) {
    cout << "No stop";
  } else {
    PrintList(stop->second);
  }
  cout << endl;
}
void BusInterchanges(const vector<string>& stop, const string& bus) {
  bool hasInt = false;
  for (auto currentBus: stop) {
    if (currentBus != bus) {
      hasInt = true;
      cout << currentBus << ' ';
    }
  }
  if (!hasInt) {
    cout << "no interchange";
  }
}

void StopsForBus(const map<string, vector<string>>& stops, const map<string, vector<string>>& buses, const string& busName) {
  auto bus = buses.find(busName);
  if (bus == buses.end()) {
    cout << "No bus" << endl;
  } else {
    for (auto stop: bus->second){
      cout << "Stop " << stop << ": ";
      BusInterchanges(stops.find(stop)->second, busName);
      cout << endl;
    }
  }
}
void AllBuses(const map<string, vector<string>>& stops, map<string, vector<string>>& buses) {
  if (buses.size() == 0) {
    cout << "No buses" << endl;
  } else {
    for (auto [key, value]: stops) {
      cout << "Bus " << key << ": ";
      PrintList(value);
      cout << endl;
    }
  }
}

int main() {
  string command;
  int c;
  cin >> c;
  map<string, vector<string>> stops;
  map<string, vector<string>> buses;

  while(c--) {
    cin >> command;
    if (command == "NEW_BUS") {
      string bus;
      int stopCount;
      cin >> bus >> stopCount;
      vector<string> busStops(stopCount);
      for (auto& stop: busStops) {
        cin >> stop;
      }
      NewBus(stops, buses, bus, busStops);
    } else if (command == "ALL_BUSES") {
      AllBuses(buses, stops);
    } else {
      string arg2;
      cin >> arg2;
      if (command == "BUSES_FOR_STOP") {
        BusesForStop(stops, arg2);
      } else if (command == "STOPS_FOR_BUS") {
        StopsForBus(stops, buses, arg2);
      }
    }

  }

  return 0;
}
