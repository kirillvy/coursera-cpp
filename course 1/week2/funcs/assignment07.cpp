#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& numbers) {
  vector<int> result;
  int len = numbers.size();
  while (len--) {
    result.push_back(numbers[len]);
  }
  return result;
}

int main() {
  vector<int> numbers = {1, 5, 3, 4, 2};
  vector<int> newnums = Reversed(numbers);
  // numbers должен оказаться равен {2, 4, 3, 5, 1}  MoveStrings(source, destination);
  for (auto c : newnums) {
    cout << c << " ";
  }
  return 0;
}
