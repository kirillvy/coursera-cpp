#include <iostream>
#include <map>
#include <string>
using namespace std;

/**
 * CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление
 * такой страны с такой столицей, если раньше её не было.
 * RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
 * ABOUT country — вывод столицы страны country.
 * DUMP — вывод столиц всех стран.
 * 6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP
 */ 

void ChangeCapital(map<string, string>& countries) {
  string country, new_capital;
  cin >> country >> new_capital;
  auto none = countries.end();
  if (countries.find(country) == none) {
    cout << "Introduce new country " << country << " with capital " << new_capital << endl;
  } else if (countries[country] == new_capital) {
    cout << "Country " << country << " hasn't changed its capital" << endl;
  } else {
    cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital << endl;
  }
  countries[country] = new_capital;
}

void Rename(map<string, string>& countries){
  string old_country_name, new_country_name;
  cin >> old_country_name >> new_country_name;
  auto none = countries.end();
  if (
    old_country_name == new_country_name
    || countries.find(old_country_name) == none
    || countries.find(new_country_name) != none
  ) {
    cout << "Incorrect rename, skip" << endl;
  } else {
    cout << "Country " << old_country_name << " with capital " << countries[old_country_name];
    cout << " has been renamed to " << new_country_name << endl;
    countries[new_country_name] = countries[old_country_name];
    countries.erase(old_country_name);
  }
}
void About(map<string, string>& countries) {
  auto none = countries.end();
  string country;
  cin >> country;
  if (countries.find(country) == none) {
    cout << "Country " << country << " doesn't exist" << endl;
  } else {
    cout << "Country " << country << " has capital " << countries[country] << endl;
  }
}
void Dump(map<string, string>& countries) {
  if (countries.size() == 0) {
    cout << "There are no countries in the world" << endl;
    return;
  }
  for (auto& [key, value] : countries) {
    cout << key << "/" << value << ' ';
  }
  cout << endl;
}

int main() {
  string command;
  int c;
  cin >> c;
  map<string, string> countries;

  while(c--) {
    cin >> command;
    if (command == "CHANGE_CAPITAL") {
      ChangeCapital(countries);
    } else if (command == "RENAME") {
      Rename(countries);
    } else if (command == "ABOUT") {
      About(countries);
    } else if (command == "DUMP") {
      Dump(countries);
    }

  }

  return 0;
}
