#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  ifstream input("input.txt");
  
  int line, col;
  string cur;
  
  input >> line;
  input >> col;
  input.ignore(1);
  while(line--) {
    for (int i = 1; i < col; ++i) {
      getline(input, cur, ',');
      cout << setw(10) << cur << ' ';
    }
    getline(input, cur);
    cout << setw(10) << cur << endl;
  }

  return 0;
}
