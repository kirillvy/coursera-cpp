#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  int range_size = range_end - range_begin;
  int split = range_size / 3;
  if (range_size < 2) {
    return;
  }
  
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  vector<typename RandomIt::value_type> temp;

  auto middle1 = begin(elements) + split;  
  auto middle2 = begin(elements) + split * 2;

  MergeSort(begin(elements), middle1);
  MergeSort(middle1, middle2);
  MergeSort(middle2, end(elements));

  merge(begin(elements), middle1, middle1, middle2, back_inserter(temp));
  merge(begin(temp), end(temp), middle2, end(elements), range_begin);

}

int main() {
  vector<int> v = {8, 6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
