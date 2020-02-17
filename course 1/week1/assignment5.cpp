#include <iostream>
using namespace std;

double discount(double s, double t) {
  return s * (1 - t / 100);
}

int main() {
  double n, a, b, x, y;
  cin >> n >> a >> b >> x >> y;

  if (n > b) {
    n = discount(n, y);
  } else if (n > a) {
    n = discount(n, x);
  }

  cout << n;

  return 0;
}
