#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class SortedStrings {
  public:
    void AddString(const string& s) {
      // добавить строку s в набор
      ++strings[s];
    }
    vector<string> GetSortedStrings() {
      // получить набор из всех добавленных строк в отсортированном порядке
      vector<string> result;
      for (auto& [first, second] : strings) {
        for (int i = 0; i < second; ++i) {
          result.push_back(first);
        }
      }
      return result;
    }
  private:
    // приватные поля
    map<string, int> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}