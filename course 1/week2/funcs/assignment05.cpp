#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& dest) {
  for (auto a : source) {
    dest.push_back(a);
  }
  source.clear();
}

int main() {
  vector<string> source = {"a", "b", "c"};
  vector<string> destination = {"z"};
  MoveStrings(source, destination);
  for (auto a : source) {
    cout << a << " ";
  }
  cout << endl;
  for (auto a : destination) {
    cout << a << " ";
  }
  return 0;
}
