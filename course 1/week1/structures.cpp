#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Person {
  string name;
  string surname;
  int age;
};

int main() {
  int x = -5;
  double pi = 3.14;
  bool logic = true;
  char symbol = 'f';


  string hw = "hello world!";
  cout << hw << endl;

  vector<int> nums = {1, 3, 4, 5};
  cout << nums.size() << endl;

  map<string, int> values;

  values["one"] = 1;
  values["two"] = 2;

  cout << "two is " << values["two"] << endl;

  vector<Person> people;

  people.push_back({ "Ivan", "Ivanov", 31 });
  people.push_back({ "Petr", "PEtrov", 25 });

  cout << people[1].name << " is " << people[1].age << endl;



  return 0;
}