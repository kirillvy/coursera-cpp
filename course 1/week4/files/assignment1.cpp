#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream input("input.txt");
  string line;
  if (input.is_open()) {
    while(getline(input, line)) {
      cout << line << endl;
    }
  }

  return 0;
}
