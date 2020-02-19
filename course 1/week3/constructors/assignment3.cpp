#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Incognizable {
  int x;
  int y;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}