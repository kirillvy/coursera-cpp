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

// Предварительное объявление шаблонных функций
template<typename T> T Sqr(T x);
template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> x);
template <typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> x);
template <typename T> vector<T> Sqr(vector<T> x);
// Объявляем шаблонные функции
template <typename T>
T Sqr(T x) {
  return x * x;
}

template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> x) {
  x.first = Sqr(x.first);
  x.second = Sqr(x.second);
  return x;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> x) {
  for (auto& [k, value] : x) {
    value = Sqr(value);
  }
  return x;
}
template <typename T>
vector<T> Sqr(vector<T> x) {
  for (auto& c : x) {
    c = Sqr(c);
  }
  return x;
}
int main() {
  // Пример вызова функции
  vector<int> v = {2, 12, 36};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
  };
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }
    return 0;
}
