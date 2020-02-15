#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  
  if (a == 0) {
    cout << c / -b;
    return 0;
  }

  double x = (-b - sqrt(pow(b, 2.0) - 4.0 * a * c) ) / (2.0 * a);
  double y = (-b + sqrt(pow(b, 2.0) - 4.0 * a * c) ) / (2.0 * a);


  if (!isfinite(x) && !isfinite(y)) {
    return 0;
  }
  if (!isfinite(x)) {
    cout << y;
  } else if (!isfinite(y)) {
    cout << x;
  } else if (x == y) {
    cout << x;
  } else {
    cout << x << " " << y;
  }

  return 0;
}