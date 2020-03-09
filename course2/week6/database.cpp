#include "database.h"


int Database::findIntersection(set<int>& date, set<int>& event) const {
  vector<int> result = {-1};
  set_intersection(begin(date), end(date), begin(event), end(event), begin(result));
  return result[0];
}


void Database::Add(const Date &date, const string &event)
{
  try {
    int res = findIntersection(
      dates_events.at(date),
      events_dates.at(event)
      );
    if (res != -1) {
      return;
    }
  } catch (out_of_range) {}
  dates_events[date].insert(last);
  events_dates[event].insert(last);
  events[last] = make_pair(date, event);
  ++last;
}

int Database::RemoveIf(Condition predicate) {
  int total = 0;
  for (auto [index, entry] : events) {
    const auto [date, event] = entry;
    if (predicate(date, event)) {
      dates_events[date].erase(index);
      events_dates[event].erase(index);
      events.erase(index);
      ++total;
    }
  }
  return total;
}

vector<string> Database::FindIf(const Condition& predicate) const {
  vector<string> result;
  stringstream temp;
  for (auto [index, event] : events) {
    auto [date, desc] = event;

    if (predicate(date, desc)) {
      temp << date << ' ' << desc;
      result.push_back(temp.str());
      temp.clear();
    }
  }
  return result;
}

void Database::Print(ostream& out) const {
  for (auto [key, val] : dates_events) {
    for (auto i : val) {
      auto [date, event] = events.at(i);
      out << date << ' ' << event << endl;
    }
  }
}

string Database::Last(const Date date) const {
  int index = -1;
  for (auto c : dates_events) {
    if (c.first <= date) {
      index = *c.second.rbegin();
    } else {
      break;
    }
  }
  if (index == -1)
    return "No entries";
  stringstream temp;
  auto [rdate, desc] = events.at(index);
  temp << rdate << ' ' << desc;
  return temp.str();
}
