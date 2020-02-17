#include <iostream>
#include <map>
using namespace std;

map<char, int> MapWords(const string& word) {
  map<char, int> wordmap;
  for (char c : word) {
    ++wordmap[c];
  }
  return wordmap;
}

int main() {
  int c;
  cin >> c;
  map<char, int> wordmap1, wordmap2;

  while(c--) {
    string word1, word2;
    cin >> word1 >> word2;

    if (MapWords(word1) != MapWords(word2)) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;

  }

  return 0;
}
