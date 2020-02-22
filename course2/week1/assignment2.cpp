#include <iostream>
#include <vector>
using namespace std;

/*
В первой строке вводятся два целых положительных числа: количество блоков N и
плотность каждого блока R. Каждая из следующих N строк содержит три целых
положительных числа W, H, D — размеры очередного блока.
*/

int main() {
  int size, density, w, h, d;
  cin >> size >> density;
  uint64_t total = 0;

  while (size--) {
    cin >> w >> h >> d;
    total += density * w * h * d;
  }

  cout << total << endl;

  return 0;
}

/*
2 14
1 2 3
30 40 50
*/
