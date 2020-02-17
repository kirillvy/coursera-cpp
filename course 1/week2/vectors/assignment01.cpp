#include <iostream>
#include <vector>
using namespace std;

int main() {
  int c;
  int d = 0;
  cin >> c;
  
  vector<int> v(c), result;

  for (int& val : v) {
    cin >> val;
  }
  for (int cur : v) {
    d += cur;
  }
  d /= c;
  
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] > d) {
      result.push_back(i);
    }
  }
  cout << result.size() << endl;
  for (auto i: result) {
    cout << i << ' ';
  }

  return 0;
}
