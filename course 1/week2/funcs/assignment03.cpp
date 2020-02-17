#include <iostream>
#include <string>
#include <vector>
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

vector<string> PalindromFilter(vector<string> palindrome, int length) {
  vector<string> result;
  for (auto x: palindrome) {
    if (IsPalindrom(x) && x.length() >= length){
      result.push_back(x);
    }
  }
  return result;
}

int main() {
  string a;
  cin >> a;
  cout << IsPalindrom(a) << endl;
  return 0;
}
