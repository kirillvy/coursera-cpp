#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string input) {
  int size = input.size();
  int middle = size / 2; 
  while (middle--) {
    if (input[middle] != input[size-middle-1]) {
      return false;
    }
  }
  return true;
}

int main() {
  string a;
  cin >> a;
  cout << IsPalindrom(a) << endl;
  return 0;
}
