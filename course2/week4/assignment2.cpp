#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <ios>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
  istringstream ss(s);

  vector<string> res;
  string temp;
  while (ss) {
    getline(ss, temp, ' ');
    res.push_back(temp);
  }
  res.pop_back();

  return res;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
