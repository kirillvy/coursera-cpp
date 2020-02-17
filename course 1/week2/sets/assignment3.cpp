#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

/*
Два слова называются синонимами друг друга, если они имеют похожие значения. 
Реализуйте следующие операции над словарём синонимов:

ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
COUNT word — узнать количество синонимов слова word.
CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами. 
Слова word1 и word2 считаются синонимами, если среди запросов ADD был хотя бы 
один запрос ADD word1 word2 или ADD word2 word1.

8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java
*/

int main() {
  int c;
  cin >> c;
  string command, word1, word2;
  set<string> words;
  map<string, set<string>> synonyms;
  auto none = synonyms.end();

  while(c--) {
    cin >> command;
    if (command == "COUNT") {
      cin >> word1;
      auto word = synonyms.find(word1);
      if (word != none) {
        cout << word->second.size();
      } else {
        cout << '0';
      }
      cout << endl;
    } else {
      cin >> word1 >> word2;
      if (command == "ADD") {
        synonyms[word1].insert(word2);
        synonyms[word2].insert(word1);
      } else if (command == "CHECK") {
        auto word = synonyms.find(word1);
        if (word != none && word->second.count(word2) == 1) {
          cout << "YES";
        } else {
          cout << "NO";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
