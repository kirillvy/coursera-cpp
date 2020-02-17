#include <iostream>
#include <vector>
using namespace std;

/**
 * WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
QUIET i: пометить i-го человека как успокоившегося;
COME k: добавить k спокойных человек в конец очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
0 = quiet
1 = worry
 * */

int main() {
  int c;
  cin >> c;

  string command;
  int number;
  vector<bool> line;

  for (int i = 0; i < c; ++i) {
    cin >> command;
    if (command == "WORRY_COUNT"){
      int total = 0;
      for (bool x : line) {
        if (x == true) {
          ++total;
        }
      }
      cout << total << endl;
      continue;
    }
    cin >> number;
    if (command == "COME"){
      line.resize(line.size() + number, false);
    } else if (command == "QUIET"){
      line[number] = false;
    } else {
      line[number] = true;
    }

  }

  return 0;
}
