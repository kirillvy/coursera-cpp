#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  if (x % 2 == 1) {
    ++x;
  }
  if (y % x == 1) {
    --y;
  }

  for (int i = x; i <= y; ++i) {
    if (i % 2 == 0) {
      cout << i;
    } else {
      cout << ' ';
    }
  }

  return 0;
}
