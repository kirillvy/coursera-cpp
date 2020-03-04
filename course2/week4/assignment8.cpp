#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
  string num;
  int ops;

  cin >> num >> ops;
  deque<char> res(begin(num), end(num));
  string op;
  do {
    getline(cin, op);
    if (op.size()) {
      res.push_front('(');
      res.push_back(')');
      res.push_back(' ');
      for (const auto& c : op) {
        res.push_back(c);
      }
    }
  } while (ops--);
  string output(res.begin(), res.end());
  cout << output << endl;
  
  return 0;
}
