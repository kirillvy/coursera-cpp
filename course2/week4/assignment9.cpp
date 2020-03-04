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
  char sign;
  char prev_sign;
  do {
    getline(cin, op);
    if (op.size()) {
      sign = op.front();
      if (
        (sign == '*' || sign == '/') &&
        (prev_sign == '+' || prev_sign == '-')
      ) {
        res.push_front('(');
        res.push_back(')');
      }
      res.push_back(' ');
      for (const auto& c : op) {
        res.push_back(c);
      }
      prev_sign = sign;
    }
  } while (ops--);
  string output(res.begin(), res.end());
  cout << output << endl;
  
  return 0;
}
