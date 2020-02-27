#pragma once

#include <vector>
#include <string>
#include <iostream>

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

istream& operator>>(istream& is, Query& q);
