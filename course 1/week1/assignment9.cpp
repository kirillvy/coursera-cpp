#include <iostream>
#include <vector>
using namespace std;

int main() {
  int64_t a;
  char b;
  int c = 0;
  string x = "";

  cin >> a;

  while (a > 0) {
    b = '0';
    if (a % 2 == 1) {
      b = '1';
    }
    x = b + x;
    a /= 2;
  }

  cout << x << endl;

  return 0;
}
