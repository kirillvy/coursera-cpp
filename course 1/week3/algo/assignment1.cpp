#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
  int a;
  cin >> a;
  vector<int> nums(a);

  for (auto& num : nums) {
    cin >> num;
  }

  sort(begin(nums), end(nums), [](int x, int y) {
    return abs(x) < abs(y);
  });
  for (const auto& num : nums) {
    cout << num << ' ';
  }

  return 0;
}
