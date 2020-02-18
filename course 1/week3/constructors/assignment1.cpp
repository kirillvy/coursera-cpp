#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ReversibleString {
  public:
    ReversibleString() {}
    ReversibleString(string init) {
      for (char& c : init) {
        current.push_back(c);
      }
    }
    void Reverse() {
      vector<char> newString;
      int len = current.size();
      while(len--) {
        newString.push_back(current[len]);
      }
      current = newString;
    }
    string ToString() const {
      string s(begin(current), end(current));
      return s;
    }
  private:
    vector<char> current;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
