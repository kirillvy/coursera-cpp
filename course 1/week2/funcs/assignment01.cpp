#include <iostream>
using namespace std;

int Factorial(int num) {
  if (num < 2) {
    return 1;
  }
  int result = num;
  while (--num) {
    result *= num;
  }
  return result;
}

int main() {
  int a;
  cin >> a;
  cout << Factorial(a) << endl;
  return 0;
}
