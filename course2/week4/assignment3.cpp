#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream& out, const vector<int> nums) {
  for (auto num : nums) {
    out << num << ' ';
  }
  return out;
} 

int main() {
  int num = 0;

  cin >> num;
  bool perms =  true;
  vector<int> nums(num);

  iota(nums.rbegin, nums.rend, 1);

  while (perms) {
    cout << nums << endl;
    perms = prev_permutation(begin(nums), end(nums));
  }
  

  return 0;
}
