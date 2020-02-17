#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

/*
Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i,
где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый 
номер i и вывести его в формате New bus i.
5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Kokoshkino
*/

int main() {
  int c, stopCount;
  cin >> c;
  map<set<string>, int> stops;
  set<string> stopsList;
  string entry;

  while(c--) {
    cin >> stopCount;
    stopsList.clear();
    while (stopCount--) {
      cin >> entry;
      stopsList.insert(entry);
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
