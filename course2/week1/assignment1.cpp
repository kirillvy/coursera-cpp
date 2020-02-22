#include <iostream>
#include <vector>
using namespace std;

int main() {
  int size;
  int64_t total = 0;
  cin >> size;
  vector<int> temps(size);
  vector<int> higherTemps;

  for (auto& n : temps) {
    cin >> n;
    total += n;
  }

  int avg = total / size; 

  for (int i = 0; i < size; ++i) {
    if (temps[i] > avg) {
      higherTemps.push_back(i);
    }
  }
  cout << higherTemps.size() << endl;
  for (const auto& c : higherTemps) {
    cout << c << ' ';
  }
  cout << endl;
  return 0;
}

/*
5
5 4 1 -2 7
*/
