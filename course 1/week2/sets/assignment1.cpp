#include <iostream>
#include <set>
using namespace std;

int main() {
  int c;
  cin >> c;
  string word;
  set <string> mySet;

  while(c--) {
    cin >> word;
    mySet.insert(word);
  }

  cout << mySet.size() << endl;

  return 0;
}
