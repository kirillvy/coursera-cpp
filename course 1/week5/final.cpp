#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
class Date
{
public:
  Date() {}
  Date(const int &new_year, const int &new_month, const int &new_day)
  {
    if (new_month < 1 || new_month > 12)
    {
      string err = "Month value is invalid: " + to_string(new_month);
      throw runtime_error(err);
    }

    if (new_day < 1 || new_day > 31)
    {
      string err = "Day value is invalid: " + to_string(new_day);
      throw runtime_error(err);
    }
    year = new_year;
    month = new_month;
    day = new_day;
  }
  int GetYear() const
  {
    return year;
  }
  int GetMonth() const
  {
    return month;
  }
  int GetDay() const
  {
    return day;
  }

private:
  int year;
  int month;
  int day;
};

ostream &operator<<(ostream &ostr, const Date &d)
{
  char divider = '-';
  int year = d.GetYear();
  if (year < 0) {
    ostr << divider;
    year = year * -1;
  }
  ostr << setw(4) << setfill('0') << year
    << divider << setw(2) << setfill('0') << d.GetMonth()
    << divider << setw(2) << setfill('0') << d.GetDay();
  return ostr;
}

istream &operator>>(istream &istr, Date &d)
{
  char divider = '-';
  int new_year, new_month;
  int new_day = -999999;
  char div1, div2;
  string input;
  getline(istr, input, ' ');
  if (input.find_first_not_of("0123456789+-") != input.npos || input.size() == 0)
  {
    throw runtime_error("Wrong date format: " + input);
  }
  stringstream date(input);
  date >> new_year >> div1 >> new_month >> div2 >> new_day;
  if (div1 == divider && div2 == divider && new_day != -999999)
  {
    d = {new_year, new_month, new_day};
  } else {
    throw runtime_error("Wrong date format: " + input);
  }

  return istr;
}

bool operator<(const Date &lhs, const Date &rhs)
{
  int rYear = rhs.GetYear();
  int lYear = lhs.GetYear();
  if (lYear < rYear)
  {
    return true;
  }
  else if (lYear > rYear)
  {
    return false;
  }
  int lMonth = lhs.GetMonth();
  int rMonth = rhs.GetMonth();
  if (lMonth < rMonth)
  {
    return true;
  }
  else if (lMonth > rMonth)
  {
    return false;
  }
  return lhs.GetDay() < rhs.GetDay();
}

class Database
{
public:
  void AddEvent(const Date &date, const string &event)
  {
    events[date].insert(event);
  }
  bool DeleteEvent(const Date &date, const string &event)
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
  int DeleteDate(const Date &date)
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

  void Find(const Date &date) const
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

  void Print() const
  {
    for (auto [date, evs] : events)
    {
      for (auto e : evs)
      {
        cout << date << ' ' << e << endl;
      }
    }
  }

private:
  map<Date, set<string>> events;
};

void ProcessDate(Date &d)
{
}

int main()
{
  Date inDate;
  Database db;
  string cmd, event;
  string command;
  while (getline(cin, command))
  {
    cmd = "";
    event = "";
    stringstream cur(command);
    getline(cur, cmd, ' ');
    if (cmd.size() == 0)
    {
      continue;
    }
    if (cmd == "Print")
    {
      db.Print();
      continue;
    }
    try
    {
      if (cmd == "Add")
      {
        cur >> inDate;
        cur >> event;
        db.AddEvent(inDate, event);
      }
      else if (cmd == "Find")
      {
        cur >> inDate;
        cur >> event;
        db.Find(inDate);
      }
      else if (cmd == "Del")
      {
        cur >> inDate;
        cur >> event;
        if (event.size() == 0)
        {
          db.DeleteDate(inDate);
        }
        else
        {
          db.DeleteEvent(inDate, event);
        }
      }
      else if (cmd.size() > 0)
      {
        cout << "Unknown command: " << cmd << endl;
      }
    }
    catch (runtime_error &ex)
    {
      cout << ex.what() << endl;
      continue;
    }
    /*
Add 0-+1-2 event1
Add 1-2-3 event2
Find 0-1-2

Del 0-1-2
Print
Del 1-2-3 event2
Del 1-2-3 event2

Your output:
event1
Deleted 1 events
0001-02-03 event2 
Deleted successfully
Event not found

Correct output:
event1
Deleted 1 events
0001-02-03 event2
Deleted successfully
Event not found
    */
    // РЎС‡РёС‚Р°Р№С‚Рµ РєРѕРјР°РЅРґС‹ СЃ РїРѕС‚РѕРєР° РІРІРѕРґР° Рё РѕР±СЂР°Р±РѕС‚Р°Р№С‚Рµ РєР°Р¶РґСѓСЋ
  }

  return 0;
}