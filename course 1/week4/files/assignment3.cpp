#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  ifstream input("input.txt");
  
  double line;
  if (!input) {
    return 0;
  }
  

  if (input.is_open()) {
    cout << fixed << setprecision(3);
    while(input >> line) {
      cout << line << endl;
    }
  }

  return 0;
}
