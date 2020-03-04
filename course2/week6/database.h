#include "date.h"

#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

class Database {
public:
  void Add(const Date& date, const string& event);
  void Print(ostream& out);
  string Last(const Date& date);
  template<class Condition>
  vector<string> FindIf(Condition predicate);
  template<class Condition>
  int RemoveIf(Condition predicate);

private:
  bool DeleteEvent(const Date &date, const string &event);
  int DeleteDate(const Date &date);
  void FindDate(const Date &date) const;
  map<Date, set<string>> events;
};
