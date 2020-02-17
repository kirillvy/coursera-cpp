#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * alpha beta gamma
 * beta gamma alpha
 * beta gamma alpha
 * 
 * alpha alpha beta
 * beta beta alpha
 * alpha beta alpha
 * 
 * alpha alpha alpha
*/

int main() {
  vector<string> input;
  string inputString;
  int limit = 3;

  while(limit--) {
    cin >> inputString;
    input.push_back(inputString);
  }

  int x = input.size() - 1;

  string result = input[x];
  while(x--) {
    if (input[x] < result) {
      result = input[x];
    }
  }
  
  cout << result;
  return 0;
}
