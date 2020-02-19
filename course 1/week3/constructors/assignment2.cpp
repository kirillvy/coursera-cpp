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
  private:
    // приватные поля
    map<int, string> firstNames;
    map<int, string> lastNames;
    int birthYear;
    
  string GetLatestName(const int& year, const map<int, string>& names) const {
    string current;
    for (const auto& [recordYear, name] : names) {
      if (year < recordYear) {
        break;
      }
      if (!name.empty()) {
        current = name;
      }
    }
    return current;
  }

  vector<string> GetAllNames(const int& year, const map<int, string>& names) const {
    vector<string> current;
    string prevName;
    for (const auto& [recordYear, name] : names) {
      if (year < recordYear) {
        break;
      }
      if (name != prevName) {
        current.push_back(name);
        prevName = name;
      }
    }
    return current;
  }

  string CompileName(const vector<string>& names) const {
    int length = names.size();
    if (!length) {
      return "";
    }
    --length;
    string name = names[length];
    if (!length)
      return name;
    name += " (";
    while(length) {
      --length;
      name += names[length];
      if (length) {
        name += ", ";
      }
    }
    return name + ')';
  }

  string MakeName(string first, string last) const {
    return first + ' ' + last;
  }
  public:
    Person(const string& first, const string& last, const int& year){
      birthYear = year;
      ChangeFirstName(year, first);
      ChangeLastName(year, last);
    }
    void ChangeFirstName(const int& year, const string& first_name) {
      // добавить факт изменения имени на first_name в год year
      if (year >= birthYear) {
        firstNames[year] = first_name;
      }
    }
    void ChangeLastName(const int& year, const string& last_name) {
      // добавить факт изменения фамилии на last_name в год year
      if (year >= birthYear) {
        lastNames[year] = last_name;
      }
    }
    string GetFullName(const int& year) const {
      if (year < birthYear) {
        return "No person";
      }
      // получить имя и фамилию по состоянию на конец года year
      return MakeName(GetLatestName(year, firstNames), GetLatestName(year, lastNames));
    }
    string GetFullNameWithHistory(const int& year) const {
      if (year < birthYear) {
        return "No person";
      }
      // получить все имена и фамилии по состоянию на конец года year
      return MakeName(
        CompileName(GetAllNames(year, firstNames)),
        CompileName(GetAllNames(year, lastNames))
      );
    }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
