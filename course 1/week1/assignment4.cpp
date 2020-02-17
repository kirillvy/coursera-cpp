#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  if (y == 0) {
    cout << "Impossible" << endl;
  } else {
    cout << x / y << endl;
  }

  return 0;
}
