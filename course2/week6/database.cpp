#include "database.h"

void Database::Add(const Date &date, const string &event)
{
  auto ev = make_pair(date, event);
  if(events_unique.count(ev)) {
    return;
  }
  dates_events[date].insert(last);
  events_unique.insert(ev);
  events[last] = make_pair(date, event);
  ++last;
}

int Database::RemoveIf(Condition predicate) {
  int total = 0;
  for (auto it = begin(events); it != end(events);) {
      auto index = it->first;
      auto entry = it->second;
      const auto [date, event] = entry;
      if (predicate(date, event)) {
        dates_events[date].erase(index);
        if (dates_events[date].size() == 0)
          dates_events.erase(date);
        events_unique.erase(entry);
        it = events.erase(it);
        ++total;
      } else {
        ++it;
      }
  }
  return total;
}


// int Database::RemoveIf(Condition predicate) {
//   int total = 0;
//   map<int, pair<Date, string>> indices;
//   for (auto [index, entry] : events) {

//       const auto [date, event] = entry;
//       if (predicate(date, event)) {
//         indices[index] = entry;
//         ++total;
//       }
//   }
  
//   for (auto [index, entry] : indices) {

//       const auto [date, event] = entry;
//       dates_events[date].erase(index);
//       if (dates_events[date].size() == 0)
//         dates_events.erase(date);
//       events_unique.erase(entry);
//       events.erase(index);
//   }
//   return total;
// }

vector<string> Database::FindIf(const Condition& predicate) const {
  vector<string> result;
  for (auto [key, val] : dates_events) {
    for (auto i : val) {
      auto [date, event] = events.at(i);
      if (predicate(date, event)) {
          result.push_back(
            PrintDate(date) + " " + event
          );
      }
    }
  }
  return result;
}

void Database::Print(ostream& out) const {
  for (auto [key, val] : dates_events) {
    for (auto i : val) {
        auto [date, event] = events.at(i);
        out << PrintDate(date) << ' ' << event << endl;
    }
  }
}

string Database::Last(const Date date) const {
  if (dates_events.size() == 0) {
    return "No entries";
  }
  auto it = dates_events.lower_bound(date);
  if (it == end(dates_events) || (
    it->first > date &&
    it != begin(dates_events)
  )) {
    --it;
  }
  if (it->first <= date) {
    auto res = *it;
    auto index = *res.second.rbegin();
    auto [rdate, desc] = events.at(index);
    return PrintDate(rdate) + " " + desc;
  } else {
    return "No entries";
  }

}
