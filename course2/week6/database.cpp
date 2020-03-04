#include "database.h"

void Database::Add(const Date &date, const string &event)
{
  events[date].insert(event);
}

bool Database::DeleteEvent(const Date &date, const string &event)
{
  auto cur = events.find(date);

  if (cur != events.end())
  {
    auto &date_events = cur->second;
    int ev = date_events.count(event);
    if (ev != 0)
    {
      date_events.erase(event);
      cout << "Deleted successfully" << endl;
      if (date_events.size() == 0)
      {
        events.erase(date);
      }
      return true;
    }
  }
  cout << "Event not found" << endl;
  return false;
}

int Database::DeleteDate(const Date &date)
{
  auto cur = events.find(date);
  int size = 0;

  if (cur != events.end())
  {
    size = cur->second.size();
    events.erase(date);
  }
  cout << "Deleted " << size << " events" << endl;
  return size;
}

void Database::FindDate(const Date &date) const
{
  auto cur = events.find(date);

  if (cur != events.end())
  {
    for (auto c : cur->second)
    {
      cout << c << endl;
    }
  }
}