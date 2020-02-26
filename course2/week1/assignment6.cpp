#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

/*
    для vector элементы нужно возвести в квадрат;
    для map в квадрат нужно возвести только значения, но не ключи;
    для pair в квадрат нужно возвести каждый элемент пары.
*/

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& x, const Key& k) {
  try {
    Value& result = x.at(k);
    return result;
  } catch (out_of_range) {
    throw runtime_error("not found");
  }
}

int main() {
  map<int, string> m = {{0, "value"}};
  string& item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl; // выведет newvalue
  return 0;
}
