#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& numbers) {
  vector<int> result;
  int len = numbers.size();
  while (len--) {
    result.push_back(numbers[len]);
  }
  numbers = result;
}

int main() {
  vector<int> numbers = {1, 5, 3, 4, 2};
  Reverse(numbers);
  // numbers должен оказаться равен {2, 4, 3, 5, 1}  MoveStrings(source, destination);
  for (auto c : numbers) {
    cout << c << " ";
  }
  return 0;
}
