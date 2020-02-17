#include <iostream>
#include <string>
using namespace std;

int main() {
  string x;
  int a = -2;
  int b = 0;
  cin >> x;
  
  for (auto y : x) {
    if (y == 'f') {
      if (a == -2) {
        a = -1;
      } else {
        a = b;
        break;
      }
    }
    ++b;
  }

  cout << a;

  return 0;
}
