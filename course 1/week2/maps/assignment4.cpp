#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i,
где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый 
номер i и вывести его в формате New bus i.
*/

int main() {
  int c, stopCount;
  cin >> c;
  map<vector<string>, int> stops;
  vector<string> stopsList;

  while(c--) {
    cin >> stopCount;
    stopsList.resize(stopCount);
    for (string& stop : stopsList) {
      cin >> stop;
    }
    auto stop = stops.find(stopsList);
    if (stop == stops.end()) {
      int line = stops.size() + 1;
      stops[stopsList] = line;
      cout << "New bus " << line << endl;
    } else {
      cout << "Already exists for " << stop->second << endl;
    }
  }

  return 0;
}
