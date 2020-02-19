#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Name {
  string first;
  string last;
};

class Person {
  public:
    void ChangeFirstName(const int& year, const string& first_name) {
      // добавить факт изменения имени на first_name в год year
      history[year].first = first_name;
    }
    void ChangeLastName(const int& year, const string& last_name) {
      // добавить факт изменения фамилии на last_name в год year
      history[year].last = last_name;
    }
    string GetFullName(const int& year) {
      Name current = GetLatestName(year);
      string& first = current.first;
      string& last = current.last;
      // получить имя и фамилию по состоянию на конец года year
      if (!first.empty()) {
        if (!last.empty()) {
          return first + ' ' + last;
        }
        return first + " with unknown last name";
      } else if (!last.empty()) {
        return last + " with unknown first name";
      }
      return "Incognito";
    }
  private:
    // приватные поля
    map<int, Name> history;
    Name GetLatestName(const int& year) {
      Name current;
      for (auto& [recordYear, name] : history) {
        if (year < recordYear) {
          break;
        }
        if (!name.first.empty()) {
          current.first = name.first;
        }
        if (!name.last.empty()) {
          current.last = name.last;
        }
      }
      return current;
    }
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
