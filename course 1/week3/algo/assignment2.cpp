#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
  int a;
  cin >> a;
  vector<string> chars(a);

  for (auto& num : chars) {
    cin >> num;
  }

  sort(begin(chars), end(chars), [](string x, string y) {
    for (char& c : x) {
      c = tolower(c);
    }
    for (char& c : y) {
      c = tolower(c);
    }
    return x < y;
  });
  for (const auto& el : chars) {
    cout << el << ' ';
  }

  return 0;
}
