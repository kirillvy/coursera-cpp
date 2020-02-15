#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s = "hello";
  string t = s;
  string& u = t;
  t += ", world";

  cout << "s = " << s << endl;
  cout << "t = " << t << endl;
  cout << "u = " << u << endl;

  int c = 5;
  int a = ++c;
  int b = c++;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  string f = "abc";

  if (!s.empty() && s < "zzz") {
    cout << s;
  }

  return 0;
}