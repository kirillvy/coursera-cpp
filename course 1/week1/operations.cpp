#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = { 1, 5, 3, 6, 5, 7 };
  for (auto c : nums) {
    cout << c << ", ";
  }
  cout << endl;

  int quantity = count(begin(nums), end(nums), 5);
  cout << "there are " << quantity << " fives" << endl;
  sort(begin(nums), end(nums));

  for (auto z : nums) {
    cout << z << " ";
  }
  cout << endl;
  return 0;
}