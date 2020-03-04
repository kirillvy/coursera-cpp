#include "date.h"

Date::Date(const int &new_year, const int &new_month, const int &new_day)
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

int Date::GetDay() const
{
  return day;
}

int Date::GetMonth() const
{
  return month;
}

int Date::GetYear() const
{
  return year;
}

Date ParseDate(istream &in)
{
  Date d;
  char divider = '-';
  int new_year, new_month;
  int new_day = -999999;
  char div1, div2;
  string input;
  getline(in, input, ' ');
  if (input.find_first_not_of("0123456789+-") != input.npos || input.size() == 0)
  {
    throw runtime_error("Wrong date format: " + input);
  }
  stringstream date(input);
  date >> new_year >> div1 >> new_month >> div2 >> new_day;
  if (div1 == divider && div2 == divider && new_day != -999999)
  {
    d = {new_year, new_month, new_day};
  }
  else
  {
    throw runtime_error("Wrong date format: " + input);
  }

  return d;
}


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

