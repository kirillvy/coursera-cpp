#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Name {
  string first;
  string last;
};

string GetLatestName(const int& year, const map<int, string>& names) {
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

vector<string> GetAllNames(const int& year, const map<int, string>& names) {
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

string CompileName(const vector<string>& names) {
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

string MakeName(string first, string last) {
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

class Person {
  private:
    // приватные поля
    map<int, string> firstNames;
    map<int, string> lastNames;
  public:
    void ChangeFirstName(const int& year, const string& first_name) {
      // добавить факт изменения имени на first_name в год year
      firstNames[year] = first_name;
    }
    void ChangeLastName(const int& year, const string& last_name) {
      // добавить факт изменения фамилии на last_name в год year
      lastNames[year] = last_name;
    }
    string GetFullName(int year) {
      // получить имя и фамилию по состоянию на конец года year
      return MakeName(GetLatestName(year, firstNames), GetLatestName(year, lastNames));
    }
    string GetFullNameWithHistory(int year) {
      // получить все имена и фамилии по состоянию на конец года year
      return MakeName(
        CompileName(GetAllNames(year, firstNames)),
        CompileName(GetAllNames(year, lastNames))
      );
    }
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
