#pragma once

#include "date.h"

#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

#include <functional>

using namespace std;

using Condition = function<bool (const Date &, const string &)>;

class Database {
public:
  void Add(const Date& date, const string& event);
  void Print(ostream& out) const;
  string Last(const Date date) const;
  vector<string> FindIf(const Condition& predicate) const;
  int RemoveIf(Condition predicate);

private:
  void DeleteEvent(const int index);
  int last = 0;
  map<int, pair<Date, string>> events;
  map<Date, set<int>> dates_events;
  set<pair<Date, string>> events_unique;
};
