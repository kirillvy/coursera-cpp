#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

struct Name {
  string first;
  string last;
};

class Person {
  public:
    void ChangeFirstName(const int& year, const string& first_name) {
      // добавить факт изменения имени на first_name в год year
      history[year].first = first_name;
    }
    void ChangeLastName(const int& year, const string& last_name) {
      // добавить факт изменения фамилии на last_name в год year
      history[year].last = last_name;
    }
    string GetFullName(const int& year) {
      Name current = GetLatestName(year);
      string& first = current.first;
      string& last = current.last;
      // получить имя и фамилию по состоянию на конец года year
      if (!first.empty()) {
        if (!last.empty()) {
          return first + ' ' + last;
        }
        return first + " with unknown last name";
      } else if (!last.empty()) {
        return last + " with unknown first name";
      }
      return "Incognito";
    }
  private:
    // приватные поля
    map<int, Name> history;
    Name GetLatestName(const int& year) {
      Name current;
      for (auto& [recordYear, name] : history) {
        if (year < recordYear) {
          break;
        }
        if (!name.first.empty()) {
          current.first = name.first;
        }
        if (!name.last.empty()) {
          current.last = name.last;
        }
      }
      return current;
    }
};

void TestFirstNameSet() {
  Person n;
  n.ChangeFirstName(1, "Kirill");
  n.ChangeLastName(2, "V");
  AssertEqual(n.GetFullName(-1), "Incognito", "negative 1 year");
  AssertEqual(n.GetFullName(0), "Incognito", "0 year");
  AssertEqual(n.GetFullName(1), "Kirill with unknown last name", "1 year");
  AssertEqual(n.GetFullName(2), "Kirill V", "2 year");
}


void TestLastNameSet() {
  Person n;
  n.ChangeFirstName(1, "Kirill");
  n.ChangeLastName(-1, "V");
  AssertEqual(n.GetFullName(-2), "Incognito", "negative 2 year");
  AssertEqual(n.GetFullName(-1), "V with unknown first name", "negative 1 year");
  AssertEqual(n.GetFullName(1), "Kirill V", "1 year");
  AssertEqual(n.GetFullName(2), "Kirill V", "2 year");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestFirstNameSet, "TestFirstNameSet");
  runner.RunTest(TestLastNameSet, "TestLastNameSet");
  // добавьте сюда свои тесты
  return 0;
}
