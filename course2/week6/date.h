#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


class Date
{
public:
  Date() {}
  Date(const int &new_year, const int &new_month, const int &new_day);
  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;

private:
  int year;
  int month;
  int day;
};

Date ParseDate(istream& in);

string PrintDate(const Date &d);
ostream &operator<<(ostream &ostr, const Date &d);

bool operator<(const Date &lhs, const Date &rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
